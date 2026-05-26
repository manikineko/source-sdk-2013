#ifndef CLIENTMODE_SWARMFORGE_H
#define CLIENTMODE_SWARMFORGE_H
#ifdef _WIN32
#pragma once
#endif

#include "clientmode_hl2mpnormal.h"

class ClientModeSwarmForge : public ClientModeHL2MPNormal
{
	DECLARE_CLASS_SIMPLE( ClientModeSwarmForge, ClientModeHL2MPNormal );

public:
	ClientModeSwarmForge();
	virtual ~ClientModeSwarmForge();

	virtual void Init();
	virtual void InitViewport();
};

extern IClientMode *GetClientMode();
extern ClientModeSwarmForge *GetClientModeNormal();

#endif // CLIENTMODE_SWARMFORGE_H
