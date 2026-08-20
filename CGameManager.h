#pragma once
#include "CMap.h"
#include "Cinventory.h"
#include "CcaseFileSystem.h"
#include "CNPC.h"
#include "CUI.h"
#include "CObstacle.h"
#include <vector>
class CGameManager
{
	int static const MAX_MAPS = 11;
	static const int MAX_OBSTACLE = 100;
	CMap map[MAX_MAPS];
	CUI UI;
	int currentMap;
	int currentUI;
	bool IsGameRunning;
	inventorySystem inventory;
	CcaseFileSystem caseFileSystem;
	NPC* NPCs;
	vector<vector<int>> Connect;
	vector<vector<CObstacle*>> mapObstacles;
	vector<vector<NPC*>> mapNPCs;
	CObstacle* Obstacle[MAX_OBSTACLE];
	int item = 1;
public:
	int SelectDestination(vector<int>& options);
	CObstacle* AddObstacle(int mapIndex, CObstacle::Furniture type, int x, int y, bool rotation);
	NPC* AddNPC(int mapIndex, NPC::People type, int x, int y);
	void displayDialogue(string c, string t);
	void TestDialogue();
	void SetMaps();
	void changeMaps(char input);
	void RunGame();
	CObstacle* FindObstacle(int mapIndex, int x, int y);

	CGameManager();

};
