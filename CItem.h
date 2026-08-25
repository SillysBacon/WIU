#pragma once
#include "CObject.h"
#include "CObstacle.h"
#include "CInventory.h"
class CItem :
    public CObject
{
public:
	enum Items
	{
		NOTEBOOK,
		CAR_KEY,
		JACKET,
		SAFE_KEY,
		MASTER_BEDROOM_KEY,
		NEIGHBOUR_HOUSE_KEY,
		CIGARS
	};
private:
	Items Item;
	string ItemDialouge;
	string ItemName;
	int Id;
public:
	CItem* SetItem(CObstacle* Obstacle, Items I);
	void AddToInventory();
	void SetType(Items I);
	//Items GetType();
	CItem();
	string GetItemName();
	int GetId();
};

