#include <SFML/Graphics.hpp>

class MainArduino
{

public:
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(641, 160), "Simulation", sf::Style::Close);
    sf::Clock clock;
    unsigned long millis();
    void setup();
    void loop();
};