#include "CGameManager.h"
#include <iostream>
#include <string>
using namespace std;

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
//KAI XIN change this part for the change map mechanic
void CGameManager::changeMaps(char input)
{
    if (input == 'm') {

        vector<int>& option = Connect[currentMap];

        UI.typeText( "\n Where do you want to go now, Mr Black?\n");
        UI.typeText("Current Location: "); UI.typeText(map[currentMap].GetName());
        cout << endl;

        for (int i = 0; i < (int)option.size(); i++) {
            cout << "(" << i + 1 << ") "; 
            UI.typeText(map[option[i]].GetName());
            cout << endl;
        }

        int choice;
        cin >> choice;

        if (choice >= 0 && choice <= (int)option.size()) {

            int destination = option[choice - 1];
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
            UI.typeText("Invalid Choice!");
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

void CGameManager::TestDialogue() {
    UI.RenderDialougeBox("Game", "Detective black Sits in his chair as he chainsmokes a cigar");
    UI.RenderDialougeBox("Game", "Like its another one of his noir movies that he larps");
    UI.RenderDialougeBox("Game", "One more and Cancer is calling his name but whatever");
    UI.RenderDialougeBox("Game", "Its been a while since the poor man has gotten a case");
    UI.RenderDialougeBox("Game", "One more cigar and the only thing calling him will be bankrupcy");
    UI.RenderDialougeBox("Game", "Oh whats that. why its his equally good for nothing assistant");
    UI.RenderDialougeBox("Game", "Maybe its a case, maybe not. Oh i wonder");
    map[currentMap].RenderMap();
}

void CGameManager::RunGame() {
    map[currentMap].RenderMap();
    TestDialogue();
    while (IsGameRunning) {
        char input = _getch();

        if (input == 'p') {
            bool keepPlaying = UI.PauseMenu();
            if (!keepPlaying) {
                IsGameRunning = false;
            }
            else {
                map[currentMap].RenderMap();
            }
            continue;
        }

        if (input == 'i') {
            inventory.showInventory(input);
            if (!inventory.getInventoryState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        if (inventory.getInventoryState() == false) {
            changeMaps(input);
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