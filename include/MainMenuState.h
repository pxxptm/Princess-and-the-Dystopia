#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "LeaderBoardState.h"

using namespace sf;

namespace owner
{
    class MainMenuState : public State
    {
        public :

            MainMenuState(GameDataRef data);
            MainMenuState(GameDataRef data,string name,long long int point);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            string USERNAME;
            long long int SCORE;

            bool gotname;
            bool gotpoint;

        private :

            GameDataRef Data;

            Sprite background;

            /// TITLE ///

            // Font
            Font barchella;
            Font EG;
            Font day28;

            // Text
            Text princess;
            Text andthe;
            Text dystopia;

            /// BUTTON ///

            // Font
            Font barbaro;

            // Text
            Text type;
            Text play;
            Text highscore;
            Text howtoplay;
            Text exit;
            Text myname;

            string username;
            Text   name;

            Clock delay;
    };
}

#endif // MAINMENUSTATE_H
