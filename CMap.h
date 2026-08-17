#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "CPlayer.h"
using namespace std;
class CMap
{
	static const int MAX_SIZE = 100;
	int MAP_SIZE;
	char MAP[MAX_SIZE][MAX_SIZE];
	CPlayer player;
public:
	void SetMap();
	void SetPosition();
	void RenderMap();
	void SetMAP_SIZE(int size);
	int GetMAP_SIZE();
	void SetRoom(int map_size);
	void Movement();
	CMap();
};

