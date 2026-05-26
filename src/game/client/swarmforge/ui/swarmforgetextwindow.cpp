#include "cbase.h"
#include "swarmforgetextwindow.h"

CSwarmForgeTextWindow::CSwarmForgeTextWindow( vgui::Panel *parent ) : CTextWindow( parent, "TextWindow" )
{
}

CSwarmForgeTextWindow::~CSwarmForgeTextWindow()
{
}

void CSwarmForgeTextWindow::Init()
{
	BaseClass::Init();
}

void CSwarmForgeTextWindow::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}
