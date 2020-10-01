#include <string>
#include "DnDDice.h"
#ifndef CHARACTERCORE_H
#define CHARACTERCORE_H

using namespace std;

class CharacterCore
{
public:
    string name;
    string attackDice;
    int maxHealth, currentHealth, strength, dexterity, constitution, intelligence, wisodom, charisma, speed, experience, level, armorClass, initiative, dread, insanity;
    CharacterCore(string, int, int, string, int, int, int, int, int, int, int, int, int, int, int, int, int);
    int takeDamage(string, bool, bool);
    bool checkSuccess(string, int, bool, bool);
    bool checkIsDead();
};

#endif