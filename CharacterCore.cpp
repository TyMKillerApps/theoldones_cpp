#include "CharacterCore.h"
#include "DnDDice.h"
#include <iostream>
#include <sstream>
#include <regex>

CharacterCore::CharacterCore(string n, int mh, int ch, string a, int s, int d, int c, int i, int w, int cma, int spd, int exp, int l, int ac, int itv, int drd, int ins)
{
    name = n;
    maxHealth = mh;
    currentHealth = ch;
    attackDice = a;
    strength = s;
    dexterity = d;
    constitution = c;
    intelligence = i;
    wisodom = w;
    charisma = cma;
    speed = spd;
    experience = exp;
    level = l;
    armorClass = ac;
    initiative = itv;
    dread = drd;
    insanity = ins;
};
bool CharacterCore::checkSuccess(string dicePlusModifier, int ac, bool adv, bool disadv)
{
    stringstream stringStream;
    string onlyNumeric = regex_replace(dicePlusModifier, regex("([^0-9])"),",");
    cout << onlyNumeric << "<-onlyNumeric read into stringStream \n";
    stringStream << onlyNumeric; 
    //string tempString; 
    int tempInt, amount = 0;
    vector<int> foundInt; 
    while(stringStream.good())
    {
        string tempString;
        getline(stringStream, tempString, ',');
        foundInt.push_back(stoi(tempString));
    }
DnDDice::DiceTypeMod diceToRoll;
DnDDice dndDice;
    diceToRoll.numMod = foundInt.back();
    //cout << diceToRoll.numMod << "\n";
    foundInt.pop_back();
    diceToRoll.numSides = foundInt.back();
    //cout << diceToRoll.numSides << "\n";
    foundInt.pop_back();
    diceToRoll.numDice = foundInt.back();
   // cout << diceToRoll.numDice << "\n";
    foundInt.empty();
    diceToRoll.dieAdvantage = adv;
  //  cout << diceToRoll.dieAdvantage << "\n";
    diceToRoll.dieDisadvantage = disadv;
  //  cout << diceToRoll.dieDisadvantage << "\n";
    amount = dndDice.rollThemDice(diceToRoll.numDice, diceToRoll.numSides, diceToRoll.numMod, diceToRoll.dieAdvantage, diceToRoll.dieDisadvantage ); 
    cout << ac << "<- target AC: Dice Roll -> " << amount << "\n";
    if(amount >= ac)
    {
    return 1;
    }
    else
    {
        return 0;
    }
    
}
int CharacterCore::takeDamage(string dicePlusModifier,bool adv, bool disadv)
{
    stringstream stringStream;
    string onlyNumeric = regex_replace(dicePlusModifier, regex("([^0-9])"),",");
    cout << onlyNumeric << "<-onlyNumeric read into stringStream \n";
    stringStream << onlyNumeric; 
    //string tempString; 
    int tempInt, amount = 0;
    vector<int> foundInt; 
    while(stringStream.good())
    {
        string tempString;
        getline(stringStream, tempString, ',');
        foundInt.push_back(stoi(tempString));
    }
DnDDice::DiceTypeMod diceToRoll;
DnDDice dndDice;
    diceToRoll.numMod = foundInt.back();
    //cout << diceToRoll.numMod << "\n";
    foundInt.pop_back();
    diceToRoll.numSides = foundInt.back();
    //cout << diceToRoll.numSides << "\n";
    foundInt.pop_back();
    diceToRoll.numDice = foundInt.back();
   // cout << diceToRoll.numDice << "\n";
    foundInt.empty();
    diceToRoll.dieAdvantage = adv;
  //  cout << diceToRoll.dieAdvantage << "\n";
    diceToRoll.dieDisadvantage = disadv;
  //  cout << diceToRoll.dieDisadvantage << "\n";
    amount = dndDice.rollThemDice(diceToRoll.numDice, diceToRoll.numSides, diceToRoll.numMod, diceToRoll.dieAdvantage, diceToRoll.dieDisadvantage );
    int damage = amount;
    if (damage <0) 
    {
        damage =0;
    }
    currentHealth -= damage;
    return damage;
}

bool CharacterCore::checkIsDead()
{
    return currentHealth <= 0;
}