#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string n, int mh, int ch, string a, int s, int d, int c, int i, int w, int cma, int spd, int exp, int l, int ac, int itv, int drd, int ins): CharacterCore(n, mh, ch, a, s, d, c, i, w, cma, spd, exp, l, ac, itv, drd, ins)
{
    /* name, health, attack, armorclass, useAsWeapon, keyItem; */
    //Item potion = Item("Potion", 10 , 0, 0, false, false);
    // name, health, attack, armorClass, useAsWeapon, rarity, level
   //Weapon stick = Weapon("Stick", 0, 1, 0, 0, 0);
   // addItem(potion);
   // addWeapon(stick);
}

void Player::addItem(Item item)
{
    inventoryItems.push_back(item);

}
void Player::addWeapon(Weapon weapon)
{
    inventoryWeapons.push_back(weapon);

}
void Player::addAccessory(Accessory accessory)
{
    inventoryAccessories.push_back(accessory);
}

void Player::increaseStats(int h, string a, int ac)
{
    /* increment stats for Player */
    currentHealth += h;
    maxHealth += h;
    attackDice = a;
    armorClass += ac;
}

void Player::decreaseStats(int h, string a, int ac)
{
    /* decrement stats for Player */
    currentHealth -= h;
    maxHealth -= h;
    attackDice = a;
    armorClass -= ac;
}

void Player::lootRoom(Room * room)
{
    /* access item members of current room pointer value */
    vector<Item> items = room ->items;
    for (int i = 0; i < items.size(); i++)
    {
        addItem(items[i]);
        cout << items.at(i).name << "<- added item \n";
    }
    vector<Accessory> accessories = room ->accessories;
    for (int i = 0; i < accessories.size(); i++)
    {
        addAccessory(accessories[i]);
        cout << accessories.at(i).name << "<- added accessory \n";
    }
    vector<Weapon> weapons = room ->weapons;
    for (int i = 0; i < weapons.size(); i++)
    {
        addWeapon(weapons[i]);
        cout << weapons.at(i).name << "<- added weapon \n";
    }
}

void Player::changeRooms(Room * newRoom)
{
    /* current room now becomes previous room */
    previousRoom = currentRoom;
    /* current room now becomes new room */
    currentRoom = newRoom;
}

void Player::useItem(Item item)
{
    item.equiped = true;
    increaseStats(item.health, item.attackDice, item.armorClass);
}

void Player::equipWeapon(Weapon weapon)
{
    weapon.equiped = true;
    increaseStats(weapon.health, weapon.attackDice, weapon.armorClass);
}
void Player::equipAccessory(Accessory accessory)
{
    accessory.equiped = true;
    increaseStats(accessory.health, accessory.attackDice, accessory.armorClass);
}

void Player::unequipWeapon(Weapon weapon)
{
    weapon.equiped = false;
    decreaseStats(weapon.health, weapon.attackDice, weapon.armorClass);
}
void Player::unequipAccessory(Accessory accessory)
{
    accessory.equiped = false;
    decreaseStats(accessory.health, accessory.attackDice, accessory.armorClass);
}

int Player::findInventory(vector<int> ivect, int ikey)
{
    if (find(ivect.begin(), ivect.end(), ikey) != ivect.end())
    return 1;
    else
    return 0;
}

Menu::Menu( int nsel, vector<Item> invItem, vector<Weapon> invWeap, vector<Accessory> invAcc)
{
    numSelections = nsel;
    inventoryItems = invItem;
    inventoryWeapons = invWeap;
    inventoryAccessories = invAcc;
}