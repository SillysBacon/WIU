#pragma once
#include "CGameObject.h"
#include <iostream>
#include <string>
using namespace std;

class NPC :
	public CGameObject
{
	int const static MAX_NPC = 5;
	string name[MAX_NPC] = {"Emily Smith", "Michael Turner", "Sarah Collins", "Trisha Lopez", "Angelo Batista"};
	char symbol[MAX_NPC] = {'E', 'N', 'S', 'T', 'A'};
	int age[MAX_NPC] = {1, 2, 3, 4, 5};
	string occupation[MAX_NPC] = {"", "", "", "", ""};
	bool isNPCKiller[MAX_NPC] = {false, true, false, false, false};
	int currentNPC;
public:
	string getName(int num);
	char getSymbol(int num);
	int getAge(int num);
	string getOccupation(int num);
	bool getKillerStatus(int num);

	NPC();
};

