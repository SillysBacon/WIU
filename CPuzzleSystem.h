#pragma once
#include "CEvidence.h"
#include "CUI.h"

class PuzzleSystem
{
	string puzzleType;
	bool puzzleCompleted;
	bool puzzleRunning;
	CEvidence evidence;
	string userAnswer;
	int userAnswerInt;
	int numberPosition;

public:
	void startPuzzles();
	void renderPuzzles(string puzzle);
	void renderNumber(int num);
	void changeNum(int input);
	string getCipher();
	string getRiddles();
	int getLock();

	PuzzleSystem();
};

