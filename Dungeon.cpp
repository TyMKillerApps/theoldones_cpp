#include "Dungeon.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon(Player p)
{
    player = p;
};


/* main while dungeon game loop */
int Dungeon::runDungeon()
{
    cout << "Welcome to the Dungeon! Enter at your own Risk! \n";
    /*need an actuall address of current rooms pointer*/
    player.currentRoom = &rooms[1];
    player.previousRoom = &rooms[1];
    while(true)
    {

        // present actions
        executeMenu(player);
        // take action - enter sequence
        // movement options
        executeMovementActions(player.currentRoom);        
        // enter room
        enterRoom(player.currentRoom);        
        // check if dead
        if (player.checkIsDead())
        {
            cout << "Game Over! Retry? \n";
            return executeEndGameLogic();
        }
        else
        {
            if(player.currentRoom->isExit)
            {
                if (player.currentRoom->enemies.size()==0)
                {
                   cout << "You win! Play again? \n";
                   return executeEndGameLogic();
                }
            }
        }

    }
}
void Dungeon::printActions(int numActions, string actions[])

{
    cout << "Choose an action \n";
    for (int i = 0; i < numActions; i++)
    {
        cout << actions[i] << "\n";
    }
}
void Dungeon::enterRoom(Room * room)
{
    if (room->enemies.size() !=0)
    {
        /* execute room with enemy */
        executeRoomWIthEnemy(room);
    }
    else if (room->items.size() !=0 || room->weapons.size() !=0 || room->accessories.size() !=0)
    {
        /* execute room with items */
        executeRoomWithLoot(room);
    }
    else
    {
        /* execute empty room */
        executeEmptyRoom(room);
    }
}
void Dungeon::executeMovementActions(Room * room)
{
    while(true)
    {
    vector <char> moveChoices;
    moveChoices.empty();
    char pChoice;
    moveChoices.push_back(pChoice);    
        switch(room->northDoor)
        {
        case true :
            cout << "Move North: n \n";
            pChoice = 'n';
            moveChoices.push_back(pChoice);
            break;
        case false :
            break;
        }
        switch(room->southDoor)
        {
        case true :
            cout << "Move South: s \n";
            pChoice = 's';
            moveChoices.push_back(pChoice);            
            break;
        case false :
            break;
        }
        switch(room->westDoor)
        {
        case true :
            cout << "Move West: w \n";
            pChoice = 'w';
            moveChoices.push_back(pChoice);               
            break;
        case false :
            break;
        }
        switch(room->eastDoor)
        {
        case true :
            cout << "Move east: e \n";
            pChoice = 'e';
            moveChoices.push_back(pChoice);               
            break;
        case false :
            break;
        }
    cout << "Which Direction? \n";
    cin >> pChoice;

        switch(pChoice)
        {
            case 'n':
            if(room->findRoute(moveChoices,'n') == 1)
            {
                player.changeRooms(&rooms[room->nDestPos]);
                break;
            }
            else
            {
                cout << "Invalid Choice \n";
                cout << "You feel Confused with no Sense of Direction.. \n";
                player.changeRooms(&rooms[room->position]);
                break;
            }
            case 's':
            if(room->findRoute(moveChoices,'s') == 1)
            {
                player.changeRooms(&rooms[room->sDestPos]);
                break;
            }
            else
            {
                cout << "Invalid Choice \n";
                cout << "You feel Confused with no Sense of Direction.. \n";
                player.changeRooms(&rooms[room->position]);
                break;
            }            
            case 'w':
            if(room->findRoute(moveChoices,'w') == 1)
            {
                player.changeRooms(&rooms[room->wDestPos]);
                break;
            }
            else
            {
                cout << "Invalid Choice \n";
                cout << "You feel Confused with no Sense of Direction.. \n";
                player.changeRooms(&rooms[room->position]);
                break;
            }            
            case 'e':
            if(room->findRoute(moveChoices,'e') == 1)
            {
                player.changeRooms(&rooms[room->eDestPos]);
                break;
            }
            else
            {
                cout << "Invalid Choice \n";
                cout << "You feel Confused with no Sense of Direction.. \n";
                player.changeRooms(&rooms[room->position]);
                break;
            }            
        }
    return;
    }
}
void Dungeon::executeRoomWithLoot(Room * room)
{
    cout << "You enter a room and see some Loot. \n";
    string actions[] = 
    {
        "Pilfer Loot: p",
        "Move to another room: m"
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "p")
        {
            executeLootActions(room);
            return;
        }
        else if (input =="m")
        {
            return;
        }
        
        else
        {
            cout << "Incorrect choice. \n";
        }
        
    }
}
void Dungeon::executeLootActions(Room * room)
{
    if (room->items.size() !=0)
    {
    Item item = room->items.front();   
        for (int i = 0; i < room->items.size(); i++)
        {
            cout << "You find a " << room->items.at(i).name << ".\n";
        }
    }
    if (room->weapons.size() !=0)
    {
    Weapon weapon = room->weapons.front();   
        for (int i = 0; i < room->weapons.size(); i++)
        {
            cout << "You find a " << room->weapons.at(i).name << ".\n";
        }
    }
    if (room->items.size() !=0)
    {
    Accessory accessory = room->accessories.front();   
        for (int i = 0; i < room->accessories.size(); i++)
        {
            cout << "You find a " << room->accessories.at(i).name << ".\n";
        }
    }    
    player.lootRoom(room);
    room->clearLoot();
}
void Dungeon::executeMenu(Player player)
{
while(true)
{
    vector <char> pChoices;
    pChoices.empty();    
    char pChoice;
    vector <char> mChoices;
    mChoices.empty();
    char mchoice;   
    cout << "Load Menu: l \n";
    pChoice = 'l';
    pChoices.push_back(pChoice);
    cout << "Proceed with Movement: p \n";
    pChoice = 'p';
    pChoices.push_back(pChoice);
    cin >> pChoice;
    vector <int> equipChoices { 0,1,2,3,4,5,6,7,9 };
    int eChoice;

    switch(pChoice)
        {
        case 'l':
        {
            cout << player.name << "'s Inventory Menu.\n";
            cout << "View Items: i\n" ;
            mchoice = 'i';
            mChoices.push_back(mchoice);
            cout << "View Weapons: w\n";
            mchoice = 'w';
            mChoices.push_back(mchoice);            
            cout << "View Accessories: a\n";
            mchoice = 'a';
            mChoices.push_back(mchoice);            
            cout << "Exit Menu: e\n";
            mchoice = 'e';
            mChoices.push_back(mchoice);            
            cin >> mchoice;
            switch(mchoice)
            {
            case 'i':
            {
                if(player.inventoryItems.empty())
                {
                    cout << player.name << " Has Zero Items. \n";
                continue;    
                }
                else
                {
                    for (int i = 0; i < player.inventoryItems.size(); i++)
                    {
                        cout << "Item: " << i << " " << player.inventoryItems.at(i).name << ".\n";
                    }
                    cout << "equip item: (enter item number) \n";
                    cout << player.currentHealth << " <- Player current health \n";
                    cin >> eChoice;
                    if(player.findInventory(equipChoices,eChoice) == 1)
                    {
                     player.useItem(player.inventoryItems.at(eChoice));
                    }
                    cout << player.currentHealth << " <- Player current health after using: " << player.inventoryItems.at(eChoice).name << " \n";
                continue;     
                }
            }
            case 'w':
            {
                if(player.inventoryWeapons.empty())
                {
                    cout << player.name << " Has Zero Weapons. \n";
                continue;
                } 
                else
                {                       
                    for (int i = 0; i < player.inventoryWeapons.size(); i++)
                    {
                        cout << "Weapon: " << i << " " << player.inventoryWeapons.at(i).name << ".\n";
                    }
                continue;
                }
            }
            case 'a':
            {
                if(player.inventoryAccessories.empty())
                {
                    cout << player.name << " Has Zero Weapons. \n";
                continue;                
                } 
                else
                {                          
                    for (int i = 0; i < player.inventoryAccessories.size(); i++)
                    {
                        cout << "Accessory: " << i << " " << player.inventoryAccessories.at(i).name << ".\n";
                    }            
                continue;
                }            
            }
            case 'e':
            {
                cout << "Leaving Menu \n";
                continue;
            }
            default :
            {
                cout << "Incorrect choice. \n";               
            }
        continue;    
        }
        case 'p':
        {
            return;
        }
        default :
                cout << "Invalid Choice \n";
        } 
        }   
    }    
}
void Dungeon::executeRoomWIthEnemy(Room * room)
{
    CharacterCore enemy = room->enemies.back();
    cout << "You enter a room and encounter a " << enemy.name << ".\n";
    string actions[] = 
    {
        "Fight the " + enemy.name + ": f",
        "Move to another room: m"
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "f")
        {
            executeFightActions(&enemy);
            while(player.currentRoom->enemies.size() > 1)
            {
                CharacterCore enemy = room->enemies.back();
                cout << "A " << enemy.name << " approaches " << player.name << "! \n";
                executeFightActions(&enemy);
            }
            player.currentRoom->clearEnemies();
            return;
        }
        else if (input =="m")
        {
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        }
        
        else
        {
            cout << "Incorrect choice. \n";
        }
        
    }
}
void Dungeon::executeFightActions(CharacterCore * enemy)
{
    string actions[] = 
    {
        "Attack: a",
        "Retreat: r"
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        /* player actions */
        if (input == "a")
        {
            bool successPlayer = enemy -> checkSuccess("1d20m0",enemy->armorClass,false,false);
            if(successPlayer)
            {
            int damage = enemy -> takeDamage(player.attackDice,false,false);
            cout << player.name << "'s attack does " << damage << " damage. \n";
            }
            else
            {
                cout << player.name << " Swing and a Miss... \n";
            }
            
        }
        else if (input =="r")
        {
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        }
        
        else
        {
            cout << "Incorrect choice. \n";
        }
        if (enemy->checkIsDead())
        {
            cout << "The enemy " << enemy->name << " has been vanquished! \n";
            cout << player.currentRoom->enemies.size() << "<-- currentRoom enemy size \n";
            //player.increaseStats(10,"",0);
            if(player.currentRoom->enemies.size() == 1)
            {
                player.currentRoom->clearEnemies();
            }
            else
            {
               player.currentRoom->enemies.pop_back(); 
            }
            //player.currentRoom->clearEnemies();
            return;
        }
        bool successEnemy = player.checkSuccess("1d20m0",player.armorClass,false,false);
        if(successEnemy)
        {
            int damage = player.takeDamage(enemy->attackDice,false,false);
            cout << enemy->name << "'s attack does " << damage << " damage. \n";
            cout << "You now have " << player.currentHealth << ".\n";
            if (player.checkIsDead())
            {
            return; 
            }
        }
        else
        {
            cout << enemy->name << " Swing and a Miss... \n";
        }
    }
}
void Dungeon::executeEmptyRoom(Room * room)
{
    cout << "You enter a room that is a whole lot of empty. \n";
    string actions[] = {"Move to another room: m"};
    while(true)
    {
        printActions(1, actions);
        string input;
        cin >> input;
        if (input == "m")
        {
            // move actions
            return;
        }
        else
        {
            cout << "Incorrect choice. \n";
        }
        
    }
}
int Dungeon::executeEndGameLogic()
{
    string actions[] =
    {
        "Yes: y",
        "No: n"
    };
    while(true){
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "y")
        {
            return 1;
        }
        else if (input == "n")
        {
            return 0;
        }
        else
        {
           cout << "Incorrect choice. \n"; 
        }
        
    }
}