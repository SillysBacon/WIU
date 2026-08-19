#include "CObstacle.h"

void CObstacle::SetType(Furniture f)
{
	type = f;
	switch (f)
	{
	case Table:
		width = 2; height = 1; symbol = '#';
		IDialouge[0] = "A table. Sturdy. Unremarkable... kinda like people named lucas";
		IDialouge[1] = "Still very much a table, With a picture of what seems to be a cat or a dog";
		IDialouge[2] = "you straigten the files on the table";
		break;
	case Desk:
		width = 1; height = 1; symbol = '#';
		IDialouge[0] = "A normal desk made out of wood. doesnt seem to be any evidence here";
		IDialouge[1] = "there's a few scratches on the wood. the table has been throughly used";
		IDialouge[2] = "still just a desk.";
		break;
	case Small_Shelf:
		width = 3; height = 1; symbol = '=';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case Long_Shelf:
		width = 4; height = 1; symbol = '=';
		IDialouge[0] = "Books, trophies, most of them fake just to trick the clients";
		IDialouge[1] = "you straigten the book that is crooked";
		IDialouge[2] = "you avoid your job as you continue to reorganise the shelf. slias looks mildly annoyed";
		break;
	case Sofa:
		width = 2; height = 1; symbol = 'L';
		IDialouge[0] = "A sofa, nothing much to see apart from the weird stain you and silas agree not to talk about";;
		IDialouge[1] = "You sit. You get up. You sit again. Nothing about this helps the case.";
		IDialouge[2] = "You lay on the sofa as you stare at the ceiling... maybe it knows why you dont have any money";
		break;
	case Chair:
		width = 1; height = 1; symbol = 'L';
		break;
	case Door:
		width = 1; height = 1; symbol = '/';
		break;
	case Window:
		width = 1; height = 1; symbol = '+';
		IDialouge[0] = "a clear window with a nice veiw of the sky";
		IDialouge[1] = "you breathe on the window as you make a smiley face from the fog";
		IDialouge[2] = "you contine to stare outside as you think to yourself to maybe do your job";
		break;
	case Flower:
		width = 1; height = 1; symbol = '*';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case Tree:
		width = 1; height = 1; symbol = '@';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case Bed:
		width = 2; height = 3; symbol = 'X';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case ToiletBowl:
		width = 1; height = 1; symbol = 'O';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case BathTub:
		width = 2; height = 1; symbol = 'H';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	case Sink:
		width = 1; height = 1; symbol = 'a';
		IDialouge[0] = "";
		IDialouge[1] = "";
		IDialouge[2] = "";
		break;
	}

}
string CObstacle::GetNextDialouge() {
	if (dialougeidx < 0) dialougeidx = 0;
	if (dialougeidx > 2) dialougeidx = 2;
	string line = IDialouge[dialougeidx];
	if (dialougeidx < 2) dialougeidx++;
	return line;
}

// CObstacle.cpp
void CObstacle::SetDialogue(int index, const string text) {
	if (index >= 0 && index <= 2) {
		IDialouge[index] = text;
	}
}

void CObstacle::Rotate() 
{
	int temp = width;
	width = height;
	height = temp;
}

int CObstacle::GetWidth() 
{ 
	return width; 
}
int CObstacle::GetHeight() 
{ 
	return height; 
}
char CObstacle::GetSymbol() 
{ 
	return symbol; 
}
CObstacle::Furniture CObstacle::GetType() 
{
	return type; 
}

CObstacle::CObstacle() 
{
	dialougeidx = 0;
	type = Table;
	width = 0;
	height = 0;
	symbol = '\0'; //nullptr placeholder
	SetPosX(0);
	SetPosY(0);
}