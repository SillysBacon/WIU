#include "CGameManager.h"
#include <iostream>


CObstacle* CGameManager::AddObstacle(int mapIndex, CObstacle::Furniture type, int x, int y, bool rotation)
{
    CObstacle* Furniture = new CObstacle();
    Furniture->SetType(type);
    Furniture->SetPosX(x);
    Furniture->SetPosY(y);
    if (rotation) {
        Furniture->Rotate();
    }
    mapObstacles[mapIndex].push_back(Furniture);
    return Furniture;
}

NPC* CGameManager::AddNPC(int mapIndex, NPC::People type, int x, int y)
{
    NPC* People = new NPC();
    People->setPerson(type);
    People->SetPosX(x);
    People->SetPosY(y);

    mapNPCs[mapIndex].push_back(People);
    return People;
}

CObstacle* CGameManager::FindObstacle(int mapIndex, int x, int y) {
    for (int i = 0; i < (int)(mapObstacles[mapIndex].size()); i++) {
        CObstacle* O = mapObstacles[mapIndex][i];

        int OX = O->GetPosX();
        int OY = O->GetPosY();
        int OWidth = O->GetWidth();
        int OHeight = O->GetHeight();

        if (x >= OX && x < OX + OWidth && y >= OY && y < OY + OHeight) {
            return O;
        }
    }
    return nullptr;
}

NPC* CGameManager::FindNPC(int mapIndex, int x, int y) {
    for (int i = 0; i < (int)(mapNPCs[mapIndex].size()); i++) {
        NPC* npc = mapNPCs[mapIndex][i];

        if (npc->GetPosX() == x && npc->GetPosY() == y) {
            return npc;
        }
    }
    return nullptr;
}


