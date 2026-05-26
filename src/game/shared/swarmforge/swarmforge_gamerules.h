#ifndef SWARMFORGE_GAMERULES_H
#define SWARMFORGE_GAMERULES_H
#ifdef _WIN32
#pragma once
#endif

#include "hl2mp_gamerules.h"

#ifdef CLIENT_DLL
	#define CSwarmForgeGameRules C_SwarmForgeGameRules
	#include "c_swarmforge_player.h"
#else
	#include "swarmforge_player.h"
#endif

class CSwarmForgeGameRules : public CHL2MPGameRules
{
public:
	DECLARE_CLASS( CSwarmForgeGameRules, CHL2MPGameRules );

	virtual bool IsTeamplay( void ) { return true; }
	virtual const char *GetGameDescription( void ) { return "SwarmForge"; }
	
#ifdef CLIENT_DLL
#else
	virtual void GoToIntermission( void );
	virtual const char *GetChatFormat( bool bTeamOnly, CBasePlayer *pPlayer );
#endif
};

extern CSwarmForgeGameRules *g_pSwarmForgeGameRules;

#endif // SWARMFORGE_GAMERULES_H
