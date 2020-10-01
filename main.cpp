#include <iostream>
#include "Dungeon.cpp"
#include "Player.cpp"
#include "CharacterCore.cpp"
#include "Inventory.cpp"
#include "Room.cpp"
#include "BattleCore.cpp"
//#include "Meander.cpp"

int main()
{
    // Set up the player  
    cout << "Welcome to the NetherDungeon.. \n Try not to go insane! What is your name?\n";
    string playerName;
    cin >> playerName;
    /* String name, int maxHealth, currentHealth, string attackDice, strength, dexterity, constitution, intelligence, wisodom, charisma, speed, experience, level, armorClass, initiative; */
    Player player = Player(playerName, 12, 12, "1d4m0", 14, 12, 15, 12, 14, 12, 30, 0, 1, 14, 1, 0, 0);
    
    /* setup Room Inventory and Enemies */
    DnDDice dDice;
    /* give the sword its dangerous */
    /* int health, attack, armorClass, rarity, level; */
    //Weapon sword = Weapon("Short Sword", 0, dDice.rollThemDice(1,6), 0, 0, 0);
    Weapon sword = Weapon("Short Sword", 0, "1d6m0", 0, 0, 0, false);
    Weapon shield = Weapon("Shield",0,"0d1m0",2,0,0, false);
    // name, health, attack, armorClass, useAsWeapon, keyItem, equiped
    Item potion = Item("Potion",0,"0d1m0",0,false,0,false);
    // name, health, attack, armorClass, rarity, status, equiped
    Accessory ring = Accessory("Ring Of Power",0,"0d1m0",5,0,"",false);
    //Weapon stick = Weapon("DStick", 0, "1d4m0", 0, 0, 0);
    vector<Weapon> firstRoomWeapons;
    vector<Accessory> firstRoomAccessories;
    vector<Item> firstRoomItems;
    vector<Weapon> sixthRoomWeapons;
    firstRoomWeapons.push_back(sword);
    firstRoomItems.push_back(potion);
    firstRoomAccessories.push_back(ring);
    sixthRoomWeapons.push_back(shield);
    /* int maxHealth, currentHealth, attack, strength, dexterity, constitution, intelligence, wisodom, charisma, speed, experience, level, armorClass, initiative; */
    CharacterCore firstEnemy = CharacterCore("Dreamlands Cat", 2, 2, "1d4m1", 3, 15, 10, 11, 12, 13, 30, 0, 1, 12, 2, 0, 0);
    CharacterCore secondEnemy = CharacterCore("Mythos Ghast", 45, 45, "1d6m2", 13, 15, 16, 4, 16, 12, 40, 0, 1, 15, 2, 0, 0);    
    vector<CharacterCore> thirdRoomEnemies;
    vector<CharacterCore> fourthRoomEnemies;
    vector<CharacterCore> seventhRoomEnemies;
    vector<CharacterCore> tenthRoomEnemies;
    thirdRoomEnemies.push_back(firstEnemy);
    thirdRoomEnemies.push_back(firstEnemy);
    fourthRoomEnemies.push_back(firstEnemy);
    seventhRoomEnemies.push_back(firstEnemy);
    tenthRoomEnemies.push_back(secondEnemy);

    /* setup Rooms .. this will be a Random Gen at some point */
    Room firstRoom = Room(0, false,firstRoomItems, firstRoomAccessories, firstRoomWeapons, vector<CharacterCore>(),false,true,false,true,0,2,0,1);
    Room secondRoom = Room(1, false,vector<Item>(), vector<Accessory>(), vector<Weapon>(), vector<CharacterCore>(),false,false,true,false,0,0,0,0);
    Room thirdRoom = Room(2, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), thirdRoomEnemies,true,false,false,true,0,0,0,3);
    Room fourthRoom = Room(3, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), fourthRoomEnemies,false,false,true,true,0,0,2,4);
    Room fifthRoom = Room(4, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), vector<CharacterCore>(),false,false,true,true,0,0,3,5);
    Room sixthRoom = Room(5, false, vector<Item>(), vector<Accessory>(), sixthRoomWeapons, vector<CharacterCore>(),false,false,true,true,0,0,4,6);
    Room seventhRoom = Room(6, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), seventhRoomEnemies,false,true,true,false,0,7,5,0);
    Room eighthRoom = Room(7, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), vector<CharacterCore>(),true,true,false,false,6,8,0,0);
    Room ninethRoom = Room(8, false, vector<Item>(), vector<Accessory>(), vector<Weapon>(), vector<CharacterCore>(),true,true,false,false,7,9,0,0);
    Room tenthRoom = Room(9, true, vector<Item>(), vector<Accessory>(), vector<Weapon>(), tenthRoomEnemies,true,false,false,false,8,0,0,0);

    Dungeon dungeon = Dungeon(player);
    dungeon.rooms[0] = firstRoom;
    dungeon.rooms[1] = secondRoom;
    dungeon.rooms[2] = thirdRoom;
    dungeon.rooms[3] = fourthRoom;
    dungeon.rooms[4] = fifthRoom;
    dungeon.rooms[5] = sixthRoom;
    dungeon.rooms[6] = seventhRoom;
    dungeon.rooms[7] = eighthRoom;
    dungeon.rooms[8] = ninethRoom;
    dungeon.rooms[9] = tenthRoom;

    while (true) {
        int result = dungeon.runDungeon();
        if (result == 0) {
            break;
        }
    }
    cout << "Goodbye!";
}