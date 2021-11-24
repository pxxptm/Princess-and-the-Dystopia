#include "Caution.h"
#include "GuideState.h"
#include "MainMenuState.h"

using namespace sf;
using namespace std;

namespace owner
{
    Caution::Caution(GameDataRef data) : Data(data)
	{

	}

	void Caution::Init()
	{
	    this->Data->assets.LoadTexture("CAUTION PIC",CAUION);
	    background.setTexture(this->Data->assets.GetTexture("CAUTION PIC"));

	    // font
	    barbaro.loadFromFile(BARBARO);

	    // back to guide
	    Back.setString("BACK");
	    Back.setCharacterSize(40);
	    Back.setFont(barbaro);
	    Back.setPosition(140,750);
	}

	void Caution::HandleInput()
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
                    Data->machine.AddState(StateRef(new GuideState(Data)),true);
                }
            }
            else
            {
                Back.setFillColor(Color::White);
            }
		}
	}

	void Caution::Update(float dt)
	{

    }

	void Caution::Draw(float dt)
	{
		this->Data->app.clear();

		this->Data->app.draw(this->background);
		Data->app.draw(Back);

		this->Data->app.display();
	}
}
