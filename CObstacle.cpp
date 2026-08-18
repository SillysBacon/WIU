#include "CObstacle.h"

void CObstacle::SetType(Furniture f)
{
	type = f;
	switch (f)
	{
	case Table:
		width = 2; height = 1; symbol = '#';
		break;
	case Desk:
		width = 1; height = 1; symbol = '#';
		break;
	case Small_Shelf:
		width = 3; height = 1; symbol = 'X';
		break;
	case Long_Shelf:
		width = 4; height = 1; symbol = 'X';
		break;
	case Sofa:
		width = 2; height = 1; symbol = 'L';
		break;
	case Chair:
		width = 1; height = 1; symbol = 'L';
		break;
	case Door:
		width = 1; height = 1; symbol = '/';
		break;
	case Window:
		width = 1; height = 1; symbol = '+';
		break;
	case Flower:
		width = 1; height = 1; symbol = '*';
		break;
	case Tree:
		width = 1; height = 1; symbol = '@';
		break;
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
	width = 0;
	height = 0;
	symbol = '\0'; //nullptr placeholder
	SetPosX(0);
	SetPosY(0);
}