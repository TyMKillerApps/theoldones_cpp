#ifndef ROOMGEN_H
#define ROOMGEN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RoomGen
{
private:
    /* data */
public:
    RoomGen(/* args */);
    int arrayXchoice[2] = {1, -1};
    int arrayYchoice[2] = {1, -1};
    vector< pair <int,int> > vectRooms;
    int arrayXcords[40];
    int arrayYcords[40];
};

RoomGen::RoomGen(/* args */)
{
}

#endif