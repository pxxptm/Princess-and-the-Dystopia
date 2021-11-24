#include "Hp.h"
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    Hp::Hp(GameDataRef data) : Data(data)
    {

    }

    void Hp::SpawnHp(float x)
    {
        Sprite sprite(Data->assets.GetTexture("HP"));
        sprite.setScale(Hp_SCALE,Hp_SCALE);
        sprite.setPosition(x,HEIGHT - 180 - sprite.getGlobalBounds().height);

        HpSprite.push_back(sprite);
        isActive.push_back(true);
    }

    void Hp::MoveHp(float dt)
    {
        for(unsigned short int i=0;i<HpSprite.size();i++)
        {
            if(HpSprite.at(i).getPosition().x < 0 - HpSprite.at(i).getGlobalBounds().width)
            {
                HpSprite.erase(HpSprite.begin()+i);
                isActive.erase(isActive.begin()+i);
            }
            else
            {
                float movement = Hp_MOVEMENT_SPEED * dt;
                HpSprite.at(i).move(-movement,0);
            }
        }
    }

    void Hp::DrawHp()
    {
        for(unsigned short int i=0;i<HpSprite.size();i++)
        {
            if(isActive.at(i))
            {
                Data->app.draw(HpSprite.at(i));
            }
            else
            {
                HpSprite.erase(HpSprite.begin()+i);
                isActive.erase(isActive.begin()+i);
            }
        }
    }

    void Hp::UpdateHp(vector<bool> isactive)
    {
        for(unsigned short int i=0;i<HpSprite.size();i++)
        {
            isActive.at(i) = isactive.at(i);
        }
    }

    const vector<Sprite> &Hp::GetSprites() const
    {
        return HpSprite;
    }
}
