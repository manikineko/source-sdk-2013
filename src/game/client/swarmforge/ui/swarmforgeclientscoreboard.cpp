#include "cbase.h"
#include "swarmforgeclientscoreboard.h"

CSwarmForgeClientScoreBoard::CSwarmForgeClientScoreBoard( vgui::Panel *parent ) : CClientScoreBoard( parent, "ScoreBoard" )
{
}

CSwarmForgeClientScoreBoard::~CSwarmForgeClientScoreBoard()
{
}

void CSwarmForgeClientScoreBoard::Init()
{
	BaseClass::Init();
}

void CSwarmForgeClientScoreBoard::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}

void CSwarmForgeClientScoreBoard::Update()
{
	BaseClass::Update();
}
