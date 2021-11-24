#ifndef LEADERBOARDSTATE_H
#define LEADERBOARDSTATE_H

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

#include "State.h"
#include "Game.h"
#include "GameState.h"

using namespace sf;
using namespace std;

namespace owner
{
    class LeaderBoardState : public State
    {
        public:

            LeaderBoardState(GameDataRef data,string newplayer,long long int newpoint,bool getstring,bool getpoint);

            void Init();

            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

            char tempusername[255];
            long long int temp[6];
            long long int score[6];
            string username[6];
            vector <pair<long long int, string>> userScore;

            string newuser;
            long long int newgetpoint;

            bool GetString;
            bool GetPoint;

            vector <pair<long long int, string>> PrintScore;

        private:

            GameDataRef Data;

            Sprite background;

            // Font
            Font barchella;
            Font barbaro;

            Text Back;
            Text Leaderboard;
            Text user;
            Text scoretext;
    };

}

#endif // LEADERBOARDSTATE_H
