#ifndef ATTACKTHORN_H
#define ATTACKTHORN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    class AttackThorn
    {
        public:

            AttackThorn(GameDataRef data);

            /*float x;
            float y;
            float dx;
            float dy;
            float angle;*/

            void Spawn(float x,float y);
            void Move(float dt);
            void Draw();
            void Update(vector<bool> isActive);

            vector <bool> Active;
            const vector<Sprite> &GetSprites() const;

        private :

            GameDataRef Data;

            vector<Sprite> SpriteB;
    };

}


#endif // ATTACKTHORN_H
