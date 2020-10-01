#include "Room.h"
#include "Player.h"
//#include "Meander.h"

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon
{
public:
    /* can make this a pointer but not for now */
    Player player;
    //Meander theMeander;
   // Dungeon(Meander);
    /* start with ten rooms */
    Room rooms[10];
    Dungeon(Player);
    /* 0 to end game loop 1 to continue running loop */
    int runDungeon();
    void printActions(int, string[]);
    void enterRoom(Room *);
    void executeMovementActions(Room *);
    void executeRoomWithLoot(Room *);
    void executeLootActions(Room *);
    void executeMenu(Player);
    void executeRoomWIthEnemy(Room *);
    void executeFightActions(CharacterCore *);
    void executeEmptyRoom(Room *);
    int executeEndGameLogic();
};

#endif