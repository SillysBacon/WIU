#include "CMap.h"

void CMap::SetMAP_SIZE(int size_x, int size_y) {
	MAP_SIZE_X = size_x;
	MAP_SIZE_Y = size_y;
}
CPlayer* CMap::GetPlayer(){
    return player;
}
char CMap::GetItem(int x, int y) {
    char item;

    if (MAP[x][y + 1] != ' ') {
        item = MAP[x][y + 1];
        MAP[x][y + 1] == '\0';
    }
    else if (MAP[x + 1][y] != ' ') {
        item = MAP[x + 1][y];
        MAP[x + 1][y] == '\0';
    }
    else if (MAP[x][y - 1] != ' ') {
        item = MAP[x][y - 1];
        MAP[x][y - 1] == '\0';
    }
    else if (MAP[x - 1][y] != ' ') {
        item = MAP[x - 1][y];
        MAP[x - 1][y] == '\0';
    }
    else {
        item = ' ';
    }
    return item;
}
void CMap::SetMap() {
	for (int i = 0; i < MAP_SIZE_X; i++) {
		for (int j = 0; j < MAP_SIZE_Y; j++) {
			MAP[i][j] = '\0';
		}
	}
}
void CMap::SetPosition() {
	MAP[player->GetPosY()][player->GetPosX()] = 'd';
}

void CMap::removePosition(int y, int x) {
    MAP[y][x] = '\0';
}

void CMap::RenderMap() {
    int width = 2 * MAP_SIZE_X + 2;
    system("cls");

    for (int j = 0; j < width; j++) {
        cout << "=";
    }
    cout << endl;

    for (int i = 0; i < MAP_SIZE_Y; i++) {
        cout << "|";
        for (int j = 0; j < MAP_SIZE_X; j++) {
            switch (MAP[i][j]) {
            case 'd':
                cout << " D";
                break;
            default:
                cout << "  ";
                break;
            }
        }
        cout << "|" << endl;
    }

    for (int j = 0; j < width; j++) {
        cout << "=";
    }
    cout << endl;
}
void CMap::Movement(char input) {
    MAP[player->GetPosY()][player->GetPosX()] = '\0';
    player->SetlastInput(input);
    player->Move(MAP, MAP_SIZE_X, MAP_SIZE_Y);
    SetPosition();
    RenderMap();
}

void CMap::SetRoom(int map_size_x, int map_size_y) {
	SetMAP_SIZE(map_size_x, map_size_y);
	SetMap();
	SetPosition();
	RenderMap();
}

CMap::~CMap() {
    delete player;
}

CMap::CMap() {
    player = new CPlayer();
	SetMap();
	MAP_SIZE_X = 0;
	MAP_SIZE_Y = 0;

}