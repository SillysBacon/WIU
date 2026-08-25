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
CItem* CGameManager::addItems(CObstacle* obstacle, CItem::Items type) {
    CItem* newItem = new CItem();
    newItem->SetItem(obstacle, type); // sets type, dialogue, and position
    obstacle->SetItemPtr(newItem);
    allItems.push_back(newItem);
    return newItem;
}

void CGameManager::RemoveRoom(int mapIndex) {
    if (mapIndex < 0 || mapIndex >= MAX_MAPS) return;
    if (mapRemoved[mapIndex]) return; // already removed, avoid double-free

    // Free obstacles that belonged to this room
    for (CObstacle* o : mapObstacles[mapIndex]) {
        delete o;
    }
    mapObstacles[mapIndex].clear();

    // Free NPCs that belonged to this room, and scrub dangling references
    for (NPC* n : mapNPCs[mapIndex]) {
        nodeItems.erase(
            std::remove_if(nodeItems.begin(), nodeItems.end(),
                [n](const NodeItems& r) { return r.npc == n; }),
            nodeItems.end());

        nodeFlags.erase(
            std::remove_if(nodeFlags.begin(), nodeFlags.end(),
                [n](const NodeFlags& r) { return r.npc == n; }),
            nodeFlags.end());

        if (n == Silas) Silas = nullptr; // Silas is tracked separately too

        delete n;
    }
    mapNPCs[mapIndex].clear();

    // Wipe the room's grid/name/player pos, but keep the CMap object/index alive
    map[mapIndex].DeleteRoom();

    // Block travel to it from now on
    mapRemoved[mapIndex] = true;
}

bool CGameManager::IsMapUnlocked(int mapIndex) {
    if (mapRemoved[mapIndex]) return false;
    switch (mapIndex) {
    case 3: // Master Bedroom
        return IsBedroomkeyPresent;

    case 12:
        return IsCollinAvailable;

    case 11: //mansion
        return IsMansionAvailable;

    case 10: // Prosecutor's Office
        return IsProsecutorAvailable;

    case 13: // Main Porch
        return IsMainPorchAvailable;

    case 14: // Main Studyroom
        return IsMainStudyAvailable;


    default:
        return true;
    }
}
void CGameManager::checkNodeFlags(NPC* npc) {
    for (int i = 0; i < (int)nodeFlags.size(); i++) {
        NodeFlags r = nodeFlags[i];
        if (r.npc == npc && npc->getCurrentNode() == r.node) {
            *r.flag = true;
        }
    }
}
void CGameManager::PlayIntroDialogue(int mapIndex) {
    for (auto& line : mapIntroDialogue[mapIndex]) {
        displayDialogue(line.first, line.second);
    }
}

