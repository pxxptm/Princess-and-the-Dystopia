#ifndef ENEMYLEVEL1_H
#define ENEMYLEVEL1_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    class EnemyLevel1
    {
        public :

            EnemyLevel1(GameDataRef data);


            void Spawn();
            void Move(float dt);
            void Draw();
            void Update(vector<int> hp);

            vector<int>  Hp;
            vector<bool> isAlive;

            const vector<Sprite> &GetSprites() const;

        private :

            GameDataRef Data;

            vector<Sprite> Sprite1;
            vector<RectangleShape> fullbar;
            vector<RectangleShape> restbar;

            RectangleShape full;
            RectangleShape rest;
    };
}


#endif // ENEMYLEVEL1_H
