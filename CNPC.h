#pragma once
#include "CGameObject.h"
#include "CUI.h"
#include "CMAP.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
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
		string npcLine;
		vector<DialogueOption> options;
	};
	vector<DialogueNode> DialougeTree;
	int currentNode = 0;
	int selectedOption = 0;
	int Eventstate;

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
		Silias_Reeds
	};

	void setPerson(People p);
	string getName();
	char getSymbol();
	int getAge();
	string getOccupation();
	bool getKillerStatus();
	string getDialogue();
	string setDialogue(string text);

	void ResetDialogueTree();
	void RenderDialougeSystem(bool typetext, CMap* map);
	void dialougesystem(CMap* map);
	int AddDialougeNode(string npcDialouge);
	void AddNodeOption(int nodeIndex, int eventState, int Go_To_Node_Index, string text);
	void Addeventflag();
	vector<int> GetVisibleOptions(const DialogueNode& node);

	NPC();

private:

	People person;

};

