#ifndef HEADUPDISPLAY_H
#define HEADUPDISPLAY_H

#include "Game.h"
#include "DEFINITION.h"

using namespace sf;

namespace owner
{
    class HeadUpDisplay
    {
        public :

            HeadUpDisplay(GameDataRef data);

            void ShowScore();

            void UpdateScore(int score);

        private :

            GameDataRef Data;

            Font barbaro;
            Text scoretext;
    };
}

#endif // HEADUPDISPLAY_H
