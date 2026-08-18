#pragma once
#include "CMap.h"
#include "Cinventory.h"
#include <vector>
class CGameManager
{
	int static const MAX_MAPS = 11;
	CMap map[MAX_MAPS];
	int currentMap;
	int currentUI;
	inventorySystem inventory;
public:
	void SetMaps();
	void changeMaps(char input);
	std::vector<std::vector<int>> Connect;
	CGameManager();
};

