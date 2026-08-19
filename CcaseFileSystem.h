#pragma once
#include <iostream>
#include <string>
using namespace std;
class CcaseFileSystem
{
	string const suspectFiles[5] = {"Person 1","Person 2","Person 3","Person 4","Person 5"};
	string const suspectDescription[5] = {"Description 1","Description 2","Description 3","Descriptoin 4","Description 5"};
	int currentFiles = 0;
	bool isCFSOpen = false;
public:
	void changeFiles(int input);
	void renderFiles();
	void showFiles(char input);
	bool getCFSState();
};

