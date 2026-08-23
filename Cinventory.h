#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "CUI.h";
using namespace std;

class inventorySystem
{
	int static const MAX_ITEMS = 15;
	int InventoryIDS[MAX_ITEMS];
	string inventorySpace[MAX_ITEMS];
	int ItemCount = 0;
	int itemPosition = 0;
	bool isInventoryOpen = false;
public:
	void renderInventory();
	void showInventory(char input);
	void addToInventory(string item, int id);
	void switchItem(int input);
	bool getInventoryState();
};