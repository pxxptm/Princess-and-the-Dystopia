#ifndef ROCK_H
#define ROCK_H

#include "Entity.h"

namespace owner
{
    class Rock : public Entity
    {
        public :

            Rock();

            void update();
    };
}

#endif // ROCK_H
