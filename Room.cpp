#include "Room.h"
#include <algorithm>

Room::Room(int p, bool ie, vector<Item> is, vector<Accessory> acy, vector<Weapon> wpns, vector<CharacterCore> gcs, bool nd, bool sd, bool wd, bool ed, int ndp, int sdp, int wdp, int edp)
{
    position = p;
    isExit = ie;
    items = is;
    accessories = acy;
    weapons = wpns;
    enemies = gcs;
    northDoor = nd;
    southDoor = sd;
    westDoor = wd;
    eastDoor = ed;
    nDestPos = ndp;
    sDestPos = sdp;
    wDestPos = wdp;
    eDestPos = edp;
}

void Room::clearLoot()
{
    items.clear();
    accessories.clear();
    weapons.clear();
}
void Room::clearEnemies()
{
    enemies.clear();
}

int Room::findRoute(vector<char> cvect, char ckey)
{
    if (find(cvect.begin(), cvect.end(), ckey) != cvect.end())
    return 1;
    else
    return 0;
}