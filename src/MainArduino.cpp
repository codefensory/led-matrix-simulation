#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <MainArduino.h>

#include <LedControl.h>
#include <Viewtrix/Viewtrix.h>
#include <Viewtrix/MatrixDirector.h>
#include <Viewtrix/Text.h>
#include <Viewtrix/Rectangle.h>

LedControl lc;
vtrx::Viewtrix *vt;
vtrx::MatrixDirector *director;
unsigned long timeMilis;

void readEvents(sf::RenderWindow *);
void draw(sf::RenderWindow *);

// Display simple para mostrar un texto
// ------- Class -------
class TextTest : public vtrx::Display
{
protected:
    TextTest() {}
    ~TextTest() {}

    void init() override;
    void update(float dt) override;

public:
    static TextTest *create();

    vtrx::Text *ltext;
    vtrx::Text *ltext2;
    vtrx::Rectangle *line;

    float time = 0;
};
//------- end Class -------
// ------- Logic -------

TextTest *TextTest::create()
{
    TextTest *t = new TextTest();
    t->init();
    return t;
}

void TextTest::init()
{
    ltext = vtrx::Text::create();
    addChild(ltext);
    ltext->updateText("12");
    ltext->setPosition(vtrx::Vector2(2, 1));

    ltext2 = vtrx::Text::create();
    addChild(ltext2);
    ltext2->updateText("3");
    ltext2->setPosition(vtrx::Vector2(10, 1));

    line = vtrx::Rectangle::create();
    addChild(line);
    line->setSize(10, 1);
    line->setPosition(vtrx::Vector2(0, 0));
}

void TextTest::update(float dt)
{
    time += dt;
    ltext->updateText(std::to_string(int(time)).c_str());
}

// ------- end Logic -------
// ------- end Display -------

// ------- Arduino main -------

void MainArduino::setup()
{
    lc.begin();

    LedControl *lcPtr = &lc;

    vtrx::Viewtrix::init(lcPtr);
    vt = vtrx::Viewtrix::getInstance();

    director = vtrx::MatrixDirector::getInstance();

    director->runWithScene(TextTest::create());
}

void MainArduino::loop()
{
    readEvents(window);

    vt->update(millis());

    draw(window);
}

//------- end Arduino main -------

void readEvents(sf::RenderWindow *window)
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::W)
            {
            }
        }
    }
}

void draw(sf::RenderWindow *window)
{
    window->draw(lc);
    window->display();
}

unsigned long MainArduino::millis()
{
    return clock.getElapsedTime().asMilliseconds();
}
