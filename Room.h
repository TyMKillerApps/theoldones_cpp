#include <vector>
#include "Inventory.h"
#include "CharacterCore.h"

#ifndef ROOM_H
#define ROOM_H

class Room
{
public:
    int position;
    bool isExit;
    vector<Item> items;
    vector<Accessory> accessories;
    vector<Weapon> weapons;
    vector<CharacterCore> enemies;
    bool northDoor;
    bool southDoor;
    bool westDoor;
    bool eastDoor;
    int nDestPos;
    int sDestPos;
    int wDestPos;
    int eDestPos;
    /* initialize Room inside the Room Constructor!!! */
    Room(int=0, bool=false, vector<Item> = vector<Item>(), vector<Accessory> = vector<Accessory>(), vector<Weapon> = vector<Weapon>(), vector<CharacterCore> = vector<CharacterCore>(), bool=false, bool=false, bool=false, bool=false, int=0, int=0, int=0, int=0);
    void clearLoot();
    void clearEnemies();
    int findRoute(vector<char>,char);
};

#endif