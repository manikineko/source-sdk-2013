#ifndef SWARMFORGE_HUD_TEAM_H
#define SWARMFORGE_HUD_TEAM_H
#ifdef _WIN32
#pragma once
#endif

#include "hudelement.h"
#include <vgui_controls/Panel.h>

class CHudSwarmForgeTeam : public CHudElement, public vgui::Panel
{
	DECLARE_CLASS_SIMPLE( CHudSwarmForgeTeam, vgui::Panel );

public:
	CHudSwarmForgeTeam( const char *pElementName );
	void Init( void );
	void VidInit( void );
	void Paint( void );
	void ApplySchemeSettings( vgui::IScheme *scheme );
};

#endif // SWARMFORGE_HUD_TEAM_H
