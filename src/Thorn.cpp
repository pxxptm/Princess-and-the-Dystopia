#include "Thorn.h"
#include <vector>

using namespace sf;
using namespace std;

namespace owner
{
    Thorn::Thorn(GameDataRef data) : Data(data)
    {

    }

    void Thorn::SpawnThorn()
    {
        Sprite sprite(Data->assets.GetTexture("Thorn"));
        sprite.setScale(THORN_SCALE,THORN_SCALE);
        sprite.setPosition(Data->app.getSize().x,HEIGHT - 180 - sprite.getGlobalBounds().height);

        int spawn = rand() % 10;

        if(( spawn == 5 || spawn == 7 || spawn == 9 ) && ThornSprite.size() < 2 )
        {
            ThornSprite.push_back(sprite);
            isActive.push_back(true);
        }
        sprite.setPosition(Data->app.getSize().x + 100 + spawn,HEIGHT - 180 - sprite.getGlobalBounds().height);
    }

    void Thorn::MoveThorn(float dt)
    {
        for(unsigned short int i=0;i<ThornSprite.size();i++)
        {
            if(ThornSprite.at(i).getPosition().x < 0 - ThornSprite.at(i).getGlobalBounds().width)
            {
                ThornSprite.erase(ThornSprite.begin()+i);
                isActive.erase(isActive.begin()+i);
            }
            else
            {
                float movement = THORN_MOVEMENT_SPEED * dt;
                ThornSprite.at(i).move(-movement,0);
            }
        }
    }

    void Thorn::DrawThorn()
    {
        for(unsigned short int i=0;i<ThornSprite.size();i++)
        {
            if(isActive.at(i))
            {
                Data->app.draw(ThornSprite.at(i));
            }
            else
            {
                ThornSprite.erase(ThornSprite.begin()+i);
                isActive.erase(isActive.begin()+i);
            }
        }
    }

    void Thorn::UpdateThorn(vector<bool> isactive)
    {
        for(unsigned short int i=0;i<ThornSprite.size();i++)
        {
            isActive.at(i) = isactive.at(i);
        }
    }

    const vector<Sprite> &Thorn::GetSprites() const
    {
        return ThornSprite;
    }
}
