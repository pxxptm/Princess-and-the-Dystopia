#ifndef ENTITY_H
#define ENTITY_H

#include "Animation.h"
#include "Game.h"

using namespace sf;
using namespace std;

namespace owner
{
    class Entity
    {
        public:

            float x;
            float y;
            float dx;
            float dy;
            float R;
            float angle;

            bool life;
            string name;
            Animation anim;

            Entity();
            virtual ~Entity(){};

            void settings(Animation &a,int X,int Y,float Angle=0,int radius=1);
            void draw(RenderWindow &app);

            virtual void update(){};
    };
}

#endif // ENTITY_H
