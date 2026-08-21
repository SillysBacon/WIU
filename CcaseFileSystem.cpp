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
		if (currentView == CFSView::EVIDENCE && currentEvidenceFiles < (int)discoveredEvidence.size() - 1) {
			currentEvidenceFiles++;
		}
		else if (currentView == CFSView::SUSPECT && currentSuspectFiles < (int)discoveredSuspect.size() - 1) {
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
	if (discoveredEvidence.empty()) {

		cout << "             " << currentEvidenceFiles + 1 << " / " << currentEvidenceFiles + 1 << endl;
		cout << "#=============================#" << endl << endl;
		cout << "No evidences collected yet" << endl << endl;
		cout << "#=============================#";

	}
	else
	{
		cout << "             " << currentEvidenceFiles + 1 << " / " << currentEvidenceFiles + 1 << endl;
		cout << "#=============================#" << endl;
		cout << discoveredEvidence[currentEvidenceFiles].GetName() << endl << endl << "Description:" << endl;
		//cout << discoveredEvidence[currentEvidenceFiles].Get << endl;
		cout << "#=============================#";
	}
}

void CcaseFileSystem::renderSuspectFiles()
{
	CUI::GetInstance().Clear();
	if (discoveredSuspect.empty()) {
		cout << "             " << currentSuspectFiles + 1 << " / " << currentSuspectFiles + 1 << endl;
		cout << "#=============================#" << endl << endl;
		cout << "No suspect yet" << endl << endl;
		cout << "#=============================#";
	}
	else
	{
		cout << "             " << currentSuspectFiles + 1 << " / " << currentSuspectFiles + 1 << endl;
		cout << "#=============================#" << endl;
		cout << discoveredSuspect[currentSuspectFiles].getName() << endl;
		cout << "Age: " << discoveredSuspect[currentSuspectFiles].getAge() << endl;
		cout << "Occupation: " << discoveredSuspect[currentSuspectFiles].getOccupation() << endl;
		//cout << "Description: " << endl;
		cout << "#=============================#";
	}
}

void CcaseFileSystem::addEvidence(CEvidence::Evidence type)
{
	CEvidence e;
	e.SetEvidence(type);
	e.SetFound(true);
	discoveredEvidence.push_back(e);

}

void CcaseFileSystem::addSuspect(NPC::People name)
{
	NPC p;
	p.setPerson(name);
	discoveredSuspect.push_back(p);
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