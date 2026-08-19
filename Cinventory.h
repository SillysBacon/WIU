#pragma once
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class inventorySystem
{
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

