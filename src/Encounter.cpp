#include "Encounter.h"
#include <math.h>

using namespace sf;

namespace owner
{
    Encounter::Encounter()
    {

    }

    bool Encounter::CheckSpriteEncounter(Sprite Sprite1,Sprite Sprite2,int distance)
    {
        if(Sprite1.getGlobalBounds().width + Sprite1.getPosition().x == Sprite2.getPosition().x - distance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Encounter::CheckSpriteEncounter(Sprite Sprite1,float scale1,Sprite Sprite2,float scale2,int distance)
    {
        Sprite1.setScale(scale1,scale1);
        Sprite2.setScale(scale2,scale2);

        if(Sprite1.getGlobalBounds().height + Sprite1.getPosition().y == (int)Sprite2.getPosition().y- distance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
