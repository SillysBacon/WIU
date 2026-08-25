#include "CEvidence.h"

void CEvidence::SetEvidence(Evidence E){
	type = E;

	switch (E) {
	case Brass_Candlestick:
		name = "Brass Candlestick";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Broken_Whiskey_Bottle:
		name = "Broken Whiskey Bottle";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Gunpowder_Ziploc:
		name = "Gunpowder Ziploc";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Suspicious_Glove:
		name = "Suspicious Glove";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case BrokenWhiskey_Bottle_Report:
		name = "BrokenWhiskey Bottle Report";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Brass_Candlestick_Report:
		name = "Brass Candlestick Report";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Suspicious_Glove_Report:
		name = "Suspicious Glove Report";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Picture_of_Muddy_shoeprint:
		name = "Picture of Muddy shoeprint";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Shoebox_of_property_Photos:
		name = "Shoebox of Property Photos";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Bank_Statement:
		name = "Bank Statement";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;
	case Divorce_Papers:
		name = "Divorce Papers";
		Dialogue[0] = "Hmm, what's this? Looks like blood,” black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		length = 4;
		break;

	}
}

string CEvidence::GetDialogue(int num)
{
	return string(Dialogue[num]);
}

void CEvidence::placeEvidence(int x, int y){
	SetPosX(x);
	SetPosY(y);
}

bool CEvidence::GetFound(){
	return true;
}

void CEvidence::SetFound(bool find){
	found = find;
}

void CEvidence::SetName(string namegive){
	name = namegive;
}

string CEvidence::GetName(){
	return string(name);
}

void CEvidence::createEvidence(){
}

int CEvidence::GetDialogueLength()
{
	length = sizeof(Dialogue);

	return length;
}

int CEvidence::GetLength(){
	return length;
}

CEvidence::CEvidence(string Name){
	name = Name;
	found = false;
	type = Brass_Candlestick;
}

CEvidence::CEvidence()
{
	found = false;
	type = Brass_Candlestick;
}
