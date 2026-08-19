#include "CGameManager.h"
#include <iostream>

void CGameManager::SetMaps() {
    map[0].SetRoom(10, 12);//office
    map[0].SetName("Detective Black's Office");

    map[1].SetRoom(20, 10);//Mansion living room
    map[1].SetName("The Mansion's Living room");

    map[2].SetRoom(6, 6);//Mansion toilet
    map[2].SetName("The Mansion's toilet");

    map[3].SetRoom(10, 10);//Mansion masterbedrm
    map[3].SetName("The Mansion's Master bedroom");

    map[4].SetRoom(8, 10);//Mansion bedrm
    map[4].SetName("The Mansion's Child's bedroom");

    map[5].SetRoom(30, 30);//Mansion garden
    map[5].SetName("The Mansion's Garden");

    map[6].SetRoom(10, 10);//Mansion study rm
    map[6].SetName("The Mansion's Study room");

    map[7].SetRoom(20, 10);//Mansion kitchen
    map[7].SetName("The Mansion's Kitchen");

    map[8].SetRoom(30, 10);//Neighbour hse living rm
    map[8].SetName("The Collins' Living room");

    map[9].SetRoom(10, 10);//Neighbour hse bedrm
    map[9].SetName("The Collins' Bedroom");

    map[10].SetRoom(15, 10);//Prosecutor office
    map[10].SetName("The Prosecutors' Office");

    Connect.resize(11);
    Connect[0] = { 1, 8, 10 };
    Connect[1] = { 0, 2, 3, 4, 5, 6, 7, 8, 10 };
    Connect[2] = { 1 };
    Connect[3] = { 1, 2, 4, 6 };
    Connect[4] = { 1, 2, 3, 6 };
    Connect[5] = { 1, 7 };
    Connect[6] = { 1, 2, 3, 4 };
    Connect[7] = { 1, 5 };
    Connect[8] = { 0, 1, 9, 10 };
    Connect[9] = { 8 };
    Connect[10] = { 0, 1 };
}
int CGameManager::SelectDestination(vector<int>& options) {
    int pos = 0;
    bool selecting = true;
    int destination = -1;

    while (selecting) {
        system("cls");
        cout << "\n      [Where do you want to go now, Mr Black?]\n";
        cout << "+====Current Location: " << map[currentMap].GetName() << "====+" << endl << endl;

        for (int i = 0; i < (int)options.size(); i++) {
            if (i == pos) {
                cout << "      ~> " << "[" << map[options[i]].GetName() << "]" << endl;
            }
            else {
                cout << "         " << "[" << map[options[i]].GetName() << "]" << endl;
            }
        }

        int input = _getch();

        if (input == 0 || input == 224) {
            input = _getch();
            if (input == 72 && pos > 0) {
                pos -= 1;
            }
            else if (input == 80 && pos < (int)options.size() - 1) {
                pos += 1;
            }
        }
        else if (input == 13) {
            destination = options[pos];
            selecting = false;
        }
        else if (input == 27) {
            selecting = false;
        }
    }

    return destination;
}
//KAI XIN change this part for the change map mechanic
void CGameManager::changeMaps(char input)
{
    if (input == 'm') {

        vector<int>& option = Connect[currentMap];
        int destination = SelectDestination(option);

        if (destination != -1) {
            map[currentMap].removePosition(
                map[currentMap].GetPlayer()->GetPosY(),
                map[currentMap].GetPlayer()->GetPosX()
            );

            currentMap = destination;
            map[currentMap].GetPlayer()->SetPosX(0);
            map[currentMap].GetPlayer()->SetPosY(0);
            map[currentMap].SetPosition();
            map[currentMap].RenderMap();

            UI.typeText("You are now at "); UI.typeText(map[currentMap].GetName()); UI.typeText(".\n");
        }
        else {
            map[currentMap].RenderMap();
        }
    }
    else if (input == 'e') {
        string object;
        object = map[0].GetItem(map[currentMap].GetPlayer()->GetPosX(), map[currentMap].GetPlayer()->GetPosY());
        inventory.addToInventory(object);
    }
    else if (input == 'f') {
        char npc;
        npc = map[0].GetItem(map[currentMap].GetPlayer()->GetPosX(), map[currentMap].GetPlayer()->GetPosY());
    }
    else {
        map[currentMap].Movement(input);
    }
}

void CGameManager::displayDialogue(string c, string t) {
    UI.RenderDialougeBox(c, t);
    map[currentMap].RenderMap();
}

void CGameManager::TestDialogue() {
    displayDialogue("Game", "Detective black Sits in his chair as he chainsmokes a cigar");
    displayDialogue("Game", "Like its another one of his noir movies that he larps");
    displayDialogue("Game", "One more and Cancer is calling his name but whatever");
    displayDialogue("Game", "Its been a while since the poor man has gotten a case");
    displayDialogue("Game", "One more cigar and the only thing calling him will be bankrupcy");
    displayDialogue("Game", "Oh whats that. why its his equally good for nothing assistant");
    displayDialogue("Game", "Maybe its a case, maybe not. Oh i wonder");
    displayDialogue("Game", "It's Thursday night, 18:34. Detective Black sits in his office, smoking a cigar. A knock sounds at the door.");
    displayDialogue("Game", "Come in.");
    displayDialogue("Game", "He stubs out the cigar in the ashtray as the door opens.");
    displayDialogue("Game", "In comes a tall, leanly built man, hair side-parted, a visible eye bag under each eye.");
    displayDialogue("Game", "It's Silas Reed, Black's partner and assistant.");
    displayDialogue("Game", "We just got a call, Silas says.");
    displayDialogue("Game", "Sounds like a murder down in Willow's Creek. We're up.");
}

void CGameManager::RunGame() {
    map[currentMap].RenderMap();
    //TestDialogue();
    while (IsGameRunning) {
        char input = _getch();

        if (input == 27) {
            bool keepPlaying = UI.PauseMenu();
            if (!keepPlaying) {
                IsGameRunning = false;
            }
            else {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (input == 'i' && caseFileSystem.getCFSState() == false) {
            inventory.showInventory(input);
            if (!inventory.getInventoryState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (input == 'c' && inventory.getInventoryState() == false) {
            caseFileSystem.showFiles(input);
            if (!caseFileSystem.getCFSState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (inventory.getInventoryState() == false) {
            if (caseFileSystem.getCFSState() == false) {
                changeMaps(input);
            }
            else {
                caseFileSystem.changeFiles(input);
                caseFileSystem.renderFiles();
            }
        }
        else {
            inventory.switchItem(input);
            inventory.renderInventory();
        }
    }
}

CGameManager::CGameManager() {
    currentMap = 0;
    currentUI = 0;
    SetMaps();
    UI.Run();
    if (UI.GetGameStart()){
        IsGameRunning = true;
    }
    else {
        IsGameRunning = false;
    }
    if (IsGameRunning) {
        RunGame();
    }
    else {
        return;
    }
}