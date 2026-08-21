#include "CcaseFileSystem.h"

void CcaseFileSystem::changeFiles(int input) {

	switch (input) {
	case '1':
		currentView = CFSView::DOCUMENT;
		break;
	case '2':
		currentView = CFSView::EVIDENCE;
		break;
	case '3':
		currentView = CFSView::SUSPECT;
		break;
	case 77:
		if (currentView == CFSView::EVIDENCE && currentEvidenceFiles < 10) {
			currentEvidenceFiles++;
		}
		else if (currentView == CFSView::SUSPECT && currentSuspectFiles < 4) {
			currentSuspectFiles++;
		}
		else if (currentFiles < 2) {
			currentFiles++;
		}
		break;
	case 75:
		if (currentView == CFSView::EVIDENCE && currentEvidenceFiles > 0) {
			currentEvidenceFiles--;
		}
		else if (currentView == CFSView::SUSPECT && currentSuspectFiles > 0) {
			currentSuspectFiles--;
		}
		else if (currentFiles > 0) {
			currentFiles--;
		}
		break;
	case 'n':
		if (currentView == CFSView::SUSPECT) {
			addNotes();
		}
	}

	
}

void CcaseFileSystem::renderFiles() {

	switch (currentView) {
	case CFSView::EVIDENCE:
		renderEvidenceFiles();
		return;
		break;
	case CFSView::SUSPECT:
		renderSuspectFiles();
		return;
		break;
	case CFSView::DOCUMENT:
		break;
	}

	CUI::GetInstance().Clear();
	cout << "             " << currentFiles + 1 << " / 3" << endl;
	cout << "#=============================#" << endl;
	cout << documentFiles[currentFiles] << endl << endl << "Description:" << endl;
	cout << documentDescription[currentFiles] << endl;
	cout << "#=============================#";
	
}

void CcaseFileSystem::renderEvidenceFiles() {
	CUI::GetInstance().Clear();
	cout << "             " << currentEvidenceFiles + 1 << " / 11" << endl;
	cout << "#=============================#" << endl;
	cout << evidenceFiles[currentEvidenceFiles] << endl << endl << "Description:" << endl;
	cout << evidenceDescription[currentEvidenceFiles] << endl;
	cout << "#=============================#";
}

void CcaseFileSystem::renderSuspectFiles()
{
	CUI::GetInstance().Clear();
	cout << "             " << currentSuspectFiles + 1 << " / 5" << endl;
	cout << "#=============================#" << endl;
	cout << suspectFiles[currentSuspectFiles] << endl << endl << "Description:" << endl;
	cout << suspectDescription[currentSuspectFiles] << endl;
	cout << "Notes:" << endl << notes[currentSuspectFiles][currentNotes[currentSuspectFiles] - 1] << endl;
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

void CcaseFileSystem::addNotes() {
	CUI::GetInstance().Clear();
	string notesText;
	cout << "What's on your mind, Mr Black?: ";
	getline(cin, notesText);
	notes[currentSuspectFiles][currentNotes[currentSuspectFiles]] = notesText;
	currentNotes[currentSuspectFiles]++;
	renderSuspectFiles();
	
}

void CcaseFileSystem::renderNotes() {

}