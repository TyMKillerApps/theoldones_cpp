#include <string>
#include "CharacterCore.h"

#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

class Inventory
{
public:
   string name;
   string attackDice;
   int health, armorClass, rarity;
   bool equiped;
};

class Item: public Inventory
{
public:
    int useAsWeapon, keyItem;
    // name, health, attack, armorClass, useAsWeapon, keyItem, equiped
    Item(string, int, string, int, bool, bool, bool);
};

class Accessory: public Inventory
{
public:
    string status;
    // name, health, attack, armorClass, useAsWeapon, rarity, status, equiped
    Accessory(string, int, string, int, int, string, bool);
};

class Weapon: public Inventory
{
public:
    int level;
    // name, health, attack, armorClass, rarity, level, equiped
    Weapon(string, int, string, int, int, int, bool);
};

#endif