void CGameManager::SetMaps() {


    mapObstacles.resize(MAX_MAPS);



    // Adding NPCs to the map

    mapNPCs.resize(MAX_MAPS);

    
    NPC* sarah = AddNPC(0, NPC::Sarah_Collins, 3, 3);

    int n0 = sarah->AddDialougeNode("I haven't seen anything unusual.");
    int n1 = sarah->AddDialougeNode("I was home alone, no alibi I'm afraid.");
    int n2 = sarah->AddDialougeNode("We went to school together, years ago.");
    int n3 = sarah->AddDialougeNode("No... no one.");

    sarah->AddNodeOption(n0, 0, n1, "Where were you last night?");
    sarah->AddNodeOption(n0, 0, n2, "Did you know the victim?");
    sarah->AddNodeOption(n0, 0, -1, "Never mind.");

    sarah->AddNodeOption(n1, 0, n3,"Anyone who can confirm that?");  // eventFlag = 1
    sarah->AddNodeOption(n1, 0, n0, "Back");

    sarah->AddNodeOption(n2, 0, n0, "Back");

    sarah->AddNodeOption(n3,0, -1, "...");




    


       /*ROOMS AND MAPS*/

   /*Detective Black's office ROOM 0*/
   {
       map[0].SetRoom(11, 6, 5, 1);//office
       map[0].SetName("Detective Black's Office");
       AddObstacle(0, CObstacle::Long_Shelf, 0, 0, 0)->SetDialogue(0, "a picture of you and silas at the play ground..... why? well why not");
       AddObstacle(0, CObstacle::Long_Shelf, 7, 0, 0);
       AddObstacle(0, CObstacle::Table, 8, 2, 1);
       AddObstacle(0, CObstacle::Table, 2, 2, 1)->SetDialogue(0, "you find a twenty that Silas left on the table as you look around before pocketing it");
       AddObstacle(0, CObstacle::Sofa, 7, 5, 0);
       AddObstacle(0, CObstacle::Sofa, 2, 5, 0)->SetDialogue(0, "its messy from all the times you slept here like your homeless... oh wait you are");
       AddObstacle(0, CObstacle::Desk, 5, 2, 0)->SetDialogue(0, "Your desk. Cigarette burns and coffee rings... really trying to sell the depressed detective trope");
       AddObstacle(0, CObstacle::Window, 5, 0, 0)->SetDialogue(0, "a beautiful Scenery Of... the neighbouring buildings red wall... truely to die for");
       AddObstacle(0, CObstacle::Door, 5, 5, 0);
   }

   /*The Mansion's Living room ROOM 1*/
   {
       map[1].SetRoom(14, 10, 0, 2);//Mansion living room
       map[1].SetName("The Mansion's Living room");
       AddObstacle(1, CObstacle::Long_Shelf, 13, 0, 1)->SetDialogue(0, "A bunch of trophies and medals, the name Colin is written on each and every one of it");
       AddObstacle(1, CObstacle::Long_Shelf, 13, 6, 1)->SetDialogue(0, "Books, a bunch of them. OMG IS THAT THE VOLUME 1 FIRST PRINTED COPY OF ONE PIECE???!!");
       AddObstacle(1, CObstacle::Sofa, 8, 2, 0);
       AddObstacle(1, CObstacle::Sofa, 6, 4, 1);
       AddObstacle(1, CObstacle::Sofa, 8, 7, 0);
       AddObstacle(1, CObstacle::Table, 9, 4, 1)->SetDialogue(0, "A basket of fruits sat on top of the Marble Table, I think someone bit into the faux Lemon, poor guy");
       AddObstacle(1, CObstacle::Table, 12, 4, 1)->SetDialogue(0, "A 2.5 Mil Stuart Hughes Prestige HD Supreme Rose Edition TV, This luxury 55-inch TV is wrapped in 28 kilograms of 18k rose gold");
       AddObstacle(1, CObstacle::Small_Shelf, 0, 4, 1);
       AddObstacle(1, CObstacle::Table, 0, 7, 1);
       AddObstacle(1, CObstacle::Flower, 0, 3, 1)->SetDialogue(0, "A Potted Plant, Nothing much");
       AddObstacle(1, CObstacle::Flower, 7, 0, 1)->SetDialogue(0, "Did you know? Tulips were once more valuable than gold");
       AddObstacle(1, CObstacle::Door, 0, 0, 0);
       AddObstacle(1, CObstacle::Door, 4, 9, 0)->SetDialogue(0, "Door to the garden");
       AddObstacle(1, CObstacle::Window, 6, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
       AddObstacle(1, CObstacle::Window, 7, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
       AddObstacle(1, CObstacle::Window, 8, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
   }

   /*The Mansion's Toilet ROOM 2*/
   {
       map[2].SetRoom(6, 6, 2, 0);//Mansion toilet
       map[2].SetName("The Mansion's toilet");
       AddObstacle(2, CObstacle::Door, 3, 0, 0);
       AddObstacle(2, CObstacle::Sink, 5, 2, 0)->SetDialogue(0, "A sink and a mirror, Still looking sharp Black");
       AddObstacle(2, CObstacle::ToiletBowl, 5, 4, 0)->SetDialogue(0, "A Toilet bowl, Is that a s*** stain?");
       AddObstacle(2, CObstacle::BathTub, 0, 4, 1)->SetDialogue(0, "A big ahh bath tub, a rubber duck sits inside it");
       AddObstacle(2, CObstacle::Flower, 0, 2, 1)->SetDialogue(0, "A Potted Plant, Nothing much");

   }

   /*The Mansion's Master Bedroom ROOM 3*/
   {
       map[3].SetRoom(10, 10, 0, 2);//Mansion master bedroom
       map[3].SetName("The Mansion's Master bedroom");
       AddObstacle(3, CObstacle::Table, 5, 0, 0)->SetDialogue(0, "A Study table, with a stunning view to the Collin's house wall");
       AddObstacle(3, CObstacle::Long_Shelf, 9, 6, 1)->SetDialogue(0, "Just a shelf with personal belongings and picture");
       AddObstacle(3, CObstacle::Long_Shelf, 0, 6, 1)->SetDialogue(0, "Just a shelf with personal belongings and picture");
       AddObstacle(3, CObstacle::Bed, 4, 7, 0)->SetDialogue(0, "A Queen-size Bed, Floral Blanket seems disturbed, seems like someone was lying down here before");
       AddObstacle(3, CObstacle::Desk, 6, 9, 0)->SetDialogue(0, "A 50 shades of grey book on the desk, kinky");
       AddObstacle(3, CObstacle::Desk, 3, 9, 0);
       AddObstacle(3, CObstacle::Flower, 7, 0, 0)->SetDialogue(0, "A Potted Plant, Nothing much");
       AddObstacle(3, CObstacle::Flower, 4, 0, 0)->SetDialogue(0, "A Potted Plant, Nothing much");
       AddObstacle(3, CObstacle::Door, 0, 3, 0);

   }

   /*The Mansion's Bedroom ROOM 4*/
   {
       map[4].SetRoom(7, 5, 2, 0);//Mansion bedroom
       map[4].SetName("The Mansion's Child's bedroom");
       AddObstacle(4, CObstacle::Bed, 0, 3, 1)->SetDialogue(0, "A King-size bed with a few unfolded clothes and another pile of folded clothes on it.");
       AddObstacle(4, CObstacle::Desk, 0, 2, 1);
       AddObstacle(4, CObstacle::Small_Shelf, 6, 2, 1);
       AddObstacle(2, CObstacle::Door, 3, 0, 0);
   }

   /*The Mansion garden ROOM 5*/
   {

       map[5].SetRoom(20, 20, 0, 2);//Mansion garden
       map[5].SetName("The Mansion's Garden");
       for (int y = 3; y < 16; y++) // left flower bed 
       {
           for (int x = 3; x < 8; x++)
           {
               AddObstacle(5, CObstacle::Flower, x, y, 0);
           }
       }

       for (int y = 3; y < 16; y++)// right flower bed 
       {
           for (int x = 11; x < 16; x++)
           {
               AddObstacle(5, CObstacle::Flower, x, y, 0);
           }
       }

       for (int x = 0; x < 20; x += 2)// top tree row
       {
           AddObstacle(5, CObstacle::Tree, x, 0, 0);
       }

       for (int x = 0; x < 20; x += 2)// bottom tree row
       {
           AddObstacle(5, CObstacle::Tree, x, 19, 0);
       }

       for (int x = 4; x < 7; x++) // top left chairs
       {
           AddObstacle(5, CObstacle::Chair, x, 2, 0);
       }

       for (int x = 4; x < 7; x++)// bottom left chairs
       {
           AddObstacle(5, CObstacle::Chair, x, 16, 0);
       }

       for (int x = 12; x < 15; x++)// top right chairs
       {
           AddObstacle(5, CObstacle::Chair, x, 2, 0);
       }

       for (int x = 12; x < 15; x++)// bottom left chairs
       {
           AddObstacle(5, CObstacle::Chair, x, 16, 0);
       }

       AddObstacle(5, CObstacle::Door, 0, 7, 0);
       AddObstacle(5, CObstacle::Door, 6, 0, 0);
       AddObstacle(5, CObstacle::Window, 0, 5, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
       AddObstacle(5, CObstacle::Window, 0, 4, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
       AddObstacle(5, CObstacle::Window, 0, 3, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
   }

   /*The Mansion study room ROOM 6*/
   {
       map[6].SetRoom(6, 7, 2, 0);//Mansion study room
       map[6].SetName("The Mansion's Study room");
       AddObstacle(6, CObstacle::Door, 3, 0, 0);
       AddObstacle(6, CObstacle::Chair, 5, 5, 0);
       AddObstacle(6, CObstacle::Table, 3, 4, 1);
       AddObstacle(6, CObstacle::Long_Shelf, 0, 3, 1);
       AddObstacle(6, CObstacle::Small_Shelf, 0, 0, 0);
   }

   /*The Mansion kitchen ROOM 7*/
   {
       map[7].SetRoom(17, 10, 0, 2);//Mansion kitchen
       map[7].SetName("The Mansion's Kitchen");
       for (int x = 2; x < 8; x++)// table
       {
           AddObstacle(7, CObstacle::Table, x, 4, 1)->SetDialogue(0, "Table with a candle in the middle");
       }
       for (int x = 2; x < 8; x += 2)// chairs top
       {
           AddObstacle(7, CObstacle::Chair, x, 3, 0)->SetDialogue(0, "You sat down...then you stand up");
       }
       for (int x = 2; x < 8; x += 2)// chairs bottom
       {
           AddObstacle(7, CObstacle::Chair, x, 6, 0)->SetDialogue(0, "You sat down...then you stand up");
       }
       AddObstacle(7, CObstacle::Chair, 1, 4, 0)->SetDialogue(0, "You sat down...then you stand up");
       AddObstacle(7, CObstacle::Chair, 8, 5, 0)->SetDialogue(0, "You sat down...then you stand up");

       AddObstacle(7, CObstacle::Table, 11, 4, 1);

       for (int y = 1; y < 6; y += 2)// cooking area
       {
           AddObstacle(7, CObstacle::Table, 15, y, 1);
       }
       for (int y = 0; y < 9; y += 2)// top shelf
       {
           AddObstacle(7, CObstacle::Small_Shelf, 16, y, 1);
       }

       AddObstacle(7, CObstacle::Long_Shelf, 13, 0, 0)->SetDialogue(0, "Just bunch of Kitchen Appliance");
       AddObstacle(7, CObstacle::Long_Shelf, 13, 9, 0)->SetDialogue(0, "Just bunch of Kitchen Appliance");

       AddObstacle(7, CObstacle::Window, 7, 0, 0);
       AddObstacle(7, CObstacle::Window, 8, 0, 0);

       AddObstacle(7, CObstacle::Window, 7, 9, 0)->SetDialogue(0, "Stunning view to the garden");
       AddObstacle(7, CObstacle::Window, 8, 9, 0)->SetDialogue(0, "There is a mold stain on this window, someone ain't doing their job");

       AddObstacle(7, CObstacle::Door, 5, 9, 0)->SetDialogue(0, "Door to the garden");

   }

   /*The Neighbour hse living rm ROOM 8*/
   {
       map[8].SetRoom(10, 15, 2, 0);//Neighbour hse living rm
       map[8].SetName("The Collins' Living room");

       AddObstacle(8, CObstacle::Door, 3, 0, 0);
       AddObstacle(8, CObstacle::Door, 5, 14, 0)->SetDialogue(0, "Locked Door, with about 45 chained padlock");
       AddObstacle(8, CObstacle::Window, 5, 0, 0);
       AddObstacle(8, CObstacle::Window, 6, 0, 0);

       AddObstacle(8, CObstacle::Table , 0, 7, 1)->SetDialogue(0, "Is that a Samsung UN110S9VFXZA 4K Ultra High Definition TV, that has a 240 Hz refresh rate and 110-inch screen?");
       AddObstacle(8, CObstacle::Long_Shelf, 0, 3, 1)->SetDialogue(0, "A few Pictures of the Collins Family");
       AddObstacle(8, CObstacle::Small_Shelf, 0, 9, 1)->SetDialogue(0, "CDs of mulitple Movies: The Shining, Mean girls, Tom & Jerry...");
       AddObstacle(8, CObstacle::Table, 2, 7, 1)->SetDialogue(0, "A Table with a Compartment below");
       AddObstacle(8, CObstacle::Sofa, 4, 7, 1);
       AddObstacle(8, CObstacle::Sofa, 2, 5, 0);
       AddObstacle(8, CObstacle::Sofa, 2, 10, 0);

       AddObstacle(8, CObstacle::Small_Shelf, 9, 3, 1)->SetDialogue(0, "A few Pictures of the Collins Family");
       AddObstacle(8, CObstacle::Small_Shelf, 9, 10, 1)->SetDialogue(0, "An Ischia Rising Stars Trophy with the name Lily Collins");

   }


   map[9].SetRoom(10, 10, 0, 2);//Neighbour hse Kitchen
   map[9].SetName("The Collins' Kitchen");

   map[10].SetRoom(15, 10, 2, 0);//Prosecutor office
   map[10].SetName("The Prosecutors' Office");


   /*To place The Objects with height and symbol*/
   for (int i = 0; i < MAX_MAPS; i++) {
       for (int j = 0; j < mapObstacles[i].size(); j++) {
           CObstacle* o = mapObstacles[i][j];
           map[i].SetObstacle(o->GetWidth(), o->GetHeight(),
               o->GetSymbol(), o->GetPosX(), o->GetPosY());
       }
   }

   // Placing the NPC's symbol
   for (int i = 0; i < MAX_MAPS; i++) {
       for (int j = 0; j < mapNPCs[i].size(); j++) {
           NPC* n = mapNPCs[i][j];
           map[i].SetNPC(n->getSymbol(), n->GetPosX(), n->GetPosY());
       }
   }


    /*To place The Objects with height and symbol*/
    for (int i = 0; i < MAX_MAPS; i++) {
        for (int j = 0; j < mapObstacles[i].size(); j++) {
            CObstacle* o = mapObstacles[i][j];
            map[i].SetObstacle(o->GetWidth(), o->GetHeight(),
                o->GetSymbol(), o->GetPosX(), o->GetPosY());
        }
    }

    // Placing the NPC's symbol
    for (int i = 0; i < MAX_MAPS; i++) {
        for (int j = 0; j < mapNPCs[i].size(); j++) {
            NPC* n = mapNPCs[i][j];
            map[i].SetNPC(n->getSymbol(), n->GetPosX(), n->GetPosY());
        }
    }










    Connect.resize(11);
    Connect[0] = { 1, 8, 10 };
    Connect[1] = { 0, 2, 3, 4, 5, 6, 7, 8, 10 };
    Connect[2] = { 1 };
    Connect[3] = { 1, 2, 4, 6 };
    Connect[4] = { 1, 2, 3, 6 };
    Connect[5] = { 1, 7 };
    Connect[6] = { 1, 2, 3, 4 };
    Connect[7] = { 1, 5 };
    Connect[8] = { 0, 1, 9, 10 };
    Connect[9] = { 8 };
    Connect[10] = { 0, 1 };
}
int CGameManager::SelectDestination(vector<int>& options) {
    int pos = 0;
    bool selecting = true;
    int destination = -1;

    while (selecting) {
        CUI::GetInstance().Clear();
        cout << "\n      [Where do you want to go now, Mr Black?]\n";
        cout << "+====Current Location: " << map[currentMap].GetName() << "====+" << endl << endl;

        for (int i = 0; i < (int)options.size(); i++) {
            if (i == pos) {
                cout << "      ~> " << "[" << map[options[i]].GetName() << "]" << endl;
            }
            else {
                cout << "         " << "[" << map[options[i]].GetName() << "]" << endl;
            }
        }

        int input = _getch();

        if (input == 0 || input == 224) {
            input = _getch();
            if (input == 72 && pos > 0) {
                pos -= 1;
            }
            else if (input == 80 && pos < (int)options.size() - 1) {
                pos += 1;
            }
        }
        else if (input == 13) {
            destination = options[pos];
            selecting = false;
        }
        else if (input == 27) {
            selecting = false;
        }
    }

    return destination;
}

void CGameManager::changeMaps(char input)
{
    if (input == 'm') {

        vector<int>& option = Connect[currentMap];
        int destination = SelectDestination(option);

        if (destination != -1) {
            map[currentMap].removePosition(
                map[currentMap].GetPlayer()->GetPosY(),
                map[currentMap].GetPlayer()->GetPosX()
            );

            currentMap = destination;
            if (destination == 0) {
                map[currentMap].GetPlayer()->SetPosX(5);
                map[currentMap].GetPlayer()->SetPosY(1);
                map[currentMap].SetPosition();
                map[currentMap].RenderMap();
            }
            else if (destination%2 != 0 && destination != 0){
                map[currentMap].GetPlayer()->SetPosX(0);
                map[currentMap].GetPlayer()->SetPosY(2);
                map[currentMap].SetPosition();
                map[currentMap].RenderMap();
            }
            else {
                map[currentMap].GetPlayer()->SetPosX(2);
                map[currentMap].GetPlayer()->SetPosY(0);
                map[currentMap].SetPosition();
                map[currentMap].RenderMap();
            }

            CUI::GetInstance().typeText("You are now at "); CUI::GetInstance().typeText(map[currentMap].GetName()); CUI::GetInstance().typeText(".\n");
        }
        else {
            map[currentMap].RenderMap();
        }
    }


    /*Interaction Code*/
    else if (input == 'e') {

        CPlayer* player = map[currentMap].GetPlayer();
        int tx = player->GetPosX();
        int ty = player->GetPosY();

        switch (player->GetlastInput()) {
        case 'w':
            ty--;
            break;
        case 'a':
            tx--;
            break;
        case 's':
            ty++;
            break;
        case 'd':
            tx++;
            break;
        }

        NPC* NPCInteract = FindNPC(currentMap, tx, ty);
        CObstacle* ObstacleInteract = FindObstacle(currentMap, tx, ty);

        if (NPCInteract != nullptr) {
            NPCInteract->dialougesystem(&map[currentMap]);
            map[currentMap].RenderMap();
        }
        else if (ObstacleInteract != nullptr) {
            displayDialogue("game", ObstacleInteract->GetNextDialouge());
        }
        else {
            displayDialogue("Silas", "theres nothing there... might be losing it pal");
        }
    }



    else if (input == 'f') {
        char npc;
        npc = map[0].GetItem(map[currentMap].GetPlayer()->GetPosX(), map[currentMap].GetPlayer()->GetPosY());
    }
    else {
        map[currentMap].Movement(input);
    }
}

void CGameManager::displayDialogue(string c, string t) {
    CUI::GetInstance().RenderDialougeBox(c, t);
    map[currentMap].RenderMap();
}

void CGameManager::TestDialogue() {
    displayDialogue("Game", "It's Thursday night, 18:34. Detective Black sits in his office, smoking a cigar. A knock sounds at the door.");
    displayDialogue("Game", "Come in.");
    displayDialogue("Game", "He stubs out the cigar in the ashtray as the door opens.");
    displayDialogue("Game", "In comes a tall, leanly built man, hair side-parted, a visible eye bag under each eye.");
    displayDialogue("Game", "It's Silas Reed, Black's partner and assistant.");
    displayDialogue("Game", "We just got a call, Silas says.");
    displayDialogue("Game", "Sounds like a murder down in Willow's Creek. We're up.");
}

void CGameManager::RunGame() {
    map[currentMap].RenderMap();
    TestDialogue();
    while (IsGameRunning) {
        char input = _getch();

        if (input == 27) {
            bool keepPlaying = CUI::GetInstance().PauseMenu();
            if (!keepPlaying) {
                IsGameRunning = false;
            }
            else {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (input == 'i' && caseFileSystem.getCFSState() == false) {
            inventory.showInventory(input);
            if (!inventory.getInventoryState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (input == 'c' && inventory.getInventoryState() == false) {
            caseFileSystem.showFiles(input);
            if (!caseFileSystem.getCFSState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (inventory.getInventoryState() == false) {
            if (caseFileSystem.getCFSState() == false) {
                changeMaps(input);
            }
            else {
                caseFileSystem.changeFiles(input);
                caseFileSystem.renderFiles();
            }
        }
        else {
            inventory.switchItem(input);
            inventory.renderInventory();
        }
    }
}

CGameManager::CGameManager() {
    currentMap = 0;
    currentUI = 0;
    SetMaps();
    CUI::GetInstance().Run();
    if (CUI::GetInstance().GetGameStart()){
        IsGameRunning = true;
    }
    else {
        IsGameRunning = false;
    }
    if (IsGameRunning) {
        RunGame();
    }
    else {
        return;
    }
}

CGameManager::~CGameManager() {
    for (auto& obstacleList : mapObstacles) {
        for (CObstacle* Obstacles : obstacleList) {
            delete Obstacles;
        }
    }
    for (auto& npcList : mapNPCs) {
        for (NPC* npcs : npcList) {
            delete npcs;
        }
    }
}
