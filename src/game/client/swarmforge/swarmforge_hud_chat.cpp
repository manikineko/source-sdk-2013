#include "cbase.h"
#include "swarmforge_hud_chat.h"
#include "hud_macros.h"
#include "c_playerresource.h"
#include "vguicenterprint.h"

DECLARE_HUDELEMENT( CHudSwarmForgeChat );

CHudSwarmForgeChat::CHudSwarmForgeChat( const char *pElementName ) : CHudBaseChat( pElementName )
{
}

void CHudSwarmForgeChat::Init( void )
{
	BaseClass::Init();
}

void CHudSwarmForgeChat::MsgFunc_SayText( bf_read &msg )
{
	BaseClass::MsgFunc_SayText( msg );
}
