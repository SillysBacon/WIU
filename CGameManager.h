#pragma once
#include "CMap.h"
#include "Cinventory.h"
#include "CcaseFileSystem.h"
#include "CUI.h"
#include <vector>
class CGameManager
{
	int item = 1;
	int static const MAX_MAPS = 11;
	CMap map[MAX_MAPS];
	CUI UI;
	int currentMap;
	int currentUI;
	bool IsGameRunning;
	inventorySystem inventory;
	CcaseFileSystem caseFileSystem;
	vector<vector<int>> Connect;
public:
	int SelectDestination(vector<int>& options);
	void displayDialogue(string c, string t);
	void TestDialogue();
	void SetMaps();
	void changeMaps(char input);
	void RunGame();

	CGameManager();
};

