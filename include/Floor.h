#ifndef FLOOR_H
#define FLOOR_H

#include "Game.h"
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    class Floor
    {
        public :

            Floor(GameDataRef data);

            void MoveFloor(float dt);
            void DrawFloor();

        private :

            GameDataRef Data;
            vector<Sprite> FloorSprites;
    };
}

#endif // FLOOR_H
