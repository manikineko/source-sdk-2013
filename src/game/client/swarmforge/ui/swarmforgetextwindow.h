#ifndef SWARMFORGE_TEXTWINDOW_H
#define SWARMFORGE_TEXTWINDOW_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Panel.h>
#include "textwindow.h"

class CSwarmForgeTextWindow : public CTextWindow
{
	DECLARE_CLASS_SIMPLE( CSwarmForgeTextWindow, CTextWindow );

public:
	CSwarmForgeTextWindow( vgui::Panel *parent );
	virtual ~CSwarmForgeTextWindow();

	virtual void Init();
	virtual void ApplySchemeSettings( vgui::IScheme *scheme );

private:
};

#endif // SWARMFORGE_TEXTWINDOW_H
