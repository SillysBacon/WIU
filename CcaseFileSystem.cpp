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
	if (discoveredDocument.empty()) {

		cout << "#=============================#" << endl << endl;
		cout << "No documents added yet" << endl << endl;
		cout << "#=============================#";

	}
	else
	{
		cout << "             " << currentFiles + 1 << " / " << discoveredDocument.size() << endl;
		cout << "#=============================#" << endl;
		cout << discoveredDocument[currentFiles] << endl << endl << "Description:" << endl; //still need getDoc func here for push
		cout << "#=============================#";
	}
	
}

void CcaseFileSystem::renderEvidenceFiles() {
	CUI::GetInstance().Clear();
	if (discoveredEvidence.empty()) {

		cout << "#=============================#" << endl << endl;
		cout << "No evidences collected yet" << endl << endl;
		cout << "#=============================#";

	}
	else
	{
		cout << "             " << currentEvidenceFiles + 1 << " / " << discoveredEvidence.size() << endl;
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
		cout << "#=============================#" << endl << endl;
		cout << "No suspect yet" << endl << endl;
		cout << "#=============================#";
	}
	else
	{
		cout << "             " << currentSuspectFiles + 1 << " / " << discoveredSuspect.size() << endl;
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
	for (CEvidence& e : discoveredEvidence) {
		if (e.getEvidence() == type) {
			return;
		}
	}
	CEvidence e;
	e.SetEvidence(type);
	e.SetFound(true);
	discoveredEvidence.push_back(e);

}

void CcaseFileSystem::addSuspect(NPC::People name)
{
	for (NPC& p : discoveredSuspect) {
		if (p.getPerson() == name) {
			return;
		}
	}
	NPC p;
	p.setPerson(name);
	discoveredSuspect.push_back(p);
}

void CcaseFileSystem::addDocument()
{
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