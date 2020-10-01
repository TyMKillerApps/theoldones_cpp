#include "CharacterCore.h"
#include "Room.h"
#include "Inventory.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public CharacterCore
{
public:
    /* define Room Pointers */
    Room * currentRoom;
    Room * previousRoom;
    vector<Item> inventoryItems;
    vector<Weapon> inventoryWeapons;
    vector<Accessory> inventoryAccessories;
    /* Player constructor with initialization */
    /* String name, int maxHealth, currentHealth, string attackDice, strength, dexterity, constitution, intelligence, wisodom, charisma, speed, experience, level, armorClass, initiative, Dread, Insanity; */
    Player(string="", int=0, int=0, string="", int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0);
    void addItem(Item);
    void addWeapon(Weapon);
    void addAccessory(Accessory);
    void increaseStats(int,string,int);
    void decreaseStats(int,string,int);
    /* Room Pointer */
    void lootRoom(Room *);
    void changeRooms(Room *);
    void useItem(Item);
    void equipWeapon(Weapon);
    void equipAccessory(Accessory);
    void unequipWeapon(Weapon);
    void unequipAccessory(Accessory);
    int findInventory(vector<int>,int);
};

class Menu: public Player
{
public:
    int numSelections;
    Menu( int , vector<Item>, vector<Weapon>, vector<Accessory>);
};

#endif