#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <SFML/Graphics.hpp>

using namespace sf;

namespace owner
{
    class Encounter
    {
        public :

            Encounter();

            bool CheckSpriteEncounter(Sprite Sprite1,Sprite Sprite2,int distance);
            bool CheckSpriteEncounter(Sprite Sprite1,float scale1,Sprite Sprite2,float scale2,int distance);
    };
}

#endif // ENCOUNTER_H
