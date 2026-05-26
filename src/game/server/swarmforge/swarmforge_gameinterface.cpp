#include "cbase.h"
#include "swarmforge_gameinterface.h"
#include "swarmforge_gamerules.h"

bool CSwarmForgeGameInterface::Init()
{
	if ( !BaseClass::Init() )
		return false;

	return true;
}

void CSwarmForgeGameInterface::PostInit()
{
	BaseClass::PostInit();
}

void CSwarmForgeGameInterface::LevelInit( const char *pMapName, const char *pMapEntities, const char *pOldLevel, const char *pLandmarkName, bool loadGame, bool background )
{
	BaseClass::LevelInit( pMapName, pMapEntities, pOldLevel, pLandmarkName, loadGame, background );
}

void CSwarmForgeGameInterface::LevelShutdown( void )
{
	BaseClass::LevelShutdown();
}
