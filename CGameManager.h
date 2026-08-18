#pragma once
#include "CMap.h"
#include "Cinventory.h"
class CGameManager
{
	int static const MAX_MAPS = 11;
	CMap map[MAX_MAPS];
	int currentMap;
	int currentUI;
	inventorySystem inventory;
public:
	void interact();
	void SetMaps();
	void changeMaps(char input);
	CGameManager();
};

