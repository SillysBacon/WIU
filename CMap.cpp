#include "CMap.h"
void CMap::SetMAP_SIZE(int size) {
	MAP_SIZE = size;
}

void CMap::SetMap() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			MAP[i][j] = '\0';
		}
	}
}

void CMap::RenderMap() {
	for (int i = 0; i < MAP_SIZE; i++) {
		cout << endl;
		for (int j = 0; j < MAP_SIZE;j++) {
			switch (MAP[i][j]) {
			case '\0':
				cout << " .";
			}
		}
	}
}

void CMap::SetRoom(int map_size) {
	SetMAP_SIZE(map_size);
	SetMap();
	RenderMap();
}

CMap::CMap() {

}