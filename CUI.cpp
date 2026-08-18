#include "CUI.h"
#include <conio.h>
#include <stdlib.h>

void CUI::delayMs(int ms) {
    clock_t start = std::clock();
    while ((std::clock() - start) * 1000 / CLOCKS_PER_SEC < ms) {}
}

void CUI::typeText(const string text) {
    for (char c : text) {
        cout << c << std::flush;
        delayMs(textSpeed);
    }
}

void CUI::RenderSettings() {
    system("cls");
    cout << "       [SETTINGS]\n";
    cout << "+------------------------+\n";
    for (int i = 0; i < MaxSetting; i++) {
        if (i == SettingPos) {
            cout << "-> " << Settings[i] << endl << endl;
        }
        else {
            cout << "   " << Settings[i] << endl << endl;
        }
    }
    cout << "+------------------------+\n";
}

void CUI::SwitchSetting(int input) {
    if (input == 72) {
        if (SettingPos > 0) {
            SettingPos -= 1;
        }
    }
    else if (input == 80) {
        if (SettingPos < MaxSetting - 1) {
            SettingPos += 1;
        }
    }
}

void CUI::RenderDialougeBox(const string character, const string text) {
    string fullLine = character + ": " + text;
    int boxWidth = (int)fullLine.length() + 6;
    cout << "+" << std::string(boxWidth - 2, '-') << "+\n";
    cout << "|  ";
    typeText(fullLine);
    cout << "  |\n";
    cout << "+" << std::string(boxWidth - 2, '-') << "+\n";
}

void CUI::SetTextSpeed(int speed) {
    textSpeed = speed;
}

void CUI::DisplayTextSpeedSettings() {
    system("cls");
    cout << "       [Text Speed]\n";
    cout << "+------------------------+\n";
    cout << "          < " << textSpeed << " >";
}

void CUI::ChangeSpeed(char input) {
    if (input == 77 && textSpeed < 50) {
        textSpeed += 10;
    }
    else if (input == 75 && textSpeed > 10) {
        textSpeed -= 10;
    }
}

void CUI::HandleArrow(int input) {
    if (isSpeedSettingOpen) {
        ChangeSpeed((char)input);
        DisplayTextSpeedSettings();
    }
    else if (isSettingsOpen) {
        SwitchSetting(input);
        RenderSettings();
    }
    else if (isStartMenuOpen) {
        SwitchStartMenuOption(input);
        RenderStartMenu();
    }
}

void CUI::HandleEnter() {
    if (isSpeedSettingOpen) {
        isSpeedSettingOpen = false;
        isSettingsOpen = true;
        RenderSettings();
        return;
    }

    if (isStartMenuOpen) {
        switch (StartMenuPos) {
        case 0:
            isStartMenuOpen = false;
            Settings[MaxSetting -1] = "Resume Game";
            break;
        case 1:
            isStartMenuOpen = false;
            isSettingsOpen = true;
            RenderSettings();
            break;
        case 2:
            isRunning = false;
            break;
        }
        return;
    }

    if (isSettingsOpen) {
        switch (SettingPos) {
        case 0:
            isSettingsOpen = false;
            isSpeedSettingOpen = true;
            DisplayTextSpeedSettings();
            break;
        case 1:
            isSettingsOpen = false;
            isStartMenuOpen = true;
            RenderStartMenu();
            break;
        case 2:
            isRunning = false;
            break;
        }
    }
}

void CUI::Run() {
    while (isRunning) {
        int input = _getch();

        if (input == 0 || input == 224) {
            input = _getch();
            HandleArrow(input);
        }
        else if (input == 13) {
            HandleEnter();
        }
    }
}

void CUI::RenderStartMenu() {
    system("cls");
    string title = "A Liar's Paradox";
    int boxWidth = (int)title.length() + 6;
    cout << "+" << std::string(boxWidth - 2, '-') << "+\n";
    cout << "|  ";
    cout << title;
    cout << "  |\n";
    cout << "+" << std::string(boxWidth - 2, '-') << "+\n";


    for (int i = 0; i < MaxStartOptions; i++) {
        if (i == StartMenuPos) {
            cout << "   ~> " << StartMenuOptions[i] << endl << endl;
        }
        else {
            cout << "      " << StartMenuOptions[i] << endl << endl;
        }
    }
}

void CUI::SwitchStartMenuOption(int input) {
    if (input == 72) {
        if (StartMenuPos > 0) {
            StartMenuPos -= 1;
        }
    }
    else if (input == 80) {
        if (StartMenuPos < MaxStartOptions - 1) {
            StartMenuPos += 1;
        }
    }
}


CUI::CUI() {
    SetTextSpeed(30);
    SettingPos = 0;
    StartMenuPos = 0;
    isStartMenuOpen = true;
    isSettingsOpen = false;
    isSpeedSettingOpen = false;
    RenderStartMenu();
}