#include "GuideState.h"
#include "MainMenuState.h"
#include "Caution.h"

using namespace sf;
using namespace std;

namespace owner
{
    GuideState::GuideState(GameDataRef data) : Data(data)
	{

	}

	void GuideState::Init()
	{
	    this->Data->assets.LoadTexture("GUIDE PIC",GUIDE);
	    background.setTexture(this->Data->assets.GetTexture("GUIDE PIC"));

	    // font
	    barbaro.loadFromFile(BARBARO);

	    // back to main menu
	    Back.setString("BACK");
	    Back.setCharacterSize(40);
	    Back.setFont(barbaro);
	    Back.setPosition(140,750);

	    // next to caution
	    // back to main menu
	    Next.setString("NEXT");
	    Next.setCharacterSize(40);
	    Next.setFont(barbaro);
	    Next.setPosition(WIDTH - 200,750);
	}

	void GuideState::HandleInput()
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

            if(Next.getGlobalBounds().contains(Mouse::getPosition(this->Data->app).x,Mouse::getPosition(this->Data->app).y))
            {
                Next.setFillColor(Color::Red);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    Data->machine.AddState(StateRef(new Caution(Data)),true);
                }
            }
            else
            {
                Next.setFillColor(Color::White);
            }
		}
	}

	void GuideState::Update(float dt)
	{

    }

	void GuideState::Draw(float dt)
	{
		this->Data->app.clear();

		this->Data->app.draw(this->background);
		this->Data->app.draw(Back);
		this->Data->app.draw(Next);

		this->Data->app.display();
	}
}
