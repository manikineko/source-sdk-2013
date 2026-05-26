#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "c_baseplayer.h"
#include "iclientmode.h"

DECLARE_HUDELEMENT( CHudSwarmForgeTeam );

CHudSwarmForgeTeam::CHudSwarmForgeTeam( const char *pElementName ) : CHudElement( pElementName ), vgui::Panel( NULL, "HudSwarmForgeTeam" )
{
	SetParent( g_pClientMode->GetViewport() );
}

void CHudSwarmForgeTeam::Init( void )
{
}

void CHudSwarmForgeTeam::VidInit( void )
{
}

void CHudSwarmForgeTeam::Paint( void )
{
}

void CHudSwarmForgeTeam::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}
