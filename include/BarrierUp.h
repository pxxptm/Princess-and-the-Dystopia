#ifndef BARRIERUP_H
#define BARRIERUP_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    class BarrierUp
    {
        public :

            BarrierUp(GameDataRef data);

            void SpawnBarriersUp();
            void MoveBarriersUp(float dt);
            void DrawBarriersUp();

            const vector<Sprite> &GetSprites() const;
            bool  isSpawn();

        private :

            GameDataRef Data;
            vector <Sprite> BarrierUpSprite;

            bool Spawn;
    };
}

#endif // BARRIERUP_H
