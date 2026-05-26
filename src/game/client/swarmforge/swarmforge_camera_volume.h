#ifndef SWARMFORGE_CAMERA_VOLUME_H
#define SWARMFORGE_CAMERA_VOLUME_H
#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"
#include "mapentities_shared.h"

//-----------------------------------------------------------------------------
// Purpose: Camera volume entity for controlling topview camera in map areas
// Based on Alien Swarm's asw_camera_control entity
//-----------------------------------------------------------------------------
class C_SwarmForge_CameraVolume : public C_BaseEntity
{
public:
	DECLARE_CLASS( C_SwarmForge_CameraVolume, C_BaseEntity );
	DECLARE_CLIENTCLASS();

	C_SwarmForge_CameraVolume();
	virtual ~C_SwarmForge_CameraVolume();

	virtual void Spawn();
	virtual bool Initialize();
	virtual bool ShouldDraw();

	// Check if a point is inside any camera volume and return the pitch
	static float IsPointInCameraVolume( const Vector &vecPoint );

	// Recreate all camera volumes (called on map load)
	static void RecreateAll();
	static void DestroyAll();

private:
	float m_flCameraPitch; // Camera pitch for this volume
};

// Global list of camera volumes
extern CUtlVector<C_SwarmForge_CameraVolume*> g_SwarmForgeCameraVolumes;

#endif // SWARMFORGE_CAMERA_VOLUME_H
