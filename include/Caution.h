#ifndef CAUTION_H
#define CAUTION_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITION.h"

using namespace sf;

namespace owner
{
    class Caution: public State
    {
        public :

            Caution(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private :

            GameDataRef Data;

            Sprite background;
            Font   barbaro;
            Text   Back;
    };

}

#endif // CAUTION_H
