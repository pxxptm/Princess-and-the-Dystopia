#include "SplashState.h"
#include "DEFINITION.h"
#include "MainMenuState.h"

#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

namespace owner
{
    SplashState::SplashState(GameDataRef data) : Data(data)
	{

	}

	void SplashState::Init()
	{
        // background load
	    Data->assets.LoadTexture("Background",Wallpaper);
	    background.setTexture(this->Data->assets.GetTexture("Background"));

	    // Font
	    barchella.loadFromFile(BARCHELLLA);
	    EG.loadFromFile(EDGE_OF_THE_GALAXY);
	    day28.loadFromFile(DAY28);

	    // princess
		princess.setString("PrincesS");
		princess.setFont(barchella);
		princess.setCharacterSize(190);
		princess.setPosition(WIDTH / 2 - princess.getGlobalBounds().width / 2,237);

		// and the
		andthe.setString("and             the");
		andthe.setFont(EG);
		andthe.setCharacterSize(35);
		andthe.setPosition(WIDTH / 2 - andthe.getGlobalBounds().width / 2,452);

		// dystopia
		dystopia.setString("DYSTOPIA");
		dystopia.setFont(day28);
		dystopia.setCharacterSize(155);
		dystopia.setPosition(WIDTH / 2 - dystopia.getGlobalBounds().width / 2,490);
	}

	void SplashState::HandleInput()
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

	void SplashState::Update(float dt)
	{
		if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOWTIME)
		{
			// Switch To Main Menu
			Data->machine.AddState(StateRef(new MainMenuState(Data)),true);
		}
	}

	void SplashState::Draw(float dt)
	{
		this->Data->app.clear();
		this->Data->app.draw(background);
		this->Data->app.draw(princess);
		this->Data->app.draw(andthe);
		this->Data->app.draw(dystopia);
		this->Data->app.display();
	}
}
