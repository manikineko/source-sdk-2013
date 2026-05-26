#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "c_baseplayer.h"
#include "iclientmode.h"

DECLARE_HUDELEMENT( CHudSwarmForgeTargetID );

CHudSwarmForgeTargetID::CHudSwarmForgeTargetID( const char *pElementName ) : CHudElement( pElementName ), vgui::Panel( NULL, "HudSwarmForgeTargetID" )
{
	SetParent( g_pClientMode->GetViewport() );
}

void CHudSwarmForgeTargetID::Init( void )
{
}

void CHudSwarmForgeTargetID::VidInit( void )
{
}

void CHudSwarmForgeTargetID::Paint( void )
{
}

void CHudSwarmForgeTargetID::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}
