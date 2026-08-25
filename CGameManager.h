#pragma once
#include "CMap.h"
#include "Cinventory.h"
#include "CcaseFileSystem.h"
#include "CNPC.h"
#include "CUI.h"
#include "CObstacle.h"
#include "CItem.h"
#include <vector>
class CGameManager
{
	struct NodeItems {
		NPC* npc;
		int node;
		string itemName;
		CItem::Items itemType;
	};
	struct NodeFlags {
		NPC* npc;
		int node;
		bool* flag;
	};
	vector<NodeFlags> nodeFlags;
	void checkNodeFlags(NPC* npc);

	int static const MAX_MAPS = 15;
	static const int MAX_OBSTACLE = 200;
	CMap map[MAX_MAPS];
	int currentMap;
	int currentUI;
	bool IsGameRunning;
	inventorySystem* inventory = new inventorySystem;
	CcaseFileSystem caseFileSystem;
	NPC* NPCs;
	vector<vector<int>> Connect;
	vector<vector<CObstacle*>> mapObstacles;
	vector<vector<NPC*>> mapNPCs;
	CObstacle* Obstacle[MAX_OBSTACLE];
	int item = 1;
	CItem Items;
	vector<CItem*> allItems;
	CItem* addItems(CObstacle* obstacle, CItem::Items type);
	vector<NodeItems> nodeItems;
	void checkNodeItems(NPC* npc);
	bool IsBedroomkeyPresent = false;
	bool IsMansionAvailable = false;
	bool IsCollinAvailable = false;
	bool IsProsecutorAvailable = false;
	bool IsMainPorchAvailable = false;
	bool IsMainStudyAvailable = false;
	bool CanTravel = false;
	bool hasTalkToSilas = false;
	bool NotebookisFound = false;
	bool CarKeysisFound = false;
	bool jacketisFound = false;
	NPC* Silas = new NPC;
	vector<bool> mapVisited;
	vector<vector<pair<string, string>>> mapIntroDialogue;
	vector<bool> mapRemoved;
public:
	int SelectDestination(vector<int>& options);
	CObstacle* AddObstacle(int mapIndex, CObstacle::Furniture type, int x, int y, bool rotation);
	NPC* AddNPC(int mapIndex, NPC::People type, int x, int y);
	NPC* FindNPC(int mapIndex, int x, int y);
	void displayDialogue(string c, string t);
	void TestDialogue();
	void SetMaps();
	void changeMaps(char input);
	void RunGame();
	CObstacle* FindObstacle(int mapIndex, int x, int y);
	bool IsMapUnlocked(int mapIndex);
	void PlayIntroDialogue(int mapIndex);
	void RemoveRoom(int mapIndex);


	CGameManager();
	~CGameManager();

};
