#include "cbase.h"
#include "clientmode_swarmforge.h"
#include "vgui_int.h"
#include "vgui/IVGui.h"
#include "iinput.h"

static ClientModeSwarmForge g_ClientModeNormal;

IClientMode *GetClientMode()
{
	return &g_ClientModeNormal;
}

ClientModeSwarmForge *GetClientModeNormal()
{
	return &g_ClientModeNormal;
}

ClientModeSwarmForge::ClientModeSwarmForge()
{
}

ClientModeSwarmForge::~ClientModeSwarmForge()
{
}

void ClientModeSwarmForge::Init()
{
	BaseClass::Init();

	// Load scheme
	vgui::scheme()->LoadSchemeFromFile( "resource/SwarmForgeScheme.res", "SwarmForge" );
}

void ClientModeSwarmForge::InitViewport()
{
	BaseClass::InitViewport();
}
