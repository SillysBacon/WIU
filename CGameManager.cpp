#include "CGameManager.h"

void CGameManager::SetMaps() {
    map[0].SetRoom(10, 6);
    map[1].SetRoom(6, 10);
}
//KAI XIN change this part for the change map mechanic
void CGameManager::changeMaps(char input)
{
    if (input == 'f') {
        map[currentMap].removePosition(
            map[currentMap].GetPlayer()->GetPosY(),
            map[currentMap].GetPlayer()->GetPosX()
        );
        if (currentMap == 0) {
            currentMap = 1;
        }
        else {
            currentMap = 0;
        }
        map[currentMap].GetPlayer()->SetPosX(0);
        map[currentMap].GetPlayer()->SetPosY(0);
        map[currentMap].SetPosition();
        map[currentMap].RenderMap();
    }
    else {
        map[currentMap].Movement(input);
    }
}

CGameManager::CGameManager() {
    currentMap = 0;
    SetMaps();
    map[currentMap].RenderMap();

    for (int i = 0; i < 100; i++) {
        char input = _getch();
        changeMaps(input);
    }
}