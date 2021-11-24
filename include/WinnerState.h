#ifndef WINNERSTATE_H
#define WINNERSTATE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;

namespace owner
{
    class WinnerState : public State
    {
        public :

            WinnerState(GameDataRef data,string username,long long int score);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            long long int SCORE;
            string USERNAME;

        private :

            GameDataRef Data;

            Clock clock;

            Sprite background;
    };
}

#endif // WINNERSTATE_H
