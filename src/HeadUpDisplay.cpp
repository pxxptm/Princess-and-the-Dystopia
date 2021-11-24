#include "HeadUpDisplay.h"
#include <string>

using namespace sf;
using namespace std;

namespace owner
{
    HeadUpDisplay::HeadUpDisplay(GameDataRef data) : Data(data)
    {
        barbaro.loadFromFile(BARBARO);

        scoretext.setFont(barbaro);
        scoretext.setCharacterSize(40);
        scoretext.setOutlineColor(Color::Black);
        scoretext.setOutlineThickness(1);
    }

    void HeadUpDisplay::ShowScore()
    {
        Data->app.draw(scoretext);
    }

    void HeadUpDisplay::UpdateScore(int score)
    {
        scoretext.setString(to_string(score));
        scoretext.setPosition(WIDTH - scoretext.getGlobalBounds().width - 100,15);
    }
}
