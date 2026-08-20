#pragma once
#include "CObject.h"
class CEvidence :
    public CObject
{

public:
    enum Evidence {
        Brass_Candlestick,
        Broken_Whiskey_Bottle,
        Gunpowder_Ziploc,
        Suspicious_Glove,
        BrokenWhiskey_Bottle_Report,
        Brass_Candlestick_Report,
        Suspicious_Glove_Report,
        Picture_of_Muddy_shoeprint,
        Shoebox_of_property_Photos,
        Bank_Statement,
        Divorce_Papers,
    };
    void SetEvidence(Evidence E);
    void runDialogue(int num, string dialogue);
    void placeEvidence(int x, int y);
    bool GetFound();
    void SetFound(bool find);
    void SetName(string namegive);
    string GetName();
    void createEvidence();
    CEvidence(string Name);
    CEvidence();

private:

    string Dialogue;
    Evidence type;
    string name;
    bool found;

};

