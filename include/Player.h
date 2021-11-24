#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "DEFINITION.h"
#include "Game.h"

using namespace sf;
using namespace std;

namespace owner
{
    class Player
    {
        public :

            Player(GameDataRef data);

            float angle = 0;
            long double Amour;

            void DrawPlayer();

            void Animate(float dt);
            void Update(float dt,long double hp,long double amour);
            void Tap_Up();
            void Tap_Down();

            const Sprite &GetSprite() const;

        private :

            GameDataRef Data;

            Sprite PlayerSprite;
            vector<Texture> AnimationFrames;

            Sprite SlideFrame;
            Texture SlidePlayer;
            Texture AmourT;
            Sprite amour;

            unsigned int animationiterator;

            Clock clock;

            int PlayerState;
            int JumpLimit = 0;

            RectangleShape fullbar;
            RectangleShape restbar;

            RectangleShape fullamourbar;
            RectangleShape getamourbar;
    };
}

#endif // PLAYER_H
