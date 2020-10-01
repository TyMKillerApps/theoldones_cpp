#include "Meander.h"
#include <random>

using namespace std;

void Meander::meanderPlane(Meander * meander)
{
    meander->meanderEnd = false;
    meander->meanderStart = true;
    meander->meanderTraversed = true;
    meander->xCord = 0;
    meander->yCord = 0;
    meander->roomGen = 0;
    vector<Meander> section;
    section[0] = { meander->meanderEnd, meander->meanderStart, meander->meanderTraversed,  meander->xCord, meander->yCord, meander->roomGen };
    for( int i=1; i<21; i++)
    {
        meander->roomGen = i;        
        meander->meanderStart = false;
        meander->meanderTraversed = true;
        int x = meander->xCord;
        int y = meander->yCord;
        bool whichWayX = meanderChoice();
        bool whichWayY = meanderChoice();
        bool whichWay = meanderChoice();
        while (true)
        {
            switch (whichWay)
            {
                case true:
                    switch (whichWayX)
                    {
                        case true:
                        x = x + 1;
                        break;
                        case false:
                        x = x - 1;
                        break;
                    }
                case false:
                    switch (whichWayX)
                    {
                        case true:
                        y = y + 1;
                        break;
                        case false:
                        y = y - 1;
                        break;
                    }
            }
            if ( x == section[i-1].xCord && y == section[i-1].yCord)
            {
                continue;
            }
            else
                return;
        }
        meander->xCord = x;
        meander->yCord = y;
        section[i] = { meander->meanderEnd, meander->meanderStart, meander->meanderTraversed,  meander->xCord, meander->yCord, meander->roomGen };
    }
    for (int j=0; j < section.size(); j++)
    {
        cout << section[j] << "<- section at " << j << " \n";

    }
}

bool meanderChoice()
{
    return rand() > (RAND_MAX / 2);
}