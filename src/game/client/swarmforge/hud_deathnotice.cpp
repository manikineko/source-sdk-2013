#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "c_baseplayer.h"
#include "iclientmode.h"

DECLARE_HUDELEMENT( CHudSwarmForgeDeathNotice );

CHudSwarmForgeDeathNotice::CHudSwarmForgeDeathNotice( const char *pElementName ) : CHudElement( pElementName ), vgui::Panel( NULL, "HudSwarmForgeDeathNotice" )
{
	SetParent( g_pClientMode->GetViewport() );
}

void CHudSwarmForgeDeathNotice::Init( void )
{
}

void CHudSwarmForgeDeathNotice::VidInit( void )
{
}

void CHudSwarmForgeDeathNotice::Paint( void )
{
}

void CHudSwarmForgeDeathNotice::ApplySchemeSettings( vgui::IScheme *scheme )
{
	BaseClass::ApplySchemeSettings( scheme );
}
