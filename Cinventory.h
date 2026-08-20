#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "CUI.h";
using namespace std;

class inventorySystem
{
	CUI UI;
	string inventorySpace[10] = {"A","B","C","D","y"};
	int maxItem = 5;
	int itemPosition = 0;
	bool isInventoryOpen = false;
public:
	void renderInventory();
	void showInventory(char input);
	void addToInventory(string item);
	void switchItem(int input);
	bool getInventoryState();
};

