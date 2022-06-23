#include <MainArduino.h>
#include <SFML/Graphics.hpp>

MainArduino ma;

bool first = false;

int main()
{
    ma.setup();

    // run the program as long as the window is open
    while (ma.window->isOpen())
        ma.loop();

    return 0;
}