#include "CcaseFileSystem.h"

void CcaseFileSystem::changeFiles(int input) {
	if (input == 77 && currentFiles < 4) {
		currentFiles++;
	}
	else if (input == 75 && currentFiles > 0) {
		currentFiles--;
	}
}

void CcaseFileSystem::renderFiles() {
	system("cls");
	cout << "             " << currentFiles + 1 << " / 5" << endl;
	cout << "#=============================#" << endl;
	cout << suspectFiles[currentFiles] << endl << endl << "Description:" << endl;
	cout << suspectDescription[currentFiles] << endl;
	cout << "#=============================#";
}

void CcaseFileSystem::showFiles(char input) {
	if (input == 'c') {
		isCFSOpen = !isCFSOpen;
	}
	if (isCFSOpen) {
		renderFiles();
	}
}

bool CcaseFileSystem::getCFSState() {
	return isCFSOpen;
}