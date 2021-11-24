#include "BarrierUp.h"
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    BarrierUp::BarrierUp(GameDataRef data) : Data(data)
    {
        Spawn = false;
    }

    void BarrierUp::SpawnBarriersUp()
    {
        Sprite sprite_short(Data->assets.GetTexture("Barrier Up Short"));
        sprite_short.setScale(BARRIERUP_SCALE,BARRIERUP_SCALE);
        sprite_short.setPosition(Data->app.getSize().x + sprite_short.getGlobalBounds().width,BARRIER_UP_POSITION_Y);

        int spawn = rand() % 10;

        if( spawn == 3 || spawn == 6)
        {
            BarrierUpSprite.push_back(sprite_short);
            Spawn = true;
        }
        else
        {
            Spawn = false;
        }
    }

    void BarrierUp::MoveBarriersUp(float dt)
    {
        for(unsigned short int i=0;i<BarrierUpSprite.size();i++)
        {
            if(BarrierUpSprite.at(i).getPosition().x < 0 - BarrierUpSprite.at(i).getGlobalBounds().width)
            {
                BarrierUpSprite.erase(BarrierUpSprite.begin()+i);
            }
            else
            {
                float movement = BARRIER_UP_MOVEMENT_SPEED * dt;
                BarrierUpSprite.at(i).move(-movement,0);
            }
        }
    }

    void BarrierUp::DrawBarriersUp()
    {
        for(unsigned short int i=0;i<BarrierUpSprite.size();i++)
        {
            Data->app.draw(BarrierUpSprite.at(i));
        }
    }

    const vector<Sprite> &BarrierUp::GetSprites() const
    {
        return BarrierUpSprite;
    }

    bool BarrierUp::isSpawn()
    {
        return Spawn;
    }
}
