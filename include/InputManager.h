#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

using namespace sf;

namespace owner
{
    class InputManager
    {
        public :

            InputManager()  {}
            ~InputManager() {}

            bool isSpriteClicked(Sprite object,Mouse::Button button,RenderWindow &app);

            Vector2i GetMousePosition(RenderWindow &app);
    };
}

#endif // INPUTMANAGER_H
