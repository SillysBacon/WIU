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
	case Narrator: //added narrator
		name = "Narrator";
		symbol = 'n';
		age = 10;
		occupation = "";
		killerStatus = false;
		break;
	}
}

vector<int> NPC::GetVisibleOptions(const DialogueNode& node) {
	vector<int> visible;
	for (int i = 0; i < (int)node.options.size(); i++) {
		if (node.options[i].Eventflag <= Eventstate) {
			visible.push_back(i);
		}
	}
	return visible;
}

void NPC::ResetDialogueTree() {
	DialougeTree.clear();
	currentNode = 0;
	selectedOption = 0;
	Eventstate = 0;
}

int NPC::AddDialougeNode(string npcDialouge, string ovrdSpeaker) {
	DialogueNode node;
	node.npcLine = npcDialouge;
	if (ovrdSpeaker.empty()) {
		node.speaker = name;
	}
	else {
		node.speaker = ovrdSpeaker;
	}
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
	string fullLine = "\033[32m" + node.speaker + "\033[0m" + ": " + node.npcLine; //change name to node.speaker
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
	vector<int> visible = GetVisibleOptions(node);
	for (int i = 0; i < (int)visible.size(); i++) {
		int optIdx = visible[i];
		if (i == selectedOption)
			cout << "   ~> " << node.options[optIdx].text << endl;
		else
			cout << "      " << node.options[optIdx].text << endl;
	}
}
void NPC::dialougesystem(CMap* map, inventorySystem* inventory) {
	currentNode = 0;
	selectedOption = 0;
	int lastnode = -1;
	bool talking = true;

	while (talking) {
		bool typetext = (currentNode != lastnode);
		RenderDialougeSystem(typetext, map);
		lastnode = currentNode;
		const DialogueNode& node = DialougeTree[currentNode];
		vector<int> visible = GetVisibleOptions(node);

		int input = _getch();

		if (input == 0 || input == 224) {
			input = _getch();

			if (input == 72 && selectedOption > 0) {
				selectedOption--;
			}
			else if (input == 80 && selectedOption < (int)visible.size() - 1) {
				selectedOption++;
			}
		}
		else if (input == 13) {
			if (visible.empty()) {
				continue;
			}

			int actualOptIdx = visible[selectedOption];
			int next = node.options[actualOptIdx].nextNode;

			if (next == PRESENT_EVIDENCE) {
				auto it = evidenceRequests.find(currentNode);
				int expectedID = -1;
				if (it != evidenceRequests.end()) {
					expectedID = it->second.ExpectedID;
				}

				isPresentEvidenceOpen = true;
				PresentPosition = 0;

				while (isPresentEvidenceOpen) {
					RenderPresentEvidence(inventory);
					int evInput = _getch();

					if (evInput == 0 || evInput == 224) {
						evInput = _getch();
						SwitchEvidence((char)evInput, inventory);
					}
					else {
						presentEvidence(inventory, expectedID, (char)evInput);
					}
				}

				if (it != evidenceRequests.end()) {
					if (evidenceCorrect) {
						currentNode = it->second.CorrectNode;
					}
					else {
						currentNode = it->second.incorrectNode;
					}
				}

				selectedOption = 0;
				map->RenderMap();
			}
			else if (next == -1) {
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
void NPC::Addeventflag() {
	Eventstate++;
}

int NPC::getCurrentNode() {
	return currentNode;
}

void NPC::SetEvidenceRequest(int nodeIndex, int expectedItemID, int correctNode, int incorrectNode) {
	IsEvidenceCorrect check;
	check.ExpectedID = expectedItemID;
	check.CorrectNode = correctNode;
	check.incorrectNode = incorrectNode;
	evidenceRequests[nodeIndex] = check;
}

void NPC::RenderPresentEvidence(inventorySystem* Inventory) {
	CUI::GetInstance().Clear();
	cout << "       [Present Evidence]\n";
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	for (int i = 0; i < Inventory->GetItemCount(); i++) {
		if (i == PresentPosition) {
			cout << "~> " << Inventory->GetInventory(i) << endl;
		}
		else {
			cout << "   " << Inventory->GetInventory(i) << endl;
		}
	}
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~+\n";
}

void NPC::SwitchEvidence(char input, inventorySystem* inventory) {
	if (input == 72) {
		if (PresentPosition > 0) {
			PresentPosition -= 1;
		}
	}
	else if (input == 80) {
		if (PresentPosition < inventory->GetItemCount() - 1) {
			PresentPosition += 1;
		}
	}
}

void NPC::presentEvidence(inventorySystem* Inventory, int id, char input) {
	if (input == 0 || input == (char)224) {
		SwitchEvidence(input, Inventory);
	}
	else if (input == 13) {
		if (Inventory->GetItemCount() > 0) {
			int chosenID = Inventory->GetInventoryID(PresentPosition);
			evidenceCorrect = (chosenID == id);
		}
		else {
			evidenceCorrect = false;
		}
		isPresentEvidenceOpen = false;
	}
	else if (input == 27) {
		evidenceCorrect = false;
		isPresentEvidenceOpen = false;
	}
}

void NPC::showPresentEvidence(inventorySystem* inventory) {
	if (isPresentEvidenceOpen) {
		RenderPresentEvidence(inventory);
	}
}

bool NPC::GetisPresentOpen() {
	return isPresentEvidenceOpen;
}

NPC::NPC() {
	ResetDialogueTree();
	int Eventstate = 0;
	person = Sarah_Collins;
	name = "";
	symbol = '\0';
	age = 0;
	occupation = "";
	killerStatus = false;
	SetPosX(0);
	SetPosY(0);
}
