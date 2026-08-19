 #include "CNPC.h"

string NPC::getName(int num) {
	return name[num];
}

char NPC::getSymbol(int num) {
	return symbol[num];
}

int NPC::getAge(int num) {
	return age[num];
}

string NPC::getOccupation(int num) {
	return occupation[num];
}

bool NPC::getKillerStatus(int num) {
	return isNPCKiller[num];
}

NPC::NPC() {
	currentNPC = 0;
}