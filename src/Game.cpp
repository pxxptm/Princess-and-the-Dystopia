#include "Game.h"
#include "SplashState.h"

#include <stdlib.h>
#include <time.h>

using namespace sf;

namespace owner
{
    Game::Game(int W,int H,string title)
    {
        srand(time(NULL));

        data->app.create(VideoMode(W,H),title,Style::Close|Style::Titlebar);
        data->machine.AddState(StateRef(new SplashState(this->data)));
        this->Run();
    }

    void Game::Run()
    {
        float newTime;
        float frameTime;
        float interpolation;

        float currentTime = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->data->app.isOpen())
        {
            this->data->machine.ProcessStateChanges();

            newTime = this->clock.getElapsedTime().asSeconds();

            frameTime = newTime - currentTime;

            if(frameTime > 0.2f)
            {
                frameTime = 0.2;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while(accumulator >= dt)
            {
                this->data->machine.GetActiveState()->HandleInput();
                this->data->machine.GetActiveState()->Update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
