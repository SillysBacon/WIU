#pragma once
#include <iostream>
#include <string>
#include "CUI.h";
using namespace std;
class CcaseFileSystem
{
	enum CFSView {
		DOCUMENT,
		EVIDENCE,
		SUSPECT,
		NOTES
	};

	CFSView currentView = CFSView::DOCUMENT;

	string const suspectFiles[5] = {"Person 1","Person 2","Person 3","Person 4","Person 5"};
	string const suspectDescription[5] = {"Description 1","Description 2","Description 3","Description 4","Description 5"};
	string const evidenceFiles[11] = { "Evidence 1", "Evidence 2" ,"Evidence 3" ,"Evidence 4" ,"Evidence 5" ,"Evidence 6" ,
										"Evidence 7" ,"Evidence 8" ,"Evidence 9" ,"Evidence 10" ,"Evidence 11" };
	string const evidenceDescription[11] = { "Description 1", "Description 2" ,"Description 3" ,"Description 4" ,"Description 5" ,"Description 6" ,
										"Description 7" ,"Description 8" ,"Description 9" ,"Description 10" ,"Description 11" };
	string const documentFiles[3] = { "Document 1","Document 2","Document 3"};
	string const documentDescription[3] = { "Description 1","Description 2","Description 3"};

	int currentFiles = 0;
	int currentEvidenceFiles = 0;
	int currentSuspectFiles = 0;
	bool isCFSOpen = false;
	string notes[5][100] = {{"No notes currently...", ""}, {"No notes currently...", ""}, {"No notes currently...", ""}, {"No notes currently...", ""}, 
	{ "No notes currently...", "" } };
	int currentNotes[5] = {1, 1, 1, 1, 1};

public:
	void changeFiles(int input);
	void renderEvidenceFiles();
	void renderSuspectFiles();
	void renderFiles();
	void renderNotes();
	void showFiles(char input);
	bool getCFSState();
	void addNotes();

};

