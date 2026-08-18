#pragma once
#include "CGameObject.h"
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
        Tree
    };
    void SetType(Furniture f);
    void Rotate();
    int GetWidth();
    int GetHeight();
    char GetSymbol();
    Furniture GetType();
    CObstacle();

private:
    Furniture type;
    int width, height;
    char symbol;

};

