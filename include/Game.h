#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace sf;
using namespace std;

namespace owner
{
    struct GameData
    {
        StateMachine  machine;
        RenderWindow  app;
        AssetManager  assets;
        InputManager  input;
    };

    typedef shared_ptr <GameData> GameDataRef;

    class Game
    {
        public :

            Game(int W,int H,string title);

        private :

            const float dt = 1.0f / 60.0f;
            Clock  clock;

            GameDataRef data = make_shared <GameData>();

            void Run();
    };
}


#endif // GAME_H
