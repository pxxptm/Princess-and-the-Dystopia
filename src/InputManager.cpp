#include "InputManager.h"

using namespace sf;

namespace owner
{
    bool isSpriteClicked(Sprite object,Mouse::Button button,RenderWindow &app)
    {
        if(Mouse::isButtonPressed(button))
        {
            IntRect tempRect(object.getPosition().x,object.getPosition().y,object.getGlobalBounds().width,object.getGlobalBounds().height);

            if(tempRect.contains(Mouse::getPosition(app)))
            {
                return true;
            }
        }
        return false;
    }

    Vector2i GetMousePosition(RenderWindow &app)
    {
        return Mouse::getPosition(app);
    }
}