void CGameManager::SetMaps() {

    mapRemoved.resize(MAX_MAPS, false);
    mapVisited.resize(MAX_MAPS, false);
    mapIntroDialogue.resize(MAX_MAPS);
    mapVisited[0] = true;
    mapObstacles.resize(MAX_MAPS);



    // Adding NPCs to the map
    NPC* narrator = new NPC();
    narrator->setPerson(NPC::Narrator); //Narrator for dialogue

    mapNPCs.resize(MAX_MAPS);



    /*---- Mr SIlas Reed ----*/
    Silas = AddNPC(0, NPC::Silias_Reeds, 5, 3);
    //nSR1_0: n = "node", SR = SILAS REED, 0 = EventState, _1 = node number.
    int nSR0_1 = Silas->AddDialougeNode("The call's from your friend, Detective Batista... you know? the funky one");
    int nSR0_2 = Silas->AddDialougeNode("yeah your friend from back in the academy");
    int nSR0_3 = Silas->AddDialougeNode("i got no cash to bet rowan.. flat broke, we really need more cases. this isn't a freebie remember.");
    int nSR0_4 = Silas->AddDialougeNode("He needs help, some rich guy found dead, in his own mansion.");
    int nSR0_5 = Silas->AddDialougeNode("um Batista said it was further from the city some mansion down in Willow's Creek. ill drive.");
    int nSR0_6 = Silas->AddDialougeNode("not sure, he says just look for the mansion surrounded by police.");
    int nSR0_7 = Silas->AddDialougeNode("Right...lets go (You unlocked The Movement to the Mansion)");
    Silas->AddNodeOption(nSR0_1, 0, nSR0_2, "Batista huh?");
    Silas->AddNodeOption(nSR0_2, 0, nSR0_3, "Right right, i wonder if he has gone bald now...wanna bet?");
    Silas->AddNodeOption(nSR0_3, 0, nSR0_4, "Aah, just a small bet nothing harmful. Anyways, why did he call?");
    Silas->AddNodeOption(nSR0_4, 0, nSR0_5, "I see, where is it?");
    Silas->AddNodeOption(nSR0_5, 0, nSR0_6, "Willow's Creek? Mansion? could be the Smiths? the Collins? or the Addams?");
    Silas->AddNodeOption(nSR0_6, 0, nSR0_1, "hmmm");

    Silas->AddNodeOption(nSR0_1, 1, nSR0_7, "aight let's go, we finally getting something good hehehe.");
    Silas->AddNodeOption(nSR0_7, 1, -1, "...");

    Silas->AddNodeOption(nSR0_1, 0, -1, "Nevermind");
    nodeFlags.push_back({ Silas, nSR0_7, &IsMansionAvailable });
    nodeFlags.push_back({ Silas, nSR0_7, &CanTravel });

    
    /*---- Mrs Emily Smith ----*/
    ///* Event 1 (First Interaction) */
    NPC* emily = AddNPC(1, NPC::Emily_Smith, 7, 4);



    int nE1_1 = emily->AddDialougeNode("...Yes?"); //nE1_1: n = "node", E = Emily, 1 = EventState, _1 = node number.
    int nE1_2 = emily->AddDialougeNode("Yes, I was in my room reading. My Maid, Trisha, ran in to told me about it. I-I couldn't believe it.");
    int nE1_3 = emily->AddDialougeNode("* Sobs *");
    int nN1_4 = emily->AddDialougeNode("Emily sat back down on the couch", narrator->getName());

    emily->AddNodeOption(nE1_1, 0, nE1_2, "It says here, you were upstair reading during the time of murder correct?");
    emily->AddNodeOption(nE1_1, 0, -1, "Never mind.");

    emily->AddNodeOption(nE1_2, 0, nE1_3, "I See, Thanks for confirming");  // eventFlag = 1

    emily->AddNodeOption(nE1_3, 0, nN1_4, "...?");

    emily->AddNodeOption(nN1_4, 0, -1, "...");





    /* Event 2 (Need Masterbedroom key) */



    int nE2_1 = emily->AddDialougeNode("...Yes?");
    int nE2_2 = emily->AddDialougeNode("Why? It has nothing to do with what happened in the study.");
    int nE2_3 = emily->AddDialougeNode("...Rule me out? ...Fine here (You received a Bedroom Key)");
    nodeItems.push_back({ emily, nE2_3, "Master Bedroom Key", CItem::MASTER_BEDROOM_KEY });
    int nE2_4 = emily->AddDialougeNode("...Fine. I don't need this looking worse than it already does. (You received a Bedroom Key)");
    nodeItems.push_back({ emily, nE2_4, "Master Bedroom Key", CItem::MASTER_BEDROOM_KEY });
    int nE2_5 = emily->AddDialougeNode("Excuse me?");
    int nE2_6 = emily->AddDialougeNode("My husband is dead! And you're already accusing me in my own home?");

    emily->AddNodeOption(nE2_1, 0, nE2_2, "Mrs. Smith, we need access to the master bedroom,");
    emily->AddNodeOption(nE2_1, 0, -1, "Never mind.");

    emily->AddNodeOption(nE2_2, 0, nE2_3, "We're not here to invade your life. We're here to rule you out");

    emily->AddNodeOption(nE2_2, 0, nE2_4, "If there's nothing in there, this takes two minutes. If you keep stalling, it doesn't look good.");

    emily->AddNodeOption(nE2_2, 0, nE2_5, "What are you hiding in there, Mrs. Smith?");

    emily->AddNodeOption(nE2_3, 0, -1, "...");
    emily->AddNodeOption(nE2_4, 0, -1, "...");
    emily->AddNodeOption(nE2_5, 0, nE2_6, "...");
    emily->AddNodeOption(nE2_6, 0, -1, "...");



    /*---- Mrs Sarah Collins ----*/
     NPC* sarah = AddNPC(1, NPC::Sarah_Collins, 3, 3);
    
     int n0 = sarah->AddDialougeNode("I haven't seen anything unusual.");
     int n1 = sarah->AddDialougeNode("I was home alone, no alibi I'm afraid.");
     int n2 = sarah->AddDialougeNode("Other than just being neighbours, not really...");
     int n3 = sarah->AddDialougeNode("No... no one.");

     sarah->AddNodeOption(n0, 0, n1, "Where were you last night?");
     sarah->AddNodeOption(n0, 0, n2, "Did you know the victim?");
     sarah->AddNodeOption(n0, 0, -1, "Never mind.");

     sarah->AddNodeOption(n1, 0, n3, "Anyone who can confirm that?");
     sarah->AddNodeOption(n1, 0, n0, "Back");

     sarah->AddNodeOption(n2, 0, n0, "Back");

     sarah->AddNodeOption(n3, 0, -1, "...");
     int nE1_correct = sarah->AddDialougeNode("...Oh god, that's Colin's watch. I- I don't know how you got that.");
     int nE1_wrong = sarah->AddDialougeNode("That has nothing to do with anything.");

     sarah->AddNodeOption(n0, 0, NPC::PRESENT_EVIDENCE, "[Present Evidence]");
     sarah->SetEvidenceRequest(n0, 1001, nE1_correct, nE1_wrong);
     sarah->AddNodeOption(nE1_correct, 0, -1, "...");
     sarah->AddNodeOption(nE1_wrong, 0, -1, "...");



     /*---- Mr Michael Turner -----*/
     NPC* michael = AddNPC(5, NPC::Michael_Turner, 10, 8);

     int nM1_1 = michael->AddDialougeNode("Hey...");
     int nM1_2 = michael->AddDialougeNode("Yes, I am. W-Well I would say i'm more of the founder and he is the Co Founder.");
     int nM1_3 = michael->AddDialougeNode("Claim? CLAIM? It's a fact, Detective. The maid saw me leave, ask her yourself.");
     int nM1_4 = michael->AddDialougeNode("Michael points to the direction of the kitchen, where the maid is.", narrator->getName());

     michael->AddNodeOption(nM1_1, 0, nM1_2, "You are Mr Turner right? You're the business partner of Mr Smith?");
     michael->AddNodeOption(nM1_1, 0, -1, "Never mind");

     michael->AddNodeOption(nM1_2, 0, nM1_3, "Right... It says here, you claim you left the Smith mansion at 16:15pm. Correct?");

     michael->AddNodeOption(nM1_3, 0, nM1_4, "...");

     michael->AddNodeOption(nM1_4, 0, -1, "... Ok, we will.");



     /*---- Detective Batista ----*/

    NPC* batista1 = AddNPC(11, NPC::Angelo_Batista, 6, 7);
    int nB1_1 = batista1->AddDialougeNode("It's a closed-room murder, domestic. The owner of this mansion, Mr. Jonathan Smith...");
    int nB1_2 = batista1->AddDialougeNode("...was found dead, El Pobre has a deep wound to the back of the neck");
    int nB1_3 = batista1->AddDialougeNode("Vamanos Viejo, The body is in the study room");
    batista1->AddNodeOption(nB1_1, 0, nB1_2, "...");
    batista1->AddNodeOption(nB1_2, 0, nB1_3, "...");
    batista1->AddNodeOption(nB1_3, 0, -1, "...");

    NPC* batista2 = AddNPC(6, NPC::Angelo_Batista, 3, 1);
    int nB2_1 = batista2->AddDialougeNode("Take a look around see if you find anything...");
    batista2->AddNodeOption(nB2_1, 0, -1, "Got it...");

    int nB3_1 = batista2->AddDialougeNode("Done?");
    int nB3_2 = batista2->AddDialougeNode("From what I've gathered, four people had contact with Mr. Smith around the time of death...");
    int nB3_3 = batista2->AddDialougeNode("...His wife, Emily Smith; his business partner, Michael Turner; his maid, Trisha Lopez; and the neighbour, Sarah Collins");
    int nB3_4 = batista2->AddDialougeNode("They should be downstairs, OH and here is the Case files on the suspects and victim");
    int nB3_5 = batista2->AddDialougeNode("Mr Batista hands you a Case Folder (Case Folder Unlocked Press 'C' then 2) ", narrator->getName());
    batista2->AddNodeOption(nB2_1, 1, nB3_2, "Yes, by the way, Who was present at the time of the crime?");
    batista2->AddNodeOption(nB3_2, 1, nB3_3, "...");
    batista2->AddNodeOption(nB3_3, 1, nB3_4, "...");
    batista2->AddNodeOption(nB3_4, 1, nB3_5, "Thanks");
    batista2->AddNodeOption(nB3_4, 1, -1, "...");







    
     NPC* police = AddNPC(11, NPC::Police, 3, 3);
     int nP1 = police->AddDialougeNode("Keep it moving...");
     police->AddNodeOption(nP1, 0, -1, "...");

     NPC* police2 = AddNPC(11, NPC::Police, 5, 7);
     int nP2 = police2->AddDialougeNode("Keep it moving man");
     police2->AddNodeOption(nP2, 0, -1, "...");

     NPC* police3 = AddNPC(11, NPC::Police, 4, 10);
     int nP3 = police3->AddDialougeNode("Just keeping a look out");
     police3->AddNodeOption(nP3, 0, -1, "...");

     NPC* police4 = AddNPC(11, NPC::Police, 10, 7);
     int nP4 = police4->AddDialougeNode("Just keeping a look out");
     police4->AddNodeOption(nP4, 0, -1, "...");


     NPC* police5 = AddNPC(13, NPC::Police, 3, 3);
     int nP5 = police5->AddDialougeNode("Keep it moving...");
     police5->AddNodeOption(nP5, 0, -1, "...");

     NPC* police6 = AddNPC(13, NPC::Police, 5, 7);
     int nP6 = police6->AddDialougeNode("Keep it moving man");
     police6->AddNodeOption(nP6, 0, -1, "...");

     NPC* police7 = AddNPC(13, NPC::Police, 4, 10);
     int nP7 = police7->AddDialougeNode("Just keeping a look out");
     police7->AddNodeOption(nP7, 0, -1, "...");

     NPC* police8 = AddNPC(13, NPC::Police, 10, 7);
     int nP8 = police8->AddDialougeNode("Just keeping a look out");
     police8->AddNodeOption(nP8, 0, -1, "...");




       /*ROOMS AND MAPS*/

   /*Detective Black's office ROOM 0*/
   {
        map[0].SetRoom(11, 6, 5, 1);//office
        map[0].SetName("Detective Black's Office");
        AddObstacle(0, CObstacle::Long_Shelf, 0, 0, 0)->SetDialogue(0, "a picture of you and Silas at the play ground..... why? well why not");
        CObstacle* carKey = AddObstacle(0, CObstacle::Long_Shelf, 7, 0, 0);
        AddObstacle(0, CObstacle::Table, 8, 2, 1);
        AddObstacle(0, CObstacle::Table, 2, 2, 1)->SetDialogue(0, "you find a twenty that Silas left on the table as you look around before pocketing it");
        CObstacle* jacket = AddObstacle(0, CObstacle::Sofa, 7, 5, 0);
        AddObstacle(0, CObstacle::Sofa, 2, 5, 0)->SetDialogue(0, "its messy from all the times you slept here like your homeless... oh wait you are");
        CObstacle* notebook = AddObstacle(0, CObstacle::Desk, 5, 2, 0);
        AddObstacle(0, CObstacle::Window, 5, 0, 0)->SetDialogue(0, "a beautiful Scenery Of... the neighbouring buildings red wall... truly to die for");
        AddObstacle(0, CObstacle::Door, 5, 5, 0);
        addItems(notebook, CItem::NOTEBOOK);
        addItems(jacket, CItem::JACKET);
        addItems(carKey, CItem::CAR_KEY);


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
       CObstacle* cigarbox = AddObstacle(1, CObstacle::Small_Shelf, 0, 4, 1);
       AddObstacle(1, CObstacle::Table, 0, 7, 1);
       AddObstacle(1, CObstacle::Flower, 0, 3, 1)->SetDialogue(0, "A Potted Plant, Nothing much");
       AddObstacle(1, CObstacle::Flower, 7, 0, 1)->SetDialogue(0, "Did you know? Tulips were once more valuable than gold");
       AddObstacle(1, CObstacle::Door, 0, 0, 0);
       AddObstacle(1, CObstacle::Door, 4, 9, 0)->SetDialogue(0, "Door to the garden");
       AddObstacle(1, CObstacle::Window, 6, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
       AddObstacle(1, CObstacle::Window, 7, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
       AddObstacle(1, CObstacle::Window, 8, 9, 0)->SetDialogue(0, "A window with a stunning view to the flower ocean in the garden");
       addItems(cigarbox, CItem::CIGARS);
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
       AddObstacle(5, CObstacle::Door, 7, 0, 0);
       AddObstacle(5, CObstacle::Window, 0, 5, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
       AddObstacle(5, CObstacle::Window, 0, 4, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
       AddObstacle(5, CObstacle::Window, 0, 3, 0)->SetDialogue(0, "A window with a stunning view to the living room sofa...");
   }

   /*The Mansion study room story ROOM 6*/
   {
       map[6].SetRoom(6, 7, 2, 0);//Mansion study room STORY
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
       AddObstacle(7, CObstacle::Sink, 15, 7, 0);
       AddObstacle(7, CObstacle::Sink, 15, 8, 0);

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

   /*The Neighbour hse kitchen rm ROOM 9*/
   {
       map[9].SetRoom(10, 10, 0, 2);//Neighbour hse Kitchen
       map[9].SetName("The Collins' Kitchen");
       AddObstacle(9, CObstacle::Long_Shelf, 9, 6, 1)->SetDialogue(0, "A bunch of kitchen stuff");
       AddObstacle(9, CObstacle::Long_Shelf, 5, 9, 0)->SetDialogue(0, "A bunch of kitchen stuff");
       AddObstacle(9, CObstacle::Table, 6, 8, 0)->SetDialogue(0, "A Bread, wrapped in plastic, multiple baking tools on the table");
       AddObstacle(9, CObstacle::Table, 8, 7, 1)->SetDialogue(0, "A Bread, wrapped in plastic, multiple baking tools on the table");
       AddObstacle(9, CObstacle::Desk, 8, 6, 1)->SetDialogue(0, "A cutting board");
       AddObstacle(9, CObstacle::Sink, 5, 8, 1);

       AddObstacle(9, CObstacle::Table, 3, 3, 1);
       AddObstacle(9, CObstacle::Table, 4, 3, 1);
       AddObstacle(9, CObstacle::Chair, 3, 2, 1);
       AddObstacle(9, CObstacle::Chair, 2, 4, 1);
       AddObstacle(9, CObstacle::Chair, 4, 5, 1);

       AddObstacle(9, CObstacle::Flower, 9, 2, 1);
       AddObstacle(9, CObstacle::Door, 0, 3, 1);
   }


   /*The Prosecutor office rm ROOM 10*/
   {
       map[10].SetRoom(15, 10, 2, 0);//Prosecutor office
       map[10].SetName("The Prosecutors' Office");
       AddObstacle(10, CObstacle::Door, 3, 0, 0);;
       AddObstacle(10, CObstacle::Sofa, 4, 3, 0);
       AddObstacle(10, CObstacle::Sofa, 4, 7, 0);
       AddObstacle(10, CObstacle::Chair, 7, 5, 0);
       AddObstacle(10, CObstacle::Table, 4, 5, 0);
       AddObstacle(10, CObstacle::Table, 11, 4, 1);
       AddObstacle(10, CObstacle::Chair, 13, 4, 1);
       AddObstacle(10, CObstacle::Long_Shelf, 11, 0, 0);
       AddObstacle(10, CObstacle::Long_Shelf, 11, 9, 0);
       AddObstacle(10, CObstacle::Long_Shelf, 0, 5, 1);
       AddObstacle(10, CObstacle::Flower, 5, 9, 0);
       AddObstacle(10, CObstacle::Window, 5, 0, 0);
       AddObstacle(10, CObstacle::Window, 6, 0, 0);
   }


   {
       map[11].SetRoom(20, 15, 0, 2);//mansion Porch STORY
       map[11].SetName("Mansion Porch");
       for (int y = 0; y < 14; y += 3)//  tree col
       {
           AddObstacle(11, CObstacle::Tree, 5, y, 0);
       }

       for (int y = 1; y < 3; y++)//  cordon1
       {
           AddObstacle(11, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 4; y < 6; y++)//  cordon2
       {
           AddObstacle(11, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 10; y < 12; y++)//  cordon3
       {
           AddObstacle(11, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 13; y < 15; y++)//  cordon4
       {
           AddObstacle(11, CObstacle::Tape, 5, y, 0);
       }

       for (int y = 0; y < 6; y++)// top flower bed
       {
           for (int x = 7; x < 19; x++)
           {
               AddObstacle(11, CObstacle::Flower, x, y, 0);
           }
       }

       for (int y = 9; y < 15; y++)// bottom flower bed
       {
           for (int x = 7; x < 19; x++)
           {
               AddObstacle(11, CObstacle::Flower, x, y, 0);
           }
       }

       AddObstacle(11, CObstacle::Door, 19, 7, 0);

       mapIntroDialogue[11] = {
            {"Narrator", "Black and reed arrive at the crime screne"},
            {"Narrator", "They can see multiple officers cordoning off the area."},
            {"Silas", "Rich people, huh. Bet the maid dusts more than we make in a month."},
            {"Silas", "Maybe we can sneak a bit of loot out"},
            {"Black", "We are detectives Silas not theives.... tho if they do have smt they wont notice or care losing maybe"},
            {"Narrator", "Black and reed walk up the the officers as the officer stops them"},
            {"Officer", "Sorry, We cant allow entry unless you are permitted"},
            {"???", "Its Ok their with me!"},
            {"Narrator", "A big bald man walks towards them with a fedora, a well maintained mustache and goatee, floral shirt, cargo shorts, grinning"},
            {"Black", "Detective Batista! After all these years, can't believe this is how we reunite!"},
            {"Barista", "Ay Cabron Ha Ha Ha"},
            {"Narrator", "Detective Batista laughed as he went in for an embrace with Detective Black."},
            {"Silas", "Damn it. that was all of it"},
            {"Narrator", "Silas Hands over his last 20 bucks"},
       };

   }


   /*The Collin's Porch ROOM 12*/
   {
       map[12].SetRoom(15, 10, 2, 0);//collin Porch
       map[12].SetName("Collin Porch");

   }


   /*The Main mansion Porch ROOM 13*/
   {
       map[13].SetRoom(20, 15, 0, 2);// Main mansion Porch
       map[13].SetName("Mansion Porch");
       for (int y = 0; y < 14; y += 3)//  tree col
       {
           AddObstacle(13, CObstacle::Tree, 5, y, 0);
       }

       for (int y = 1; y < 3; y++)//  cordon1
       {
           AddObstacle(13, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 4; y < 6; y++)//  cordon2
       {
           AddObstacle(13, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 10; y < 12; y++)//  cordon3
       {
           AddObstacle(13, CObstacle::Tape, 5, y, 0);
       }
       for (int y = 13; y < 15; y++)//  cordon4
       {
           AddObstacle(13, CObstacle::Tape, 5, y, 0);
       }

       for (int y = 0; y < 6; y++)// top flower bed
       {
           for (int x = 7; x < 19; x++)
           {
               AddObstacle(13, CObstacle::Flower, x, y, 0);
           }
       }

       for (int y = 9; y < 15; y++)// bottom flower bed
       {
           for (int x = 7; x < 19; x++)
           {
               AddObstacle(13, CObstacle::Flower, x, y, 0);
           }
       }

       AddObstacle(13, CObstacle::Door, 19, 7, 0);
   }

   /*The Main Mansion study room  ROOM 14*/
   {
       map[14].SetRoom(6, 7, 2, 0);//Mansion study room 
       map[14].SetName("The Mansion's Study room");
       AddObstacle(14, CObstacle::Door, 3, 0, 0);
       AddObstacle(14, CObstacle::Chair, 5, 5, 0);
       AddObstacle(14, CObstacle::Table, 3, 4, 1);
       AddObstacle(14, CObstacle::Long_Shelf, 0, 3, 1);
       AddObstacle(14, CObstacle::Small_Shelf, 0, 0, 0);
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










    Connect.resize(15);
    Connect[0] = { 10, 12 ,11, 13};
    Connect[1] = { 2, 3, 4, 5, 6, 7, 8, 10, 13, 14 };
    Connect[2] = { 1 };
    Connect[3] = { 1, 2, 4, 14 };
    Connect[4] = { 1, 2, 3, 14 };
    Connect[5] = { 1, 7 };
    Connect[6] = { 1 };
    Connect[7] = { 1, 5 };
    Connect[8] = { 0, 1, 9, 10 };
    Connect[9] = { 8 };
    Connect[10] = { 0, 1 };
    Connect[11] = { 0, 6 };
    Connect[12] = { 0, 8 };
    Connect[13] = { 0, 1 };
    Connect[14] = { 1, 2, 3, 4 };

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
        if (!CanTravel) {
            displayDialogue("Silas", "We're not going anywhere till we know what we're dealing with.");
            return;
        }
        vector<int> available;
        for (int m : Connect[currentMap]) {
            if (IsMapUnlocked(m)) {
                available.push_back(m);
            }
        }
        int destination = SelectDestination(available);

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
            else if (destination == 6){
                map[currentMap].GetPlayer()->SetPosX(0);
                map[currentMap].GetPlayer()->SetPosY(2);
                map[currentMap].SetPosition();
                map[currentMap].RenderMap();
                RemoveRoom(11);
                IsMainPorchAvailable = true;
            }
            else if (destination == 1){
                map[currentMap].GetPlayer()->SetPosX(0);
                map[currentMap].GetPlayer()->SetPosY(2);
                map[currentMap].SetPosition();
                map[currentMap].RenderMap();
                RemoveRoom(6);
                IsMainStudyAvailable = true;
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

            if (!mapVisited[currentMap]) {
                PlayIntroDialogue(currentMap);
                mapVisited[currentMap] = true;
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
            if (NPCInteract->isSuspect() == true) {
                caseFileSystem.addSuspect(NPCInteract->getPerson());
            }
            NPCInteract->dialougesystem(&map[currentMap],inventory);
            checkNodeItems(NPCInteract);
            checkNodeFlags(NPCInteract);
            map[currentMap].RenderMap();




        }
        else if (ObstacleInteract != nullptr) {
            CItem* foundItem = ObstacleInteract->GetItemPtr();
            if (foundItem != nullptr) {
                inventory->addToInventory(foundItem->GetItemName(), foundItem->GetId());
                displayDialogue("Narrator", ObstacleInteract->GetNextDialouge());
                ObstacleInteract->SetItemPtr(nullptr);

                switch (foundItem->GetId()) {
                case 1001:
                    NotebookisFound = true;
                    break;
                case 1002:
                    CarKeysisFound = true;
                    break;
                case 1003:
                    jacketisFound = true;
                    break;
                }
                if (NotebookisFound && CarKeysisFound && jacketisFound) {
                    Silas->Addeventflag();
                }

            }
            else {
                displayDialogue("Narrator", ObstacleInteract->GetNextDialouge());
            }
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

void CGameManager::checkNodeItems(NPC* npc) {
    for (int i = 0; i < (int)nodeItems.size(); i++) {
        NodeItems r = nodeItems[i];
        if (r.npc == npc && npc->getCurrentNode() == r.node) {
            inventory->addToInventory(r.itemName, r.itemType);
            if (r.itemType == CItem::MASTER_BEDROOM_KEY) {
                IsBedroomkeyPresent = true;
            }
        }
    }
}

void CGameManager::displayDialogue(string c, string t) {
    CUI::GetInstance().RenderDialougeBox(c, t);
    map[currentMap].RenderMap();
}

void CGameManager::TestDialogue() {
    displayDialogue("Narrator", "It's Thursday night, 18:34. Detective Black sits in his office, smoking a cigar. A knock sounds at the door.");
    displayDialogue("Black", "Come in.");
    displayDialogue("Narrator", "He stubs out the cigar in the ashtray as the door opens.");
    displayDialogue("Narrator", "In comes a tall, leanly built man, hair side-parted, a visible eye bag under each eye.");
    displayDialogue("Narrator", "It's Silas Reed, Black's partner and assistant.");
    displayDialogue("Silas", "We just got a call");
    displayDialogue("Silas", "Sounds like a murder down in Willow's Creek. We're up.");
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
            inventory->showInventory(input);
            if (!inventory->getInventoryState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (input == 'c' && inventory->getInventoryState() == false) {
            caseFileSystem.showFiles(input);
            if (!caseFileSystem.getCFSState()) {
                map[currentMap].RenderMap();
            }
            continue;
        }

        else if (inventory->getInventoryState() == false) {
            if (caseFileSystem.getCFSState() == false) {
                changeMaps(input);
            }
            else {
                caseFileSystem.changeFiles(input);
                caseFileSystem.renderFiles();
            }
        }
        else {
            inventory->switchItem(input);
            inventory->renderInventory();
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
