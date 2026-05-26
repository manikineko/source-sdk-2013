#ifndef SWARMFORGE_TOPVIEW_CAMERA_H
#define SWARMFORGE_TOPVIEW_CAMERA_H
#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"

class C_SwarmForgePlayer;

//-----------------------------------------------------------------------------
// Purpose: Top-down camera system for SwarmForge (based on Alien Swarm)
//-----------------------------------------------------------------------------
class CSwarmForgeTopViewCamera
{
public:
	CSwarmForgeTopViewCamera();
	~CSwarmForgeTopViewCamera();

	void Init();
	void Think();

	// Camera configuration
	void SetCameraPitch( float flPitch );
	void SetCameraYaw( float flYaw );
	void SetCameraDistance( float flDistance );
	void SetCameraHeight( float flHeight );

	// Get camera parameters
	float GetCameraPitch() const { return m_flCameraPitch; }
	float GetCameraYaw() const { return m_flCameraYaw; }
	float GetCameraDistance() const { return m_flCameraDistance; }
	float GetCameraHeight() const { return m_flCameraHeight; }

	// Enable/disable topview mode
	void SetTopViewEnabled( bool bEnabled );
	bool IsTopViewEnabled() const { return m_bTopViewEnabled; }

	// Calculate camera position for a player
	void CalculateCameraPosition( C_SwarmForgePlayer *pPlayer, Vector &vecCameraOrigin, QAngle &angCameraAngles );

private:
	float m_flCameraPitch;
	float m_flCameraYaw;
	float m_flCameraDistance;
	float m_flCameraHeight;
	float m_flCurrentPitch;
	float m_flCurrentYaw;
	float m_flCurrentDistance;
	float m_flCurrentHeight;

	bool m_bTopViewEnabled;
	bool m_bSmoothCamera;
};

extern CSwarmForgeTopViewCamera *g_pSwarmForgeTopViewCamera;

#endif // SWARMFORGE_TOPVIEW_CAMERA_H
