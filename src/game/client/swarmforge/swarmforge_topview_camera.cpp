#include "cbase.h"
#include "swarmforge_topview_camera.h"
#include "c_swarmforge_player.h"
#include "input.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// Topview Camera ConVars
ConVar sf_topview_enabled( "sf_topview_enabled", "0", FCVAR_ARCHIVE | FCVAR_USERINFO, "Enable top-down camera view" );
ConVar sf_topview_pitch( "sf_topview_pitch", "60", FCVAR_ARCHIVE, "Topview camera pitch angle" );
ConVar sf_topview_yaw( "sf_topview_yaw", "90", FCVAR_ARCHIVE, "Topview camera yaw angle" );
ConVar sf_topview_distance( "sf_topview_distance", "412", FCVAR_ARCHIVE, "Topview camera distance from player" );
ConVar sf_topview_height( "sf_topview_height", "300", FCVAR_ARCHIVE, "Topview camera height above player" );
ConVar sf_topview_smooth( "sf_topview_smooth", "1", FCVAR_ARCHIVE, "Enable camera smoothing" );
ConVar sf_topview_pitch_rate( "sf_topview_pitch_rate", "1000", FCVAR_CHEAT, "Camera pitch interpolation rate" );
ConVar sf_topview_yaw_rate( "sf_topview_yaw_rate", "1000", FCVAR_CHEAT, "Camera yaw interpolation rate" );
ConVar sf_topview_dist_rate( "sf_topview_dist_rate", "50", FCVAR_CHEAT, "Camera distance interpolation rate" );

static CSwarmForgeTopViewCamera g_SwarmForgeTopViewCamera;
CSwarmForgeTopViewCamera *g_pSwarmForgeTopViewCamera = &g_SwarmForgeTopViewCamera;

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CSwarmForgeTopViewCamera::CSwarmForgeTopViewCamera()
{
	m_flCameraPitch = sf_topview_pitch.GetFloat();
	m_flCameraYaw = sf_topview_yaw.GetFloat();
	m_flCameraDistance = sf_topview_distance.GetFloat();
	m_flCameraHeight = sf_topview_height.GetFloat();
	
	m_flCurrentPitch = m_flCameraPitch;
	m_flCurrentYaw = m_flCameraYaw;
	m_flCurrentDistance = m_flCameraDistance;
	m_flCurrentHeight = m_flCameraHeight;
	
	m_bTopViewEnabled = sf_topview_enabled.GetBool();
	m_bSmoothCamera = sf_topview_smooth.GetBool();
}

//-----------------------------------------------------------------------------
// Purpose: Destructor
//-----------------------------------------------------------------------------
CSwarmForgeTopViewCamera::~CSwarmForgeTopViewCamera()
{
}

//-----------------------------------------------------------------------------
// Purpose: Initialize the camera system
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::Init()
{
	m_flCameraPitch = sf_topview_pitch.GetFloat();
	m_flCameraYaw = sf_topview_yaw.GetFloat();
	m_flCameraDistance = sf_topview_distance.GetFloat();
	m_flCameraHeight = sf_topview_height.GetFloat();
	
	m_flCurrentPitch = m_flCameraPitch;
	m_flCurrentYaw = m_flCameraYaw;
	m_flCurrentDistance = m_flCameraDistance;
	m_flCurrentHeight = m_flCameraHeight;
	
	m_bTopViewEnabled = sf_topview_enabled.GetBool();
	m_bSmoothCamera = sf_topview_smooth.GetBool();
}

//-----------------------------------------------------------------------------
// Purpose: Update camera state each frame
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::Think()
{
	// Update from ConVars if they changed
	if ( m_bTopViewEnabled != sf_topview_enabled.GetBool() )
	{
		m_bTopViewEnabled = sf_topview_enabled.GetBool();
	}
	
	if ( m_bSmoothCamera != sf_topview_smooth.GetBool() )
	{
		m_bSmoothCamera = sf_topview_smooth.GetBool();
	}
	
	// Update target values
	m_flCameraPitch = sf_topview_pitch.GetFloat();
	m_flCameraYaw = sf_topview_yaw.GetFloat();
	m_flCameraDistance = sf_topview_distance.GetFloat();
	m_flCameraHeight = sf_topview_height.GetFloat();
}

//-----------------------------------------------------------------------------
// Purpose: Set camera pitch
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::SetCameraPitch( float flPitch )
{
	m_flCameraPitch = flPitch;
	sf_topview_pitch.SetValue( flPitch );
}

