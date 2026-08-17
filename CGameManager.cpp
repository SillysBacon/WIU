#include "CGameManager.h"

CGameManager::CGameManager() {
	map.SetRoom(12);
	for (int i = 0; i < 100; i++) {
		map.Movement();

	}
}