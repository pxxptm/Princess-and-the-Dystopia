#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;

namespace owner
{
    class SplashState : public State
    {
        public :

            SplashState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private :

            GameDataRef Data;

            Clock clock;

            Sprite background;

            //Font
            Font barchella;
            Font EG;
            Font day28;

            //Text
            Text princess;
            Text andthe;
            Text dystopia;
    };
}

#endif // SPLASHSTATE_H
