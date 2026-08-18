#include "CGameManager.h"

CGameManager::CGameManager() {
	map.SetRoom(25,10);
	for (int i = 0; i < 100; i++) {
		map.Movement();

	}
}