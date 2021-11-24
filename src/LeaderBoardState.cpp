#include "LeaderBoardState.h"

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "DEFINITION.h"
#include "MainMenuState.h"

using namespace sf;
using namespace std;

namespace owner
{
    LeaderBoardState::LeaderBoardState(GameDataRef data,string newplayer,long long int newpoint,bool getstring,bool getpoint) : Data(data)
	{
	    newuser = newplayer;
	    newgetpoint = newpoint;
	    GetString = getstring;
	    GetPoint = getpoint;
	}

	void LeaderBoardState::Init()
	{
	    // Font
	    barchella.loadFromFile(BARCHELLLA);
	    barbaro.loadFromFile(BARBARO);

        // background load
	    Data->assets.LoadTexture("Background",MainMenuWallpaper);
	    background.setTexture(this->Data->assets.GetTexture("Background"));

        Back.setString("BACK  TO  MAIN  MENU");
	    Back.setFont(barbaro);
	    Back.setCharacterSize(20);
	    Back.setOutlineColor(Color::Black);
	    Back.setOutlineThickness(1);
	    Back.setPosition(WIDTH / 2 - Back.getGlobalBounds().width / 2,HEIGHT - 100);

	}

	void LeaderBoardState::HandleInput()
	{
	    Event event;

	    while (this->Data->app.pollEvent(event))
		{
			if (event.type == Event::Closed)
            {
                this->Data->app.close();
            }

            if(Back.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                Back.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    Data->machine.AddState(StateRef(new MainMenuState(Data)),true);
                }
            }
            else
            {
                Back.setFillColor(Color::White);
            }
		}
	}

	void LeaderBoardState::Update(float dt)
	{
	    FILE    *fp;

	    vector < pair<long long int,string> > userScore;

	    fp = fopen("resource/Leader Board.txt","r");

	    for (int i = 0; i < 5; i++)
        {
            fscanf(fp,"%s",&tempusername);
            username[i] = tempusername;
            fscanf(fp,"%lld",&score[i]);
            userScore.push_back(make_pair(score[i],username[i]));
            temp[i] = score[i];
            //cout << tempusername << " " << score[i] << endl;
        }

        username[5] = newuser;
        score[5] = newgetpoint;
        temp[5] = newgetpoint;

        userScore.push_back(make_pair(score[5],username[5]));

        sort(temp,temp+6);

        for (int i = 0; i < 6; i++)
        {
            //cout << username[i] << " " << score[i] << " " << temp[i] << endl;

            for (int j = 0; j < 6; j++)
            {
                if(temp[5-i]==score[j])
                {
                    PrintScore.push_back(make_pair(temp[5-i],username[j]));
                    //cout << username[j] << " " << temp[i] << endl;
                    break;
                }
            }
        }

        fclose(fp);

        sort(userScore.begin(),userScore.end());

        ofstream myfile("Leader Board.txt");

        if (myfile.is_open())
        {
            for (int i = 0; i < 6; i++)
            {
                myfile << PrintScore[i].second << " " << PrintScore[i].first << endl;
                //cout << username[i] << " " << score[i] << endl;
            }

            myfile.close();
        }

        fclose(fp);


        fp = fopen("Leader Board.txt","r");

	    for (int i = 0; i < 5; i++)
        {
            fscanf(fp,"%s",&tempusername);
            username[i] = tempusername;
            fscanf(fp,"%lld",&score[i]);
            //PrintScore.push_back(make_pair(score[i],username[i]));
            //cout << tempusername << " " << score;
        }
        fclose(fp);
        //sort(PrintScore.begin(),PrintScore.end());

	}

	void LeaderBoardState::Draw(float dt)
	{
	    this->Data->app.clear();

	    this->Data->app.draw(background);

	    Leaderboard.setString("Leader   boarD");
	    Leaderboard.setFont(barchella);
        Leaderboard.setCharacterSize(120);
        Leaderboard.setPosition(WIDTH / 2 - Leaderboard.getGlobalBounds().width / 2, 80);
        this->Data->app.draw(Leaderboard);

        this->Data->app.draw(Back);

	    for (int i = 0; i < 5; i++)
        {
            user.setString(PrintScore[i].second);
            user.setFont(barbaro);
            user.setCharacterSize(40);
            user.setPosition(WIDTH / 2 - Leaderboard.getGlobalBounds().width / 2, 350 + 70 * i);

            scoretext.setString(to_string(PrintScore[i].first));
            scoretext.setFont(barbaro);
            scoretext.setCharacterSize(40);
            scoretext.setPosition(WIDTH / 2 + Leaderboard.getGlobalBounds().width / 2 - scoretext.getGlobalBounds().width, 350 + 70 * i);

            this->Data->app.draw(user);
            this->Data->app.draw(scoretext);
        }

        this->Data->app.display();
	}
}
