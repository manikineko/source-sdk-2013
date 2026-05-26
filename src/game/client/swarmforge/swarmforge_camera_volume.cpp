#include "cbase.h"
#include "swarmforge_camera_volume.h"
#include "mapentities_shared.h"
#include "datacache/imdlcache.h"
#include "gamestringpool.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

CUtlVector<C_SwarmForge_CameraVolume*> g_SwarmForgeCameraVolumes;

IMPLEMENT_CLIENTCLASS_DT( C_SwarmForge_CameraVolume, DT_SwarmForge_CameraVolume, CSwarmForge_CameraVolume )
END_RECV_TABLE()

C_SwarmForge_CameraVolume::C_SwarmForge_CameraVolume()
{
	g_SwarmForgeCameraVolumes.AddToTail( this );
	m_flCameraPitch = 90.0f; // Default to top-down
}

C_SwarmForge_CameraVolume::~C_SwarmForge_CameraVolume()
{
	g_SwarmForgeCameraVolumes.FindAndRemove( this );
}

void C_SwarmForge_CameraVolume::Spawn()
{
	SetSolid( SOLID_BBOX );
	SetModel( STRING( GetModelName() ) ); // set size and link into world

	BaseClass::Spawn();

	m_takedamage = DAMAGE_NO;
}

bool C_SwarmForge_CameraVolume::Initialize()
{
	if ( InitializeAsClientEntity( NULL, false ) == false )
	{
		return false;
	}

	Spawn();

	const model_t *mod = GetModel();
	if ( mod )
	{
		Vector mins, maxs;
		modelinfo->GetModelBounds( mod, mins, maxs );
		SetCollisionBounds( mins, maxs );
	}

	SetBlocksLOS( false ); // this should be a small object
	SetNextClientThink( CLIENT_THINK_NEVER );

	return true;
}

float C_SwarmForge_CameraVolume::IsPointInCameraVolume( const Vector &vecPoint )
{
	int c = g_SwarmForgeCameraVolumes.Count();
	for ( int i = 0; i < c; i++ )
	{
		if ( g_SwarmForgeCameraVolumes[i]->CollisionProp()->IsPointInBounds( vecPoint ) )
			return g_SwarmForgeCameraVolumes[i]->m_flCameraPitch;
	}
	return -1.0f;
}

void C_SwarmForge_CameraVolume::RecreateAll()
{
	DestroyAll();
	ParseAllEntities( engine->GetMapEntitiesString() );
}

void C_SwarmForge_CameraVolume::DestroyAll()
{
	while ( g_SwarmForgeCameraVolumes.Count() > 0 )
	{
		C_SwarmForge_CameraVolume *p = g_SwarmForgeCameraVolumes[0];
		p->Release();
	}
}

const char *C_SwarmForge_CameraVolume::ParseEntity( const char *pEntData )
{
	CEntityMapData entData( (char*)pEntData );
	char className[MAPKEY_MAXLENGTH];

	MDLCACHE_CRITICAL_SECTION();

	if ( !entData.ExtractValue( "classname", className ) )
	{
		Error( "classname missing from entity!\n" );
	}

	if ( !Q_strcmp( className, "swarmforge_camera_control" ) )
	{
		// always force clientside entities placed in maps
		C_SwarmForge_CameraVolume *pEntity = new C_SwarmForge_CameraVolume();

		if ( pEntity )
		{
			// Set up keyvalues.
			pEntity->ParseMapData( &entData );

			if ( !pEntity->Initialize() )
				pEntity->Release();

			return entData.CurrentBufferPosition();
		}
	}

	// Just skip past all the keys.
	char keyName[MAPKEY_MAXLENGTH];
	char value[MAPKEY_MAXLENGTH];
	if ( entData.GetFirstKey( keyName, value ) )
	{
		do
		{
		}
		while ( entData.GetNextKey( keyName, value ) );
	}

	// Return the current parser position in the data block
	return entData.CurrentBufferPosition();
}

bool C_SwarmForge_CameraVolume::KeyValue( const char *szKeyName, const char *szValue )
{
	if ( FStrEq( szKeyName, "model" ) )
	{
		SetModelName( AllocPooledString( szValue ) );
		return true;
	}
	if ( FStrEq( szKeyName, "angtype" ) )
	{
		int iAngleType = atoi( szValue );
		if ( iAngleType == 0 ) // 0 is top down
		{
			m_flCameraPitch = 90.0f;
		}
		else // 1 is 40 degree
		{
			m_flCameraPitch = 40.0f;
		}
		return true;
	}
	if ( FStrEq( szKeyName, "camerapitch" ) )
	{
		m_flCameraPitch = atof( szValue );
		return true;
	}
	return BaseClass::KeyValue( szKeyName, szValue );
}

//-----------------------------------------------------------------------------
// Purpose: Only called on BSP load. Parses and spawns all the entities in the BSP.
//-----------------------------------------------------------------------------
void C_SwarmForge_CameraVolume::ParseAllEntities( const char *pMapData )
{
	int nEntities = 0;

	char szTokenBuffer[MAPKEY_MAXLENGTH];

	// Loop through all entities in the map data, creating each.
	for ( ; true; pMapData = MapEntity_SkipToNextEntity( pMapData, szTokenBuffer ) )
	{
		// Parse the opening brace.
		char token[MAPKEY_MAXLENGTH];
		pMapData = MapEntity_ParseToken( pMapData, token );

		// Check to see if we've finished or not.
		if ( !pMapData )
			break;

		if ( token[0] != '{' )
		{
			Error( "C_SwarmForge_CameraVolume::ParseAllEntities: found %s when expecting {", token );
			continue;
		}

		// Parse the entity and add it to the spawn list.
		pMapData = ParseEntity( pMapData );

		nEntities++;
	}
}

bool C_SwarmForge_CameraVolume::ShouldDraw()
{
	return false;
}
