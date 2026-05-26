#ifndef SWARMFORGE_HUD_DEATHNOTICE_H
#define SWARMFORGE_HUD_DEATHNOTICE_H
#ifdef _WIN32
#pragma once
#endif

#include "hudelement.h"
#include <vgui_controls/Panel.h>

class CHudSwarmForgeDeathNotice : public CHudElement, public vgui::Panel
{
	DECLARE_CLASS_SIMPLE( CHudSwarmForgeDeathNotice, vgui::Panel );

public:
	CHudSwarmForgeDeathNotice( const char *pElementName );
	void Init( void );
	void VidInit( void );
	void Paint( void );
	void ApplySchemeSettings( vgui::IScheme *scheme );
};

#endif // SWARMFORGE_HUD_DEATHNOTICE_H
