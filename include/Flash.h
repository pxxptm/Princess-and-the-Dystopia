#ifndef FLASH_H
#define FLASH_H

#include "Game.h"
#include "DEFINITION.h"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace owner
{

    class Flash
    {
        public:

            Flash (GameDataRef data);
            ~ Flash();

            void Show(float dt);
            void Draw();

        private :

            GameDataRef Data;

            RectangleShape rectanglewhite;

            bool flashOn;
    };
}

#endif // FLASH_H
