#pragma once
#include "CGameObject.h"
#include <iostream>
#include <string>
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

	NPC();

private:
	People person;
};

