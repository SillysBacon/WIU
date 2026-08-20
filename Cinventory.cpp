#include "Cinventory.h"

void inventorySystem::renderInventory() {
	UI.Clear();
	cout << "       [Inventory]\n";
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~+\n";
	for (int i = 0; i < maxItem; i++) {
		if (i == itemPosition) {
			cout << "~> " << inventorySpace[i] << endl;
		}
		else {
			cout << "   " << inventorySpace[i] << endl;
		}
	}
	cout << "+~~~~~~~~~~~~~~~~~~~~~~~~+\n";
}

void inventorySystem::showInventory(char input) {
	if (input == 'i') {
		isInventoryOpen = !isInventoryOpen;
	}
	if (isInventoryOpen) {
		renderInventory();
	}
}

void inventorySystem::addToInventory(string item) {
	inventorySpace[maxItem] = item;
	maxItem++;
}

void inventorySystem::switchItem(int input) {
	if (input == 72) {
		if (itemPosition > 0) {
			itemPosition -= 1;
		}
	}
	else if (input == 80) {
		if (itemPosition < maxItem - 1) {
			itemPosition += 1;
		}
	}
}

bool inventorySystem::getInventoryState() {
	return isInventoryOpen;
}