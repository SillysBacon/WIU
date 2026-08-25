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

	int static const MAX_MAPS = 13;
	static const int MAX_OBSTACLE = 100;
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
	CObstacle* EvidencePtr1;
	CObstacle* EvidencePtr2;
	CObstacle* EvidencePtr3;
	CObstacle* EvidencePtr4;
	CObstacle* EvidencePtr5;
	CObstacle* EvidencePtr6;
	CObstacle* EvidencePtr7;
	CObstacle* EvidencePtr8;
	CObstacle* EvidencePtr9;
	CObstacle* EvidencePtr10;
	CObstacle* EvidencePtr11;
	CObstacle* ObstacleInteract;
	CEvidence Evidence;
	CGameManager* evidence = nullptr;
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
	NPC* Silas = new NPC;
	vector<bool> mapVisited;
	vector<vector<pair<string, string>>> mapIntroDialogue;
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
	int GetDialogue_Length(CEvidence::Evidence e);
	//string runDialogue(CEvidence::Evidence e, int num);
	void checkForEvidence(CObstacle* oPtr, CObstacle* ptr, CEvidence::Evidence e);
	CGameManager* GetEvidencePtr();
	void RemoveRoom(int mapIndex);


	CGameManager();
	~CGameManager();

};
