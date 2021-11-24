#ifndef GUIDESTATE_H
#define GUIDESTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITION.h"

using namespace sf;

namespace owner
{
    class GuideState: public State
    {
        public :

            GuideState(GameDataRef data);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private :

            GameDataRef Data;

            Sprite background;
            Font   barbaro;
            Text   Back;
            Text   Next;
    };

}
#endif // GUIDESTATE_H
