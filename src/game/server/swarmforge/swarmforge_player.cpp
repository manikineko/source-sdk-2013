#include "cbase.h"
#include "swarmforge_player.h"
#include "weapon_hl2mpbase.h"
#include "gamerules.h"
#include "team.h"

LINK_ENTITY_TO_CLASS( player_swarmforge, CSwarmForgePlayer );
PRECACHE_REGISTER(player_swarmforge);

IMPLEMENT_SERVERCLASS_ST( CSwarmForgePlayer, DT_SwarmForgePlayer )
END_SEND_TABLE()

CSwarmForgePlayer::CSwarmForgePlayer()
{
}

CSwarmForgePlayer::~CSwarmForgePlayer()
{
}

void CSwarmForgePlayer::Spawn( void )
{
	BaseClass::Spawn();

	// Set default team
	if ( GetTeamNumber() == TEAM_UNASSIGNED )
	{
		ChangeTeam( TEAM_SPECTATOR );
	}
}

void CSwarmForgePlayer::Precache( void )
{
	BaseClass::Precache();
}

void CSwarmForgePlayer::CreateViewModel( void )
{
	BaseClass::CreateViewModel();
}

void CSwarmForgePlayer::GiveDefaultItems( void )
{
	BaseClass::GiveDefaultItems();
}

void CSwarmForgePlayer::PlayerDeathThink( void )
{
	BaseClass::PlayerDeathThink();
}

void CSwarmForgePlayer::Event_Killed( const CTakeDamageInfo &info )
{
	BaseClass::Event_Killed( info );
}

void CSwarmForgePlayer::PostDeath( void )
{
	BaseClass::PostDeath();
}
