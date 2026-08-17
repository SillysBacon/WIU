#include "CMap.h"

void CMap::SetMAP_SIZE(int size) {
	MAP_SIZE = size;
}
int CMap::GetMAP_SIZE() {
	return MAP_SIZE;
}
void CMap::SetMap() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			MAP[i][j] = '\0';
		}
	}
}
void CMap::SetPosition() {
	MAP[player.GetPosY()][player.GetPosX()] = 'd';
}

void CMap::RenderMap() {
	for (int j = 0; j < MAP_SIZE; j++) {
		cout << "__";
	}
	cout << "__" << endl;
	for (int i = 0; i < MAP_SIZE; i++) {
		cout << "|";
		for (int j = 0; j < MAP_SIZE; j++) {
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
	for (int j = 0; j < MAP_SIZE; j++) {
		cout << "--";
	}
	cout << "--" << endl;
}
void CMap::Movement() {
	char input = _getch();
	MAP[player.GetPosY()][player.GetPosX()] = '\0';
	player.SetlastInput(input);
	player.Move(MAP, MAP_SIZE);
	SetPosition();
	RenderMap();
}

void CMap::SetRoom(int map_size) {
	SetMAP_SIZE(map_size);
	SetMap();
	SetPosition();
	RenderMap();
}

CMap::CMap() {
	SetMap();
	MAP_SIZE = 0;

}