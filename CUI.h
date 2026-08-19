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
	string Settings[MaxSetting] = { "Change Text Speed", "Return to Start Menu", "Exit to Desktop" };
	bool GameStart;
	bool isRunning = true;
	void HandleArrow(int input);
	void HandleEnter();
	int StartMenuPos;
	string StartMenuOptions[MaxStartOptions] = { "Start Game", "Settings", "Leave Game" };
	bool isStartMenuOpen = true;

	int const static MaxPauseOptions = 3;
	string PauseMenuOptions[MaxPauseOptions] = { "Continue", "Settings", "Exit" };
	int PauseMenuPos;
	bool isPauseMenuOpen;
	bool isPauseLoopActive;
	bool PausedFromGame;
	bool ExitToDesktop;





public:
	void RenderStartMenu();
	void SwitchStartMenuOption(int input);
	bool GetGameStart();
	static void delayMs(int ms);
	void SetTextSpeed(int speed);
	void typeText(const string text);
	void NextDialouge();
	void RenderDialougeBox(const string character, const string text);
	void RenderSettings();
	void DisplayTextSpeedSettings();
	void ChangeSpeed(char input);
	void SwitchSetting(int input);
	void Run();



	void RenderPauseMenu();
	void SwitchPauseMenuOption(int input);
	bool PauseMenu();


	CUI();

};