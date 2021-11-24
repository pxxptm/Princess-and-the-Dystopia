#ifndef HP_H
#define HP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFINITION.h"

using namespace sf;
using namespace std;

namespace owner
{
    class Hp
    {
        public :

            Hp(GameDataRef data);

            void SpawnHp(float x);
            void MoveHp(float dt);
            void UpdateHp(vector<bool> isactive);
            void DrawHp();

            vector<bool> isActive;

            const vector<Sprite> &GetSprites() const;

        private :

            GameDataRef Data;
            vector<Sprite> HpSprite;
    };
}

#endif // HP_H
