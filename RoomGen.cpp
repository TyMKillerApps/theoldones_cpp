#include "RoomGen.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int RoomGen::runRoomGen()
{

    RoomGen::vectRooms = {{0,0}};
    RoomGen::arrayXcords[0] = {0};
    RoomGen::arrayYcords[0] = {0};
    vector<int> list{1,-1};
    //                          north south west east
    vector<string> doorsDirection{};
    int x=0;
    int y=0;
    for(int i=1; i<40; i++)
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        int newRandom = rand();
        int listIndex = newRandom % list.size();
        int listValue = list[listIndex];
        switch(newRandom%2){
            case 0:
            x = x + listValue;
            switch(listValue){
                case 1:
                doorsDirection.push_back("east");
                case -1:
                doorsDirection.push_back("west");
            }
           //arrayXcords[i] = x;
            break;
            case 1:
            y = y + listValue;
            switch(listValue){
                case 1:
                doorsDirection.push_back("north");
                case -1:
                doorsDirection.push_back("south");
            }
            //arrayYcords[i] = y;
            break;
        }
        cout << x << "," << y << endl;
        vectRooms.push_back(make_pair(x,y));

    }
    for(int i=0; i<40; i++)
    {
        cout << vectRooms[i].first << "," << vectRooms[i].second << ", Destination Door: " << doorsDirection[i] << endl;
    }
    return endRoomGenLogic();
}
int RoomGen::endRoomGenLogic()
{
    cout << "Are you Happy with RoomGen. ? \n";
    cout << "Yes: y \n";
    cout << "No: n \n";

    while(true){
        string input;
        cin >> input;
        if (input == "y")
        {
            return 0;
        }
        else if (input == "n")
        {
            return 1;
        }
        else
        {
           cout << "Incorrect choice. \n"; 
        }
        
    }
}
