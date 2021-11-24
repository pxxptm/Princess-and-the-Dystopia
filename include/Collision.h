#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

namespace owner
{
    class Collision
    {
        public :

            Collision();

            bool CheckSpriteCollision(Sprite Sprite1,Sprite Sprite2);
            bool CheckSpriteCollision(Sprite Sprite1,float scale1,Sprite Sprite2,float scale2);

            bool isCollide(Entity *a,Entity *b);
    };
}

#endif // COLLISION_H
