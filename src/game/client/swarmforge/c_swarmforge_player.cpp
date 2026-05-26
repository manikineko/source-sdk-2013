#include "cbase.h"
#include "c_swarmforge_player.h"

IMPLEMENT_CLIENTCLASS_DT( C_SwarmForgePlayer, DT_SwarmForgePlayer, CSwarmForgePlayer )
END_RECV_TABLE()

C_SwarmForgePlayer::C_SwarmForgePlayer()
{
}

C_SwarmForgePlayer::~C_SwarmForgePlayer()
{
}

void C_SwarmForgePlayer::PostDataUpdate( DataUpdateType_t updateType )
{
	BaseClass::PostDataUpdate( updateType );
}
