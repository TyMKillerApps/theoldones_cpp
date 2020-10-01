#include "Inventory.h"

Item::Item(string n, int h, string a, int ac, bool uw, bool ki, bool eqp)
{
    name = n;
    health = h;
    attackDice = a;
    armorClass = ac;
    useAsWeapon = uw;
    keyItem = ki;
    equiped = eqp;
};

Accessory::Accessory(string n, int h, string a, int ac, int r, string st, bool eqp)
{
    name = n;
    health = h;
    attackDice = a;
    armorClass = ac;
    rarity = r;
    status = st;
    equiped = eqp;
};

Weapon::Weapon(string n, int h, string a, int ac, int r, int l, bool eqp)
{
    name = n;
    health = h;
    attackDice = a;
    armorClass = ac;
    rarity = r;
    level = l;
    equiped = eqp;
};