#include "cbase.h"
#include "swarmforge_gamerules.h"

#ifdef CLIENT_DLL
#else
	#include "team.h"
#endif

LINK_ENTITY_TO_CLASS( swarmforge_gamerules, CSwarmForgeGameRules );
CSwarmForgeGameRules *g_pSwarmForgeGameRules = NULL;

#ifdef CLIENT_DLL

#else

void CSwarmForgeGameRules::GoToIntermission( void )
{
	BaseClass::GoToIntermission();
}

const char *CSwarmForgeGameRules::GetChatFormat( bool bTeamOnly, CBasePlayer *pPlayer )
{
	if ( !pPlayer )
	{
		return NULL;
	}

	const char *pszFormat = NULL;
	if ( bTeamOnly )
	{
		if ( pPlayer->GetTeamNumber() == TEAM_SPECTATOR )
		{
			pszFormat = "#Cstrike_Chat_Spec";
		}
		else
		{
			pszFormat = "#Cstrike_Chat_Team";
		}
	}
	else
	{
		pszFormat = "#Cstrike_Chat_All";
	}

	return pszFormat;
}

#endif
