#include "CEvidence.h"

void CEvidence::SetEvidence(Evidence E){
	//type = E;

	switch (E) {
	case Brass_Candlestick:
		name = "Brass Candlestick";
		Dialogue[0] = "Hmm, what's this? Looks like blood - Black mutters";
		Dialogue[1] = "At the base of a brass candlestick, a blood smudge can be seen.";
		Dialogue[2] = "Seems like it was wiped carelessly, as if in a rush";
		Dialogue[3] = "Detective Black places the candlestick into a Ziploc bag";
		description = "A Ziploc Bag with a Brass Candlestick, A smudge of Blood can be seen at the side of the Candlestick.";
		length = 4;
		id = 3001;
		found = false;
		break;
	case Broken_Whiskey_Glass:  //Change dialogue to all evidence
		name = "Broken Whiskey Glass";
		Dialogue[0] = "As Detective Black looks closely at the Broken Whiskey Glass on the floor...";
		Dialogue[1] = "he could see a fingerprint smudge";
		Dialogue[2] = "He put the Broken Whiskey Glass into a Ziploc Bag";
		description = "A Ziploc Bag with a Broken Whiskey Glass, A fingerprint smudge is a little visible on the side of the glass";
		length = 3;
		id = 3002;
		found = false;
		break;
	case Gunpowder_Ziploc:
		name = "Gunpowder Ziploc";
		Dialogue[0] = "Has any officer been in here holding a pistol - asks Black";
		Dialogue[1] = "No hermano,  just me and the forensics - said Batista";
		Dialogue[2] = "Funny, there seems to be a gunpowder trace here... -  Black Scoffs";
		Dialogue[3] = "Detective Black places the gunpowder into a Ziploc bag";
		description = "A Ziploc Bag with little traces of Gunpowder";
		length = 4;
		id = 3003;
		found = false;
		break;
	case Suspicious_Glove:
		name = "Suspicious Glove";
		description = "yay";
		length = 0;
		id = 3004;
		found = false;
		break;
	case BrokenWhiskey_Glass_Report:
		name = "BrokenWhiskey Glass Report";
		description = "It states here that the Fingerprint matches Mr Turner's fingerprint.";
		length = 0;
		id = 3005;
		found = false;
		break;
	case Brass_Candlestick_Report:
		name = "Brass Candlestick Report";
		description = "It states here that the blood on the candlestick belongs to Mr Smith.";
		length = 0;
		id = 3006;
		found = false;
		break;
	case Suspicious_Glove_Report:
		name = "Suspicious Glove Report";
		description = "It states that the blood on the suspicious glove belongs to Mr. Smith, while the body hair belongs to Mr. Turner.";
		length = 0;
		id = 3007;
		found = false;
		break;
	case Picture_of_Muddy_shoeprint:
		name = "Picture of Muddy shoeprint";
		Dialogue[0] = "Check this out. It’s mud, isn't it? - questioned Black";
		Dialogue[1] = "Yeah. And from the looks of it...";
		Dialogue[2] = "it seems to be a shoe print coming from the back door, through the garden - replied Silas";
		Dialogue[3] = "Take a picture of this, Silas; this could be our murderer - said Mr Black";
		Dialogue[4] = " (The Image of the muddy shoe print has been added to your evidence inventory)";
		length = 5;
		id = 3008;
		found = false;
		break;
	case Shoebox_of_property_Photos:
		name = "Shoebox of Property Photos";
		Dialogue[0] = "Detective Black spots a shoebox under the coffee table...";
		Dialogue[1] = "-EVIDENCE- scrawled across a strip of tape on the lid.";
		Dialogue[2] = "Evidence? - Black mutters.";
		Dialogue[3] = "He lifts the lid. Inside: a stack of photographs: ";
		Dialogue[4] = "a garden hose laid out across the grass, an apple tree leaning over the fence line...";
		Dialogue[5] = "gardening rake tipped over the boundary, more in the same vein. Dozens of them, some yellowed with age.";
		Dialogue[6] = "What are these? - Black asks, flipping through the pile";
		Dialogue[7] = "Silas walks over, glancing down. - Looks like evidence for a property feud";
		Dialogue[8] = "That might be motive - Black says.";
		description = "yay";
		length = 9;
		id = 3009;
		found = false;
		break;
	case Bank_Statement:
		name = "Bank Statement";
		Dialogue[0] = "Silas! Found something - Black calls, beckoning him over.";
		Dialogue[1] = "Silas leans in. Black holds up a folded bank statement...";
		Dialogue[2] = "several transactions circled in pen — presumably Jonathan's own hand";
		Dialogue[3] = "Withdrawals.Big ones.Same amount, every few weeks, going back months - Black says.";
		Dialogue[4] = "Any idea where it's going - Silas asks.";
		Dialogue[5] = "Not yet.No memo, no transfer name — just cash pulled out, over and over - Black flips the page...";
		Dialogue[6] = "while frowning - Man's bleeding money from somewhere, and he didn't want a paper trail explaining why.";
		Dialogue[7] = "He tucks the statement into an evidence bag - We'll need to find out who's on the other end of this.";
		Dialogue[8] = "(Bank Statement added to your evidence inventory.)";
		description = "A Bank Statement, All withdrwals, no name, no memo, nothing";
		length = 9;
		id = 3010;
		found = false;
		break;
	case Divorce_Papers:
		name = "Divorce Papers";
		Dialogue[0] = "Silas looks inside the nightstand’s drawer";
		Dialogue[1] = "Eh, just a bunch of cosmetics - he mutters.";
		Dialogue[2] = "He reaches in to feel around. His hand brushes against something foreign...";
		Dialogue[3] = "taped to	the underside of the drawer above.  He pulls out what seems to be an Envelope.";
		Dialogue[4] = "Found something, Black. - said Silas";
		Dialogue[5] = "Black opens it and finds an unsigned, unfiled divorce filing with Emily listed as the petitioner.";
		Dialogue[6] = "She was planning to leave him,” Silas says.";
		Dialogue[7] = "Looks like it - Black replies - But why didn’t she file?";
		Dialogue[8] = "(Divorce Papers added to your evidence inventory.)";
		description = "yay";
		length = 9;
		id = 3011;
		found = false;
		break;

	}
}

CEvidence::Evidence CEvidence::getEvidence()
{
	return type;
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
	return found;
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

int CEvidence::GetId()
{
	return id;
}

string CEvidence::GetDescription()
{
	return string(description);
}


CEvidence::CEvidence()
{
	found = false;
	type = Brass_Candlestick;
}
