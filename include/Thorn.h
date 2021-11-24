#ifndef THORN_H
#define THORN_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    class Thorn
    {
        public :

            Thorn(GameDataRef data);

            void SpawnThorn();
            void MoveThorn(float dt);
            void UpdateThorn(vector<bool> isactive);
            void DrawThorn();

            vector<bool> isActive;

            const vector<Sprite> &GetSprites() const;

        private :

            GameDataRef Data;
            vector<Sprite> ThornSprite;
    };
}

#endif // THORN_H
