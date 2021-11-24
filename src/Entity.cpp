#include "Entity.h"

namespace owner
{
    Entity::Entity()
    {
        life = 1;
    }

    void Entity::settings(Animation &a,int X,int Y,float Angle,int radius)
    {
        anim = a;
        x = X;
        y = Y;
        angle = Angle;
        R = radius;
    }

    void Entity::draw(RenderWindow &app)
    {
        anim.sprite.setPosition(x,y);
        anim.sprite.setRotation(angle+90);

        if(x > 0 && y > 0)
        {
            app.draw(anim.sprite);
        }
    }
}
