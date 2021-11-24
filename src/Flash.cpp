#include "Flash.h"

using namespace sf;

namespace owner
{
    Flash::Flash(GameDataRef data) : Data(data)
    {
        rectanglewhite = RectangleShape(Vector2f(Data->app.getSize().x,Data->app.getSize().y));
        rectanglewhite.setFillColor(Color(255,255,255,0));

        flashOn = true;
    }

    Flash::~Flash()
    {

    }

    void Flash::Show(float dt)
    {
        if(flashOn)
        {
            int delta = (int) rectanglewhite.getFillColor().a + (FLASH_SPEED * dt);

            if(delta >= 255.0f)
            {
                delta = 255.0f;
                flashOn = false;
            }

            rectanglewhite.setFillColor(Color(255,255,255,delta));
        }
        else
        {
            int delta = (int) rectanglewhite.getFillColor().a - (FLASH_SPEED * dt);

            if(delta <= 0.0f)
            {
                delta = 0.0f;
            }

            rectanglewhite.setFillColor(Color(255,255,255,delta));
        }
    }

    void Flash::Draw()
    {
        Data->app.draw(rectanglewhite);
    }
}
