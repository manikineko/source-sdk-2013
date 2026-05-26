#include "cbase.h"
#include "swarmforge_topview_camera.h"
#include "c_swarmforge_player.h"
#include "concommand.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Console commands for topview camera
//-----------------------------------------------------------------------------
CON_COMMAND( sf_topview_toggle, "Toggle top-down camera view" )
{
	if ( !g_pSwarmForgeTopViewCamera )
		return;

	bool bCurrentState = g_pSwarmForgeTopViewCamera->IsTopViewEnabled();
	g_pSwarmForgeTopViewCamera->SetTopViewEnabled( !bCurrentState );

	Msg( "Topview camera %s\n", !bCurrentState ? "enabled" : "disabled" );
}

CON_COMMAND( sf_topview_on, "Enable top-down camera view" )
{
	if ( !g_pSwarmForgeTopViewCamera )
		return;

	g_pSwarmForgeTopViewCamera->SetTopViewEnabled( true );
	Msg( "Topview camera enabled\n" );
}

CON_COMMAND( sf_topview_off, "Disable top-down camera view" )
{
	if ( !g_pSwarmForgeTopViewCamera )
		return;

	g_pSwarmForgeTopViewCamera->SetTopViewEnabled( false );
	Msg( "Topview camera disabled\n" );
}

CON_COMMAND( sf_topview_set_pitch, "Set topview camera pitch" )
{
	if ( args.ArgC() < 2 )
	{
		Msg( "Usage: sf_topview_set_pitch <pitch_angle>\n" );
		return;
	}

	if ( !g_pSwarmForgeTopViewCamera )
		return;

	float flPitch = atof( args.Arg( 1 ) );
	g_pSwarmForgeTopViewCamera->SetCameraPitch( flPitch );
	Msg( "Topview camera pitch set to %.2f\n", flPitch );
}

CON_COMMAND( sf_topview_set_yaw, "Set topview camera yaw" )
{
	if ( args.ArgC() < 2 )
	{
		Msg( "Usage: sf_topview_set_yaw <yaw_angle>\n" );
		return;
	}

	if ( !g_pSwarmForgeTopViewCamera )
		return;

	float flYaw = atof( args.Arg( 1 ) );
	g_pSwarmForgeTopViewCamera->SetCameraYaw( flYaw );
	Msg( "Topview camera yaw set to %.2f\n", flYaw );
}

CON_COMMAND( sf_topview_set_distance, "Set topview camera distance" )
{
	if ( args.ArgC() < 2 )
	{
		Msg( "Usage: sf_topview_set_distance <distance>\n" );
		return;
	}

	if ( !g_pSwarmForgeTopViewCamera )
		return;

	float flDistance = atof( args.Arg( 1 ) );
	g_pSwarmForgeTopViewCamera->SetCameraDistance( flDistance );
	Msg( "Topview camera distance set to %.2f\n", flDistance );
}

CON_COMMAND( sf_topview_set_height, "Set topview camera height" )
{
	if ( args.ArgC() < 2 )
	{
		Msg( "Usage: sf_topview_set_height <height>\n" );
		return;
	}

	if ( !g_pSwarmForgeTopViewCamera )
		return;

	float flHeight = atof( args.Arg( 1 ) );
	g_pSwarmForgeTopViewCamera->SetCameraHeight( flHeight );
	Msg( "Topview camera height set to %.2f\n", flHeight );
}
