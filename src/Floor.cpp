#include "Floor.h"
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    Floor::Floor(GameDataRef data) : Data(data)
    {
        Sprite sprite1(Data->assets.GetTexture("Floor"));
        Sprite sprite2(Data->assets.GetTexture("Floor"));

        sprite1.setPosition(0,HEIGHT - sprite1.getGlobalBounds().height - 30);
        sprite2.setPosition(sprite1.getGlobalBounds().width + 0.5,HEIGHT - sprite2.getGlobalBounds().height - 30);

        FloorSprites.push_back(sprite1);
        FloorSprites.push_back(sprite2);
    }

    void Floor::MoveFloor(float dt)
    {
        for(unsigned short int i=0;i<FloorSprites.size();i++)
        {
            float movement = THORN_MOVEMENT_SPEED * dt;
            FloorSprites.at(i).move(-movement,0.0f );

            if(FloorSprites.at(i).getPosition().x < 0 - FloorSprites.at(i).getGlobalBounds().width)
            {
                Vector2f position(WIDTH,FloorSprites.at(i).getPosition().y);
                FloorSprites.at(i).setPosition(position);
            }
        }
    }

    void Floor::DrawFloor()
    {
        for(unsigned short int i=0;i<FloorSprites.size();i++)
        {
            Data->app.draw(FloorSprites.at(i));
        }
    }
}
