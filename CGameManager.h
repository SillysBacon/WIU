#pragma once
#include "CMap.h"
#include "Cinventory.h"
#include "CUI.h"
#include <vector>
class CGameManager
{
	int static const MAX_MAPS = 11;
	CMap map[MAX_MAPS];
	CUI UI;
	int currentMap;
	int currentUI;
	bool IsGameRunning;
	inventorySystem inventory;
public:
	void TestDialogue();
	void SetMaps();
	void changeMaps(char input);
	vector<vector<int>> Connect;
	void RunGame();

	CGameManager();
};

