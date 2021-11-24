#include "Rock.h"
#include "DEFINITION.h"

namespace owner
{
        Rock::Rock()
        {
            dx = rand()%8-4;
            dy = rand()%8-4;

            name = "Rock";
        }

        void Rock::update()
        {
            x += dx;
            y += dy;
        }
}
