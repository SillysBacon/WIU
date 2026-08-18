#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class CUI
{
	int textSpeed;
	int PlayerColor;
	bool isSettingsOpen;
	bool isSpeedSettingOpen;
	int SettingPos;
	int const static MaxSetting = 3;
	int const static MaxStartOptions = 3;
	string Settings[MaxSetting] = { "Change Text Speed", "Return to Start Menu", "Exit Game" };

	bool isRunning = true;

	void HandleArrow(int input);
	void HandleEnter();

	int StartMenuPos;
	string StartMenuOptions[MaxStartOptions] = { "Start Game", "Settings", "Exit" };
	bool isStartMenuOpen = true; // this is now the default screen

public:
	void RenderStartMenu();
	void SwitchStartMenuOption(int input);


	static void delayMs(int ms);
	void SetTextSpeed(int speed);
	void typeText(const string text);
	void RenderDialougeBox(const string character, const string text);
	void RenderSettings();
	void DisplayTextSpeedSettings();
	void ChangeSpeed(char input);
	void SwitchSetting(int input);
	CUI();

	void Run();
};