//-----------------------------------------------------------------------------
// Purpose: Set camera yaw
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::SetCameraYaw( float flYaw )
{
	m_flCameraYaw = flYaw;
	sf_topview_yaw.SetValue( flYaw );
}

//-----------------------------------------------------------------------------
// Purpose: Set camera distance
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::SetCameraDistance( float flDistance )
{
	m_flCameraDistance = flDistance;
	sf_topview_distance.SetValue( flDistance );
}

//-----------------------------------------------------------------------------
// Purpose: Set camera height
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::SetCameraHeight( float flHeight )
{
	m_flCameraHeight = flHeight;
	sf_topview_height.SetValue( flHeight );
}

//-----------------------------------------------------------------------------
// Purpose: Enable/disable topview mode
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::SetTopViewEnabled( bool bEnabled )
{
	m_bTopViewEnabled = bEnabled;
	sf_topview_enabled.SetValue( bEnabled ? 1 : 0 );
}

//-----------------------------------------------------------------------------
// Purpose: Calculate camera position for a player
//-----------------------------------------------------------------------------
void CSwarmForgeTopViewCamera::CalculateCameraPosition( C_SwarmForgePlayer *pPlayer, Vector &vecCameraOrigin, QAngle &angCameraAngles )
{
	if ( !pPlayer )
		return;

	Vector vecPlayerOrigin = pPlayer->GetAbsOrigin();
	
	// Calculate target camera position
	float flPitch = m_flCameraPitch;
	float flYaw = m_flCameraYaw;
	float flDistance = m_flCameraDistance;
	float flHeight = m_flCameraHeight;
	
	// Apply smoothing if enabled
	if ( m_bSmoothCamera )
	{
		float flFrameTime = gpGlobals->frametime;
		if ( flFrameTime > 0.0f )
		{
			// Smooth pitch
			float flPitchDelta = fabs( m_flCurrentPitch - flPitch );
			if ( flPitchDelta > 0.1f )
			{
				float flPitchStep = MIN( 0.2f, flFrameTime );
				m_flCurrentPitch = ApproachAngle( flPitch, m_flCurrentPitch, sf_topview_pitch_rate.GetFloat() * flPitchStep );
			}
			else
			{
				m_flCurrentPitch = flPitch;
			}
			
			// Smooth yaw
			float flYawDelta = fabs( m_flCurrentYaw - flYaw );
			if ( flYawDelta > 0.1f )
			{
				float flYawStep = MIN( 0.2f, flFrameTime );
				m_flCurrentYaw = ApproachAngle( flYaw, m_flCurrentYaw, sf_topview_yaw_rate.GetFloat() * flYawStep );
			}
			else
			{
				m_flCurrentYaw = flYaw;
			}
			
			// Smooth distance
			float flDistDelta = fabs( m_flCurrentDistance - flDistance );
			if ( flDistDelta > 1.0f )
			{
				float flDistStep = MIN( 0.2f, flFrameTime );
				m_flCurrentDistance = Approach( flDistance, m_flCurrentDistance, sf_topview_dist_rate.GetFloat() * flDistStep );
			}
			else
			{
				m_flCurrentDistance = flDistance;
			}
			
			// Smooth height
			float flHeightDelta = fabs( m_flCurrentHeight - flHeight );
			if ( flHeightDelta > 1.0f )
			{
				float flHeightStep = MIN( 0.2f, flFrameTime );
				m_flCurrentHeight = Approach( flHeight, m_flCurrentHeight, sf_topview_dist_rate.GetFloat() * flHeightStep );
			}
			else
			{
				m_flCurrentHeight = flHeight;
			}
		}
	}
	else
	{
		m_flCurrentPitch = flPitch;
		m_flCurrentYaw = flYaw;
		m_flCurrentDistance = flDistance;
		m_flCurrentHeight = flHeight;
	}
	
	// Calculate camera angles
	angCameraAngles[PITCH] = m_flCurrentPitch;
	angCameraAngles[YAW] = m_flCurrentYaw;
	angCameraAngles[ROLL] = 0;
	
	// Calculate camera position based on angles and distance
	Vector vecForward, vecRight, vecUp;
	AngleVectors( angCameraAngles, &vecForward, &vecRight, &vecUp );
	
	// Position camera behind and above the player
	vecCameraOrigin = vecPlayerOrigin;
	vecCameraOrigin -= vecForward * m_flCurrentDistance;
	vecCameraOrigin.z += m_flCurrentHeight;
}
