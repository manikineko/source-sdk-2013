#ifndef SWARMFORGE_CLIENTSCOREBOARD_H
#define SWARMFORGE_CLIENTSCOREBOARD_H
#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Panel.h>
#include "clientscoreboard.h"

class CSwarmForgeClientScoreBoard : public CClientScoreBoard
{
	DECLARE_CLASS_SIMPLE( CSwarmForgeClientScoreBoard, CClientScoreBoard );

public:
	CSwarmForgeClientScoreBoard( vgui::Panel *parent );
	virtual ~CSwarmForgeClientScoreBoard();

	virtual void Init();
	virtual void ApplySchemeSettings( vgui::IScheme *scheme );
	virtual void Update();

private:
};

#endif // SWARMFORGE_CLIENTSCOREBOARD_H
