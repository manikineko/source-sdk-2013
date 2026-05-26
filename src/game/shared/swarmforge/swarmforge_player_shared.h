#ifndef SWARMFORGE_PLAYER_SHARED_H
#define SWARMFORGE_PLAYER_SHARED_H
#ifdef _WIN32
#pragma once
#endif

#include "hl2mp_player_shared.h"

#ifdef CLIENT_DLL
	#define CSwarmForgePlayer C_SwarmForgePlayer
#endif

class CSwarmForgePlayer : public CHL2MPPlayer
{
public:
	DECLARE_CLASS( CSwarmForgePlayer, CHL2MPPlayer );
	DECLARE_NETWORKCLASS();

public:
	virtual void Spawn( void );
};

#endif // SWARMFORGE_PLAYER_SHARED_H
