#include "CItem.h"
void CItem::SetType(Items I) {
	Item = I;
	switch (I) {
	case NOTEBOOK:
		ItemName = "Notebook";
		ItemDialouge = "You find a old rustic notebook";
		Id = 1001;
		break;
	case CAR_KEY:
		ItemName = "";
		ItemDialouge = "";
		Id = 1002;
		break;
	case JACKET:
		ItemName = "";
		ItemDialouge = "";
		Id = 1003;
		break;
	case SAFE_KEY:
		ItemName = "";
		ItemDialouge = "";
		Id = 1004;
		break;
	case MASTER_BEDROOM_KEY:
		ItemName = "";
		ItemDialouge = "";
		Id = 1005;
		break;
	case CAMERA:
		ItemName = "";
		ItemDialouge = "";
		Id = 1006;
		break;
	case CIGARS:
		ItemName = "";
		ItemDialouge = "";
		Id = 1007;
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