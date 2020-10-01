#include <vector>

#ifndef MEANDER_H
#define MEANDER_H

class Meander
{
    public:
        int xCord, yCord, roomGen;
        bool meanderStart, meanderEnd, meanderTraversed;
        void meanderPlane(Meander *);
};
#endif