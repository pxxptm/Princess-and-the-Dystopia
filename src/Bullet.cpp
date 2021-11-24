#include "Bullet.h"
#include <vector>
#include <math.h>

using namespace sf;
using namespace std;

namespace owner
{
    Bullet::Bullet(GameDataRef data/*,float posx,float posy,float ANGLE*/) : Data(data)
    {
        /*x = posx;
        y = posy;

        dx = cos(angle*DEGTORAD)*6;
        dx = sin(angle*DEGTORAD)*6;*/
    }

    void Bullet::Spawn(float x,float y)
    {
        Sprite sprite(Data->assets.GetTexture("PINK"));
        sprite.setScale(PINK_POWER_SCALE,PINK_POWER_SCALE);
        sprite.setPosition(x,y);

        SpriteB.push_back(sprite);
        Active.push_back(true);
    }

    void Bullet::Move(float dt)
    {
        for(unsigned short int i=0;i<SpriteB.size();i++)
        {
            float movement = POWER_SPEED * dt;

            if(Active.at(i))
            {
                SpriteB.at(i).move(movement,0);
            }
        }
    }

    void Bullet::Draw()
    {
        for(unsigned short int i=0;i<SpriteB.size();i++)
        {
            if(Active.at(i))
            {
                Data->app.draw(SpriteB.at(i));
            }
            else
            {
                SpriteB.erase(SpriteB.begin()+i);
                Active.erase(Active.begin()+i);
            }
        }
    }

    void Bullet::Update(vector<bool> isActive)
    {
        for(unsigned short int i=0;i<SpriteB.size();i++)
        {
            Active.at(i) = isActive.at(i);

            if (SpriteB.at(i).getPosition().x > WIDTH)
            {
                Active.at(i) = false;
            }
        }
    }

    const vector<Sprite> &Bullet::GetSprites() const
    {
        return SpriteB;
    }
}
