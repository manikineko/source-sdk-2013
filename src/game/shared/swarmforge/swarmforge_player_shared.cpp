#include "cbase.h"
#include "swarmforge_player_shared.h"

#ifdef CLIENT_DLL
	#include "c_swarmforge_player.h"
#else
	#include "swarmforge_player.h"
#endif

IMPLEMENT_NETWORKCLASS_ALIASED( SwarmForgePlayer, DT_SwarmForgePlayer )

BEGIN_NETWORK_TABLE( CSwarmForgePlayer, DT_SwarmForgePlayer )
END_NETWORK_TABLE()

#ifdef CLIENT_DLL
BEGIN_PREDICTION_DATA( CSwarmForgePlayer )
END_PREDICTION_DATA()
#endif

LINK_ENTITY_TO_CLASS( player_swarmforge, CSwarmForgePlayer );
PRECACHE_REGISTER(player_swarmforge);

void CSwarmForgePlayer::Spawn( void )
{
	BaseClass::Spawn();
}
