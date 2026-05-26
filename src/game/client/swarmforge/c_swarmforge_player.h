#ifndef C_SWARMFORGE_PLAYER_H
#define C_SWARMFORGE_PLAYER_H
#ifdef _WIN32
#pragma once
#endif

#include "c_hl2mp_player.h"

class C_SwarmForgePlayer : public C_HL2MP_Player
{
public:
	DECLARE_CLASS( C_SwarmForgePlayer, C_HL2MP_Player );
	DECLARE_CLIENTCLASS();

public:
	C_SwarmForgePlayer();
	virtual ~C_SwarmForgePlayer();

	virtual void PostDataUpdate( DataUpdateType_t updateType );
};

#endif // C_SWARMFORGE_PLAYER_H
