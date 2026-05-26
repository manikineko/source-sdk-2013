#ifndef SWARMFORGE_HUD_CHAT_H
#define SWARMFORGE_HUD_CHAT_H
#ifdef _WIN32
#pragma once
#endif

#include "hud_basechat.h"

class CHudSwarmForgeChat : public CHudBaseChat
{
	DECLARE_CLASS_SIMPLE( CHudSwarmForgeChat, CHudBaseChat );

public:
	CHudSwarmForgeChat( const char *pElementName );
	void Init( void );
	void MsgFunc_SayText( bf_read &msg );
};

#endif // SWARMFORGE_HUD_CHAT_H
