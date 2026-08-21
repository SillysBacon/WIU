#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "CGameObject.h"
#include "CEvidence.h"
class CObstacle :
    public CGameObject
{
public:
    enum Furniture
    {
        Table,
        Desk,
        Small_Shelf,
        Long_Shelf,
        Sofa,
        Chair,
        Door,
        Window,
        Flower,
        Tree,
        Bed,
        ToiletBowl,
        BathTub,
        Sink
    };
    void SetType(Furniture f);
    void Rotate();
    int GetWidth();
    int GetHeight();
    char GetSymbol();
    Furniture GetType();
    string GetNextDialouge();
    void SetDialogue(int index, const string text);
    string runDialogue(CEvidence::Evidence, int num);
    string GetEvidenceName(CEvidence::Evidence e);
    CObstacle();

private:
    Furniture type;
    int width, height;
    char symbol;
    string IDialouge[3];
    int dialougeidx;
    CEvidence EvidenceIdx;
    int EvidenceDialogueIdx;


    //Placeholders for later;
    bool isKeyObject = false;
    void SetKeyObject(bool val);
    bool IsKeyObject();

};

