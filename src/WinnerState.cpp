#include "WinnerState.h"
#include "DEFINITION.h"
#include "GameOverState.h"

#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

namespace owner
{
    WinnerState::WinnerState(GameDataRef data,string username,long long int score) : Data(data)
	{
	    SCORE = score;
	    USERNAME = username;
	}

	void WinnerState::Init()
	{
        // background load
	    Data->assets.LoadTexture("Background",WinnerStateWallpaper);
	    background.setTexture(this->Data->assets.GetTexture("Background"));
	}

	void WinnerState::HandleInput()
	{
		Event event;

		while (this->Data->app.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				this->Data->app.close();
			}
		}
	}

	void WinnerState::Update(float dt)
	{
		if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOWTIME)
		{
			// Switch To Main Menu
			Data->machine.AddState(StateRef(new GameOverState(Data,USERNAME,SCORE)),true);
		}
	}

	void WinnerState::Draw(float dt)
	{
		this->Data->app.clear();
		this->Data->app.draw(background);
		this->Data->app.display();
	}
}
