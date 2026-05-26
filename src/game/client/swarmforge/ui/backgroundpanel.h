#ifndef SWARMFORGE_BACKGROUNDPANEL_H
#define SWARMFORGE_BACKGROUNDPANEL_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Panel.h>

class CSwarmForgeBackgroundPanel : public vgui::Panel
{
	DECLARE_CLASS_SIMPLE( CSwarmForgeBackgroundPanel, vgui::Panel );

public:
	CSwarmForgeBackgroundPanel( vgui::Panel *parent, const char *panelName );
	virtual ~CSwarmForgeBackgroundPanel();

	virtual void PaintBackground();
	virtual void ApplySchemeSettings( vgui::IScheme *scheme );

private:
};

#endif // SWARMFORGE_BACKGROUNDPANEL_H
