#include "cbase.h"
#include "backgroundpanel.h"

CSwarmForgeBackgroundPanel::CSwarmForgeBackgroundPanel( vgui::Panel *parent, const char *panelName ) : vgui::Panel( parent, panelName )
{
}

CSwarmForgeBackgroundPanel::~CSwarmForgeBackgroundPanel()
{
}

void CSwarmForgeBackgroundPanel::PaintBackground()
{
	BaseClass::PaintBackground();
}

void CSwarmForgeBackgroundPanel::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}
