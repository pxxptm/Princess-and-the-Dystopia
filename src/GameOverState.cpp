#include "GameOverState.h"
#include "LeaderBoardState.h"
#include "DEFINITION.h"
#include "Game.h"
#include "State.h"
#include "GuideState.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace sf;
using namespace std;

namespace owner
{
    GameOverState::GameOverState(GameDataRef data,string username,long long int point) : Data(data)
	{
	    USERNAME = username;
	    SCORE = point;
	}

	void GameOverState::Init()
	{
	    // background load
	    Data->assets.LoadTexture("Background",MainMenuWallpaper);
	    background.setTexture(this->Data->assets.GetTexture("Background"));

	     /// this score

	    // fonts
	    Barbaro.loadFromFile(BARBARO);
	    Barchella.loadFromFile(BARCHELLLA);

	    // setting
	    score.setString("S C O R E");
	    score.setFont(Barbaro);
	    score.setCharacterSize(60);
	    score.setOutlineColor(Color::Black);
	    score.setOutlineThickness(1);
	    score.setPosition(WIDTH / 2 - score.getGlobalBounds().width / 2,200);

	    score_thisgame.setString(to_string(SCORE));
	    score_thisgame.setFont(Barchella);
	    score_thisgame.setCharacterSize(400);
	    score_thisgame.setOutlineColor(Color::Black);
	    score_thisgame.setOutlineThickness(1);
	    score_thisgame.setPosition(WIDTH / 2 - score_thisgame.getGlobalBounds().width / 2,240);

	    Back.setString("BACK  TO  MAIN  MENU");
	    Back.setFont(Barbaro);
	    Back.setCharacterSize(20);
	    Back.setOutlineColor(Color::Black);
	    Back.setOutlineThickness(1);
	    Back.setPosition(WIDTH / 2 - Back.getGlobalBounds().width / 2,HEIGHT - 100);
	}

	void GameOverState::HandleInput()
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
                    Data->machine.AddState(StateRef(new MainMenuState(Data,USERNAME,SCORE)),true);
                }
            }
            else
            {
                Back.setFillColor(Color::White);
            }
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
	    this->Data->app.clear();

		this->Data->app.draw(this->background);
		Data->app.draw(score);
		Data->app.draw(score_thisgame);
		Data->app.draw(Back);

		this->Data->app.display();
	}
}
