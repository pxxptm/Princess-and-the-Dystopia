#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <list>
#include <vector>
#include "State.h"
#include "Game.h"
#include "BarrierUp.h"
#include "Floor.h"
#include "Player.h"
#include "Collision.h"
#include "Flash.h"
#include "HeadUpDisplay.h"
#include "Thorn.h"
#include "EnemyLevel1.h"
#include "EnemyLevel2.h"
#include "Encounter.h"
#include "Bullet.h"
#include "Entity.h"
#include "Rock.h"
#include "AttackThorn.h"
#include "Hp.h"

using namespace sf;

namespace owner
{
    class GameState : public State
    {
        public :

            GameState(GameDataRef data,string username);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            string USERNAME;

        private :

            GameDataRef Data;

            Sprite background;
            Sprite pausebackground;
            Sprite pausebutton;

            Texture playerbulletsprite;

            BarrierUp       *barrierup;
            Floor           *floor;
            Player          *player;
            Collision       collision;
            Encounter       encounter;
            Flash           *flash;
            HeadUpDisplay   *HUD;
            Thorn           *thorn;
            EnemyLevel1     *enemyLV1;
            EnemyLevel2     *enemyLV2;
            Rock            *rock;
            AttackThorn     *attackthorn;
            Bullet          *bullet;
            Hp              *hp;

            Clock clock;
            Clock BarrierUpClock;
            Clock ScoringClock;
            Clock GameOverClock;
            Clock ThornClock;
            Clock EnemyLevel1Clock;
            Clock EnemyLevel2Clock;
            Clock AmourClock;

            int gamestate;
            int ESC;
            long long int score = 0;

            long double Player_Hp = PLAYER_HP;

            Font barbaro;
            Font barchella;
            Font EG;
            Font day28;

            Text princess;
            Text andthe;
            Text dystopia;

            Text play;
            Text quit;

            /// enemy spawn
            int level1;
            int level2;

            bool spawnLevel1;
            bool spawnLevel2;

            /// enemy Hp
            vector<int> LV1Hp;
            vector<bool> EnemyLevel1Alive;
            vector<int> LV2Hp;
            vector<bool> EnemyLevel2Alive;

            /// bullet shoot
            vector<bool> bulletActive;
            Clock CoolDownBullet;
            bool ShootABLE;

            vector<bool> isThornActive;

            /// background object
            list<Entity*> entities;

            Texture     smallrock;

            /// thorn attacked
            vector<bool> thornbulletActive;

            /// drop Hp
            bool drop_1;
            vector<bool> isHpActive;

            /// amour
            long double amourload;
            bool isx2;

            /// audio
            SoundBuffer     collectbuff;
            SoundBuffer     gameoverbuff;
            SoundBuffer     winningbuff;
            SoundBuffer     jumpbuff;
            SoundBuffer     slidebuff;
            SoundBuffer     roarbuff;
            SoundBuffer     hitbuff;
            SoundBuffer     shootbuff;

            Sound       collect;
            Sound       gameover;
            Sound       winning;
            Sound       jump;
            Sound       slide;
            Sound       roar;
            Sound       hit;
            Sound       shoot;
    };
}

#endif // GAMESTATE_H
