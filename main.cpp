#include <iostream>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <time.h>

#include "Game.h"
#include "DEFINITION.h"

using namespace sf;
using namespace std;
using namespace owner;

main()
{
    srand (time(NULL));

    /// audio
    Music open;
    Music backgroundmusic;

    open.openFromFile(COLLECT);
    backgroundmusic.openFromFile(BGM);

    open.play();
    backgroundmusic.play();
    backgroundmusic.setLoop(true);

    Game(WIDTH,HEIGHT,"Princess and the Dystopia");

    system("CLS");

    return EXIT_SUCCESS;
}
