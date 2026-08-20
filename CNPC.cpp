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

void NPC::ResetDialogueTree() {
	DialougeTree.clear();
	currentNode = 0;
	selectedOption = 0;
	Eventstate = 0;
}

int NPC::AddDialougeNode(string npcDialouge) {
	DialogueNode node;
	node.npcLine = npcDialouge;
	DialougeTree.push_back(node);
	return (int)DialougeTree.size() - 1;
}

void NPC::AddNodeOption(int nodeIndex, int eventState, int Go_To_Node_Index, string text) {
	DialogueNode node;
	if (nodeIndex >= 0 && nodeIndex < (int)DialougeTree.size()) {
		DialougeTree[nodeIndex].options.push_back({ text, Go_To_Node_Index, eventState });
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
void NPC::RenderDialougeSystem(bool typetext, CMap* map) {
	CUI::GetInstance().Clear();
	map->RenderMap();
	bool dialougePrintoutFinished = false;
	const DialogueNode& node = DialougeTree[currentNode]; 
	string fullLine = "\033[32m" + name + "\033[0m" + ": " + node.npcLine;
	int boxWidth = (int)fullLine.length() - 9 + 6;

	cout << "+" << std::string(boxWidth - 2, '-') << "+\n";
	cout << "|  ";
	if (typetext) {
		CUI::GetInstance().typeText(fullLine);
	}
	else if(!typetext){
		cout << fullLine;
	}
	cout << "  |\n";
	cout << "+" << std::string(boxWidth - 2, '-') << "+\n";
	for (int i = 0; i < (int)node.options.size(); i++) {
		if (i == selectedOption)
			cout << "   ~> " << node.options[i].text << endl;
		else
			cout << "      " << node.options[i].text << endl;
	}
}

void NPC::dialougesystem(CMap* map) {
	currentNode = 0;
	selectedOption = 0;
	int lastnode=-1;
	bool talking = true;
	while (talking) {
		bool typetext = (currentNode != lastnode);
		RenderDialougeSystem(typetext, map);
		lastnode = currentNode;
		const DialogueNode& node = DialougeTree[currentNode];

		int input = _getch();

		if (input == 0 || input == 224) {
			input = _getch();
			if (input == 72 && selectedOption > 0) {
				selectedOption--;
			}
			else if (input == 80 && selectedOption < (int)node.options.size() - 1) {
				selectedOption++;
			}
		}
		else if (input == 13) {
			int next = node.options[selectedOption].nextNode;
			if (next == -1) {
				talking = false;
			}
			else {
				currentNode = next;
				selectedOption = 0;
			}
		}
		else if (input == 27) {
			talking = false;
		}
	}
}


NPC::NPC() {
	ResetDialogueTree();
	person = Sarah_Collins;
	name = "";
	symbol = '\0';
	age = 0;
	occupation = "";
	killerStatus = false;
	SetPosX(0);
	SetPosY(0);
}