#include "CItem.h"
void CItem::SetType(Items I) {
	Item = I;
	switch (I) {
	case NOTEBOOK:
		ItemName = "Notebook";
		ItemDialouge = "You found Detective Black's Notebook";
		Id = 1001;
		break;
	case CAR_KEY:
		ItemName = "Car Keys";
		ItemDialouge = "You found Detective Black's Car Keys";
		Id = 1002;
		break;
	case JACKET:
		ItemName = "Jacket";
		ItemDialouge = "You found Detective Black's Jacket";
		Id = 1003;
		break;
	case MASTER_BEDROOM_KEY:
		ItemName = "Master Bedroom Key";
		ItemDialouge = "";
		Id = 1005;
		break;
	case NEIGHBOUR_HOUSE_KEY:
		ItemName = "Neighbour House Key";
		ItemDialouge = "";
		Id = 1006;
		break;
	case CIGARS:
		ItemName = "Cigar";
		ItemDialouge = "You found a box of cigars, you sneakily took one out and put it in your pocket";
		Id = 1007;
		break;
	case CODE_NOTE:
		ItemName = "Note with a Code";
		ItemDialouge = "You found a note with the code -6767-";
		Id = 1008;
		break;
	}
}
CItem* CItem::SetItem(CObstacle* obstacle, Items I) {
	SetType(I);
	obstacle->SetDialogue(0, ItemDialouge);
	return this;
}
string CItem::GetItemName() {
	return ItemName; 
}
int CItem::GetId() {
	return Id; 
}

CItem::CItem() {

}