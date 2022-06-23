#include <LedControl.h>
#include <SFML/Graphics.hpp>
#include <cstddef>

int margin = 1;

void drawRectangle(sf::Vertex *quad, float x, float y, float width, float height, sf::Color color)
{
    quad[0].position = sf::Vector2f(x, y);
    quad[0].color = color;
    quad[1].position = sf::Vector2f(x + width, y);
    quad[1].color = color;
    quad[2].position = sf::Vector2f(x + width, y + height);
    quad[2].color = color;
    quad[3].position = sf::Vector2f(x, y + height);
    quad[3].color = color;
}

//Hola mundo
void LedControl::begin()
{
    vertexArray.setPrimitiveType(sf::Quads);
    vertexArray.resize(32 * 8 * 4);

    for (int y = 0; y < WIDTH; y++)
        for (int x = 0; x < WIDTH * horizontalCount; x++)
            drawRectangle(&vertexArray[(x + y * (WIDTH * horizontalCount)) * 4],
                          x * 20 + margin, y * 20,
                          19, 19, sf::Color{0x121212ff});
}

void LedControl::setLed(int m, int x, int y, bool v)
{
    x += m * WIDTH;

    drawRectangle(&vertexArray[(x + y * (WIDTH * horizontalCount)) * 4],
                  x * 20 + margin, y * 20,
                  19, 19, sf::Color{v ? 0xe81313ff : 0x121212ff});
}

void LedControl::setRow(int m, int r, unsigned char v)
{
    for (int i = 7; i >= 0; i--)
    {
        int c = v & 1;
        int x = i + (m * WIDTH);

        drawRectangle(&vertexArray[(x + r * (WIDTH * horizontalCount)) * 4],
                      x * 20 + margin, r * 20,
                      19, 19, sf::Color{c == 1 ? 0xe81313ff : 0x121212ff});

        v >>= 1;
    }
}

uint8_t LedControl::getDeviceCount()
{
    return horizontalCount;
}

void LedControl::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(vertexArray, states);
}