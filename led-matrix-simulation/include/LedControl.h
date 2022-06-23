#ifndef LedControl_h
#define LedControl_h

#define WIDTH 8
#define HEIGHT 8

#include <SFML/Graphics.hpp>

using namespace std;

class LedControl : public sf::Drawable
{
    int horizontalCount = 4;

    sf::VertexArray vertexArray;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    
    void begin();

    void setLed(int matrix, int x, int y, bool v);
    void setRow(int matrix, int row, unsigned char v);

    uint8_t getDeviceCount();
};

#endif