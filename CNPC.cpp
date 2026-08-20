 #include "CNPC.h"

void NPC::setPerson(People p) {

	person = p;
	switch (p) 
	{
	case Sarah_Collins:
		name = "Sarah Collins";
		symbol = 'S';
		age = 1;
		occupation = "";
		killerStatus = false;
		break;
	case Emily_Smith:
		name = "Emily Smith";
		symbol = 'E';
		age = 2;
		occupation = "";
		killerStatus = false;
		break;
	case Michael_Turner:
		name = "Michael Turner";
		symbol = 'M';
		age = 3;
		occupation = "";
		killerStatus = true;
		break;
	case Trisha_Lopez:
		name = "Trisha Lopez";
		symbol = 'T';
		age = 4;
		occupation = "";
		killerStatus = false;
		break;
	case Angelo_Batista:
		name = "Angelo Batista";
		symbol = 'A';
		age = 5;
		occupation = "";
		killerStatus = false;
		break;
	case Harvey_Denn:
		name = "Harvey Denn";
		symbol = 'H';
		age = 6;
		occupation = "";
		killerStatus = false;
		break;
	case Forensics:
		name = "Forensics";
		symbol = 'F';
		age = 7;
		occupation = "";
		killerStatus = false;
		break;
	case Jonathan_Smith:
		name = "Jonathan Smith";
		symbol = 'J';
		age = 8;
		occupation = "";
		killerStatus = false;
		break;
	case Silias_Reeds:
		name = "Silias Reeds";
		symbol = 's';
		age = 9;
		occupation = "";
		killerStatus = false;
		break;
	}
}

string NPC::getName() {
	return name;
}

char NPC::getSymbol() {
	return symbol;
}

int NPC::getAge() {
	return age;
}

string NPC::getOccupation() {
	return occupation;
}

bool NPC::getKillerStatus() {
	return killerStatus;
}

string NPC::getDialogue() {
	return dialogue;
}

NPC::NPC() {
	person = Sarah_Collins;
	name = "";
	symbol = '\0';
	age = 0;
	occupation = "";
	killerStatus = false;
	SetPosX(0);
	SetPosY(0);
}