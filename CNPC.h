#pragma once
#include "CGameObject.h"
#include "CUI.h"
#include "CMAP.h"
#include "CInventory.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class NPC :
	public CGameObject
{
	string name;
	char symbol;
	int age;
	string occupation;
	bool killerStatus;
	string dialogue;
	struct DialogueOption {
		string text;
		int nextNode;
		int Eventflag = 0;
	};
	struct DialogueNode {
		string speaker; //added speaker 
		string npcLine;
		vector<DialogueOption> options;
	};
	vector<DialogueNode> DialougeTree;
	int currentNode = 0;
	int selectedOption = 0;
	int Eventstate;
	int PresentPosition = 0;
	bool isPresentEvidenceOpen = false;
	bool evidenceCorrect = false;
	struct IsEvidenceCorrect {
		int ExpectedID;
		int CorrectNode;
		int incorrectNode;
	};
	unordered_map<int, IsEvidenceCorrect> evidenceRequests;
public:
	enum People
	{
		Sarah_Collins,
		Emily_Smith,
		Michael_Turner,
		Trisha_Lopez,
		Angelo_Batista,
		Harvey_Denn,
		Forensics,
		Jonathan_Smith,
		Silias_Reeds,
		Police,
		Narrator //added narrator
	};

	void setPerson(People p);
	People getPerson();
	string getName();
	char getSymbol();
	int getAge();
	string getOccupation();
	bool getKillerStatus();
	bool isSuspect();
	string getDialogue();
	string setDialogue(string text);
	int getCurrentNode();//for items

	void ResetDialogueTree();
	void RenderDialougeSystem(bool typetext, CMap* map);
	void dialougesystem(CMap* map, inventorySystem* inventory);
	int AddDialougeNode(string npcDialouge, string ovrdSpeaker = ""); //ovrdSpeaker = overide speaker for Narrator
	void AddNodeOption(int nodeIndex, int eventState, int Go_To_Node_Index, string text);
	void Addeventflag();
	vector<int> GetVisibleOptions(const DialogueNode& node);
	void presentEvidence(inventorySystem* Inventory, int id, char input);
	void RenderPresentEvidence(inventorySystem* Inventory);
	void SwitchEvidence(char input, inventorySystem* inventory);
	void showPresentEvidence(inventorySystem* inventory);
	bool GetisPresentOpen();
	static const int PRESENT_EVIDENCE = -2;

	void SetEvidenceRequest(int nodeIndex, int expectedItemID, int correctNode, int incorrectNode);
	NPC();

	struct EvidenceCheck {
		int expectedItemID;
		int correctNode;
		int incorrectNode;
	};
private:

	People person;

};

