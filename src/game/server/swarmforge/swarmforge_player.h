#ifndef SWARMFORGE_PLAYER_H
#define SWARMFORGE_PLAYER_H
#ifdef _WIN32
#pragma once
#endif

#include "hl2_player.h"

class CSwarmForgePlayer : public CHL2Player
{
public:
	DECLARE_CLASS( CSwarmForgePlayer, CHL2Player );
	DECLARE_SERVERCLASS();

public:
	CSwarmForgePlayer();
	virtual ~CSwarmForgePlayer();

	virtual void Spawn( void );
	virtual void Precache( void );
	virtual void CreateViewModel( void );
	virtual void GiveDefaultItems( void );
	virtual void PlayerDeathThink( void );

	virtual void Event_Killed( const CTakeDamageInfo &info );
	virtual void PostDeath( void );

private:
};

#endif // SWARMFORGE_PLAYER_H
