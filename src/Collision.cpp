#include "Collision.h"
#include "DEFINITION.h"

using namespace sf;

namespace owner
{
    Collision::Collision()
    {

    }

    bool Collision::CheckSpriteCollision(Sprite Sprite1,Sprite Sprite2)
    {
        Rect <float> rect1 = Sprite1.getGlobalBounds();
        Rect <float> rect2 = Sprite2.getGlobalBounds();

        if(rect1.intersects(rect2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Collision::CheckSpriteCollision(Sprite Sprite1,float scale1,Sprite Sprite2,float scale2)
    {
        Sprite1.setScale(scale1,scale1);
        Sprite2.setScale(scale2,scale2);

        Rect <float> rect1 = Sprite1.getGlobalBounds();
        Rect <float> rect2 = Sprite2.getGlobalBounds();

        if(rect1.intersects(rect2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Collision::isCollide(Entity *a,Entity *b)
    {
        return (b->x - a->x)*(b->x - a->x)+(b->y - a->y)*(b->y - a->y)<(a->R + b->R)*(a->R + b->R);
    }
}
