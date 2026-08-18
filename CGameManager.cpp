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
//KAI XIN change this part for the change map mechanic
void CGameManager::changeMaps(char input)
{
    if (input == 'm') {

        std::vector<int>& option = Connect[currentMap];

        std::cout << "\n Where do you want to go now, Mr Black?\n";
        std::cout << "Current Location: " << map[currentMap].GetName() << endl;

        for (int i = 0; i < (int)option.size(); i++) {
            std::cout << "(" << i + 1 << ")" << map[option[i]].GetName() << std::endl;
        }

        int choice;
        std::cin >> choice;

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

            std::cout << "You are now at " << map[currentMap].GetName() << "." << std::endl;
        }

        else {
            std::cout << "Invalid Choice!";
        }
    }
    else if (input == 'e') {
        char object;
        object = map[0].GetItem(map[currentMap].GetPlayer()->GetPosX(), map[currentMap].GetPlayer()->GetPosY());
        std::cout << object << '\n';
    }
    else if (input == 'f') {
        char npc;
        npc = map[0].GetItem(map[currentMap].GetPlayer()->GetPosX(), map[currentMap].GetPlayer()->GetPosY());
    }
    else {
        map[currentMap].Movement(input);
    }
}

CGameManager::CGameManager() {
    currentMap = 0;
    currentUI = 0;
    SetMaps();
    map[currentMap].RenderMap();

    for (int i = 0; i < 100; i++) {
        char input = _getch();

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