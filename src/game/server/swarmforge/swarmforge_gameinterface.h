#ifndef SWARMFORGE_GAMEINTERFACE_H
#define SWARMFORGE_GAMEINTERFACE_H
#ifdef _WIN32
#pragma once
#endif

#include "gameinterface.h"

class CSwarmForgeGameInterface : public CServerGameDLL
{
public:
	DECLARE_CLASS_SIMPLE( CSwarmForgeGameInterface, CServerGameDLL );

public:
	virtual bool Init();
	virtual void PostInit();
	virtual void LevelInit( const char *pMapName, const char *pMapEntities, const char *pOldLevel, const char *pLandmarkName, bool loadGame, bool background );
	virtual void LevelShutdown( void );
};

#endif // SWARMFORGE_GAMEINTERFACE_H
