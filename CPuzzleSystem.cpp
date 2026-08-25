#include "CPuzzleSystem.h"

void PuzzleSystem::renderPuzzles(string puzzle) {
	if (puzzle == "cipher") {
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|              CIPHER PUZZLE               |" << endl;
		cout << "|  DECODE THE FOLLOWING ENCRYPTED MESSAGE  |" << endl;
		cout << "|                                          |" << endl;
		cout << "|                 KPCVYJL                  |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		cout << "Decypher this message: ";
		cin >> userAnswer;
		if (userAnswer == "DIVORCE") {
			// Give evidence
			puzzleCompleted = true;
		}
		else {
			cout << "Seems like that didn't work..." << endl;
		}
	}
	else if (puzzle == "riddle") {
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|              RIDDLE PUZZLE               |" << endl;
		cout << "|       ANSWER THE FOLLOWING RIDDLE        |" << endl;
		cout << "|                                          |" << endl;
		cout << "|  I help you wave and hold things tight,  |" << endl;
		cout << "| five curious helpers fill me with light. |" << endl;
		cout << "| A cozy covering keeps me warm all night. |" << endl;
		cout << "|               What am I?                 |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		cout << "Answer: ";
		cin >> userAnswer;
		if (userAnswer == "GLOVE") {
			// Give evidence
			puzzleCompleted = true;
		}
		else {
			cout << "Ugh, can't figure out what this means...";
		}
	}
	else if (puzzle == "lock") {
		CUI::GetInstance().Clear();
		renderNumber(numberPosition);
		cout << "Your answer: ";
		cin >> userAnswerInt;
		if (userAnswerInt == 1234) {
			// Give evidence
			puzzleCompleted = true;
		}
		else {
			cout << "Well that didn't seem to work...";
		}
	}
}

void PuzzleSystem::renderNumber(int num) {
	switch (num) {
	case 0:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     0000000000     >          |" << endl;
		cout << "|        <<<     000    000     >>>        |" << endl;
		cout << "|     <<<<<<     000    000     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<     000    000     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<     000    000     >>>>>>     |" << endl;
		cout << "|        <<<     000    000     >>>        |" << endl;
		cout << "|          <     0000000000     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 1:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <        1111        >          |" << endl;
		cout << "|        <<<      111111        >>>        |" << endl;
		cout << "|     <<<<<<     111 111        >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<         111        >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<         111        >>>>>>     |" << endl;
		cout << "|        <<<         111        >>>        |" << endl;
		cout << "|          <     1111111111     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 2:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <        2222        >          |" << endl;
		cout << "|        <<<      222  222      >>>        |" << endl;
		cout << "|     <<<<<<     222    222     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<           222      >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<         222        >>>>>>     |" << endl;
		cout << "|        <<<       222          >>>        |" << endl;
		cout << "|          <     2222222222     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 3:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     3333333333     >          |" << endl;
		cout << "|        <<<     333    333     >>>        |" << endl;
		cout << "|     <<<<<<            333     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<           333      >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<            333     >>>>>>     |" << endl;
		cout << "|        <<<     333    333     >>>        |" << endl;
		cout << "|          <     3333333333     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 4:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     444    444     >          |" << endl;
		cout << "|        <<<     444    444     >>>        |" << endl;
		cout << "|     <<<<<<     444    444     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<     444    444     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<     4444444444     >>>>>>     |" << endl;
		cout << "|        <<<            444     >>>        |" << endl;
		cout << "|          <            444     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 5:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     5555555555     >          |" << endl;
		cout << "|        <<<     555            >>>        |" << endl;
		cout << "|     <<<<<<     555555555      >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<     555    555     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<            555     >>>>>>     |" << endl;
		cout << "|        <<<     555    555     >>>        |" << endl;
		cout << "|          <      55555555      >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 6:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <    66666666666     >          |" << endl;
		cout << "|        <<<    666             >>>        |" << endl;
		cout << "|     <<<<<<    666             >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<    66666666666     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<    666     666     >>>>>>     |" << endl;
		cout << "|        <<<    666     666     >>>        |" << endl;
		cout << "|          <    66666666666     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 7:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     7777777777     >          |" << endl;
		cout << "|        <<<            777     >>>        |" << endl;
		cout << "|     <<<<<<           777      >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<          777       >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<         777        >>>>>>     |" << endl;
		cout << "|        <<<        777         >>>        |" << endl;
		cout << "|          <       777          >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 8:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     8888888888     >          |" << endl;
		cout << "|        <<<     888    888     >>>        |" << endl;
		cout << "|     <<<<<<     888    888     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<     8888888888     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<     888    888     >>>>>>     |" << endl;
		cout << "|        <<<     888    888     >>>        |" << endl;
		cout << "|          <     8888888888     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	case 9:
		cout << "#==========================================#" << endl;
		cout << "|                                          |" << endl;
		cout << "|             COMBINATION LOCK             |" << endl;
		cout << "|    ENTER THE CORRECT NUMBER TO UNLOCK    |" << endl;
		cout << "|                                          |" << endl;
		cout << "|          <     9999999999     >          |" << endl;
		cout << "|        <<<     999    999     >>>        |" << endl;
		cout << "|     <<<<<<     999    999     >>>>>>     |" << endl;
		cout << "|  <<<<<<<<<     9999999999     >>>>>>>>>  |" << endl;
		cout << "|     <<<<<<            999     >>>>>>     |" << endl;
		cout << "|        <<<     999    999     >>>        |" << endl;
		cout << "|          <     9999999999     >          |" << endl;
		cout << "|                                          |" << endl;
		cout << "#==========================================#" << endl;
		break;
	}
}

void PuzzleSystem::changeNum(int input) {
	if (input == 77 && numberPosition < 10) {
		numberPosition++;
	}
	else if (input == 75 && numberPosition > 0) {
		numberPosition--;
	}
}

PuzzleSystem::PuzzleSystem() {
	puzzleType = "";
	userAnswer = "";
	userAnswerInt = 0;
	puzzleCompleted = false;
	puzzleRunning = false;
	numberPosition = 0;
}