#pragma once
#include "CMap.h"
class CGameManager
{
	int static const MAX_MAPS = 11;
	CMap map[MAX_MAPS];
	int currentMap;
public:
	void SetMaps();
	void changeMaps(char input);
	CGameManager();
};

