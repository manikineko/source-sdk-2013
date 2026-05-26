#ifndef SWARMFORGE_HUD_TARGET_ID_H
#define SWARMFORGE_HUD_TARGET_ID_H
#ifdef _WIN32
#pragma once
#endif

#include "hudelement.h"
#include <vgui_controls/Panel.h>

class CHudSwarmForgeTargetID : public CHudElement, public vgui::Panel
{
	DECLARE_CLASS_SIMPLE( CHudSwarmForgeTargetID, vgui::Panel );

public:
	CHudSwarmForgeTargetID( const char *pElementName );
	void Init( void );
	void VidInit( void );
	void Paint( void );
	void ApplySchemeSettings( vgui::IScheme *scheme );
};

#endif // SWARMFORGE_HUD_TARGET_ID_H
