#include "AttackThorn.h"
#include <vector>
#include <math.h>

using namespace sf;
using namespace std;

namespace owner
{
    AttackThorn::AttackThorn(GameDataRef data/*,float posx,float posy,float ANGLE*/) : Data(data)
    {
        /*x = posx;
        y = posy;

        dx = cos(angle*DEGTORAD)*6;
        dx = sin(angle*DEGTORAD)*6;*/
    }

    void AttackThorn::Spawn(float x,float y)
    {
        Sprite sprite(Data->assets.GetTexture("GREEN"));
        sprite.setScale(THORN_BULLET_SCALE,THORN_BULLET_SCALE);
        sprite.setPosition(x,y-10);

        SpriteB.push_back(sprite);
        Active.push_back(true);
    }

    void AttackThorn::Move(float dt)
    {
        for(unsigned short int i=0;i<SpriteB.size();i++)
        {
            float movement = POWER_SPEED * dt;

            if(Active.at(i))
            {
                SpriteB.at(i).move(-movement,0);
            }
        }
    }

    void AttackThorn::Draw()
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

    void AttackThorn::Update(vector<bool> isActive)
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

    const vector<Sprite> &AttackThorn::GetSprites() const
    {
        return SpriteB;
    }
}
