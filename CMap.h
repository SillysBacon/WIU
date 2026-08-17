#pragma once
#include <string>
#include <iostream>
using namespace std;
class CMap
{
	static const int MAX_SIZE = 100;
	int MAP_SIZE;
	char MAP[MAX_SIZE][MAX_SIZE];
public:
	void SetMap();
	void RenderMap();
	void SetMAP_SIZE(int size);
	void SetRoom(int map_size);
	CMap();
};

