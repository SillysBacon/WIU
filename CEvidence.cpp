#include "CEvidence.h"

void CEvidence::SetEvidence(Evidence E){
	type = E;

	switch (E) {
	case Brass_Candlestick:
		name = "Brass Candlestick";
		Dialogue = "a";
		break;
	case Broken_Whiskey_Bottle:
		name = "Broken Whiskey Bottle";
		Dialogue = "a";
		break;
	case Gunpowder_Ziploc:
		name = "Gunpowder Ziploc";
		Dialogue = "a";
		break;
	case Suspicious_Glove:
		name = "Suspicious Glove";
		Dialogue = "a";
		break;
	case BrokenWhiskey_Bottle_Report:
		name = "BrokenWhiskey Bottle Report";
		Dialogue = "a";
		break;
	case Brass_Candlestick_Report:
		name = "Brass Candlestick Report";
		Dialogue = "";
		break;
	case Suspicious_Glove_Report:
		name = "Suspicious Glove Report";
		Dialogue = "";
		break;
	case Picture_of_Muddy_shoeprint:
		name = "Picture of Muddy shoeprint";
		Dialogue = "";
		break;
	case Shoebox_of_property_Photos:
		name = "Shoebox of Property Photos";
		Dialogue = "";
		break;
	case Bank_Statement:
		name = "Bank Statement";
		Dialogue = "";
		break;
	case Divorce_Papers:
		name = "Divorce Papers";
		Dialogue = "";
		break;

	}
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

CEvidence::CEvidence(string Name){
	name = Name;
}

CEvidence::CEvidence()
{
}
