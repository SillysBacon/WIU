#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "CPlayer.h"
using namespace std;
class CMap
{
	static const int MAX_SIZE = 100;
	int MAP_SIZE_X;
	int MAP_SIZE_Y;
	char MAP[MAX_SIZE][MAX_SIZE];
	CPlayer* player;
public:
	void SetMap();
	void SetPosition();
	void removePosition(int x, int y);
	void RenderMap();
	void SetMAP_SIZE(int size_x, int size_y);
	void SetRoom(int map_size_x , int map_size_y);
	void Movement(char input);
	char GetMap();
	CPlayer* GetPlayer();
	~CMap();
	CMap();
};

