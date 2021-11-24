#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameState.h"
#include "MainMenuState.h"

using namespace sf;

namespace owner
{
    class GameOverState : public State
    {
        public :

            GameOverState(GameDataRef data,string username,long long int point);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            string USERNAME;
            long long int SCORE;

        private :

            GameDataRef Data;

            Sprite background;
            RectangleShape rectt;

            Font  Barchella;
            Font  Barbaro;

            Text  score;
            Text  score_thisgame;

            Text  Back;

            long long int bestpoint;
    };
}

#endif // GAMEOVERSTATE_H
