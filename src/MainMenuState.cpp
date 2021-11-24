#include "MainMenuState.h"
#include "DEFINITION.h"
#include "GameState.h"
#include "GuideState.h"
#include "LeaderBoardState.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;

namespace owner
{
    MainMenuState::MainMenuState(GameDataRef data) : Data(data)
	{
	    gotname = false;
	    gotpoint = false;
	}

	MainMenuState::MainMenuState(GameDataRef data,string name,long long int point) : Data(data)
	{
	    USERNAME = name;
	    SCORE = point;
	    gotname = true;
	    gotpoint = true;
	}

	void MainMenuState::Init()
	{
	    int posy;

        // background load
	    Data->assets.LoadTexture("Background",MainMenuWallpaper);
	    background.setTexture(this->Data->assets.GetTexture("Background"));

	    /// TITLE ///

	    // Font
	    barchella.loadFromFile(BARCHELLLA);
	    EG.loadFromFile(EDGE_OF_THE_GALAXY);
	    day28.loadFromFile(DAY28);
	    barbaro.loadFromFile(BARBARO);

	    // Type
	    type.setString("type   your   name");
	    type.setFont(barbaro);
	    type.setColor(Color(80,80,80));
		type.setCharacterSize(30);
		type.setPosition(WIDTH/2 - type.getGlobalBounds().width/2,380);


	    // User name
	    name.setFont(barbaro);
	    name.setCharacterSize(40);

	    // princess
		princess.setString("PrincesS");
		princess.setFont(barchella);
		princess.setCharacterSize(90);
		posy = princess.getGlobalBounds().height/2 +10;
		princess.setPosition(WIDTH/2 - princess.getGlobalBounds().width/2,posy);

		// and the
		andthe.setString("and             the");
		andthe.setFont(EG);
		andthe.setCharacterSize(20);
		posy = 3*princess.getGlobalBounds().height/2 +10 + andthe.getGlobalBounds().height/2;
		andthe.setPosition(WIDTH/2 - andthe.getGlobalBounds().width/2 + 10,posy+10);

		// dystopia
		dystopia.setString("DYSTOPIA");
		dystopia.setFont(day28);
		dystopia.setCharacterSize(75);
		posy = 3*princess.getGlobalBounds().height/2 +10 + 3*andthe.getGlobalBounds().height/2 + dystopia.getGlobalBounds().height/2;
		dystopia.setPosition(WIDTH/2 - princess.getGlobalBounds().width/2,posy-20);

		/// BUTTON ///

		// play
		play.setString("PLAY");
		play.setFont(EG);
		play.setCharacterSize(30);
		play.setPosition(WIDTH/2 - play.getGlobalBounds().width/2,540);
		play.setOutlineColor(Color::Black);
        play.setOutlineThickness(1);

        // high score
        highscore.setString("HIGH SCORE");
		highscore.setFont(EG);
		highscore.setCharacterSize(30);
		highscore.setPosition(WIDTH/2 - highscore.getGlobalBounds().width/2,700);
		highscore.setOutlineColor(Color::Black);
        highscore.setOutlineThickness(1);

        // how to play
        howtoplay.setString("GUIDE");
        howtoplay.setFont(EG);
		howtoplay.setCharacterSize(30);
		howtoplay.setPosition(WIDTH/2 - howtoplay.getGlobalBounds().width/2,620);
		howtoplay.setOutlineColor(Color::Black);
        howtoplay.setOutlineThickness(1);

        // exit
        exit.setString("EXIT");
		exit.setFont(EG);
		exit.setCharacterSize(30);
		exit.setPosition(WIDTH/2 - exit.getGlobalBounds().width/2,780);
		exit.setOutlineColor(Color::Black);
        exit.setOutlineThickness(1);

        // myname
        myname.setString("Pattamon       Pongsakornpisit      64010574");
		myname.setFont(barbaro);
		myname.setCharacterSize(18);
		myname.setPosition(WIDTH - myname.getGlobalBounds().width - 50,HEIGHT - 50);
		myname.setOutlineColor(Color::Black);
        myname.setOutlineThickness(1);
	}

	void MainMenuState::HandleInput()
	{
		Event event;

		while (this->Data->app.pollEvent(event))
		{
			// Play
			if(event.key.code == Keyboard::Enter)
            {
                // game start
                if(username.length() > 0)
                {
                    Data->machine.AddState(StateRef(new GameState(Data,username)),true);
                }
                else
                {
                    type.setColor(Color::White);
                    delay.restart();
                }
            }

			if (event.type == Event::Closed)
			{
				this->Data->app.close();
			}

            if(play.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                play.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    // game start
                    if(username.length() > 0)
                    {
                        Data->machine.AddState(StateRef(new GameState(Data,username)),true);
                    }
                    else
                    {
                        type.setColor(Color::White);
                        delay.restart();
                    }
                }
                else
                {
                    type.setColor(Color::White);
                    delay.restart();
                }
            }
            else
            {
                play.setFillColor(Color::White);
            }

            // High Score
            if(highscore.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                highscore.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    // high score page
                    if(gotname&&gotpoint)
                    {
                        Data->machine.AddState(StateRef(new LeaderBoardState(Data,USERNAME,SCORE,1,1)),true);
                    }
                    else
                    {
                        Data->machine.AddState(StateRef(new LeaderBoardState(Data,"anonymous",0,0,0)),true);
                    }
                }
            }
            else
            {
                highscore.setFillColor(Color::White);
            }

            // How To Play
            if(howtoplay.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                howtoplay.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    // guide page
                    Data->machine.AddState(StateRef(new GuideState(Data)),true);
                }
            }
            else
            {
                howtoplay.setFillColor(Color::White);
            }

            // press EXIT to close
            if(exit.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                exit.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left)) this->Data->app.close();
            }
            else
            {
                exit.setFillColor(Color::White);
            }

            // input USER NAME
            if (event.type == Event::TextEntered)
            {
                // Handle ASCII characters only
                if (event.text.unicode < 128 && event.text.unicode != 13)
                {
                    if(event.text.unicode == 8)
                    {
                        if(username.length() > 0)
                        {
                            username.pop_back();
                        }
                    }
                    else
                    {
                        username += static_cast<char>(event.text.unicode);
                    }
                    name.setString(username);
                }
            }
		}

		if(delay.getElapsedTime().asSeconds() > 0.5)
        {
            type.setColor(Color(80,80,80));
            delay.restart();
        }
	}

	void MainMenuState::Update(float dt)
	{
	    name.setString(username);
        name.setPosition(WIDTH /2 - name.getGlobalBounds().width / 2,375);
	}

	void MainMenuState::Draw(float dt)
	{
		this->Data->app.clear();

		this->Data->app.draw(background);
		this->Data->app.draw(princess);
		this->Data->app.draw(andthe);
		this->Data->app.draw(dystopia);

		if(username.length() == 0)
        {
            this->Data->app.draw(type);
        }
        else
        {
            this->Data->app.draw(name);
        }

		this->Data->app.draw(play);
		this->Data->app.draw(highscore);
		this->Data->app.draw(howtoplay);
		this->Data->app.draw(exit);
		this->Data->app.draw(myname);

		this->Data->app.display();
	}
}
