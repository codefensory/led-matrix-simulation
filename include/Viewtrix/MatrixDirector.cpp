#include "MatrixDirector.h"

namespace vtrx
{
    MatrixDirector *MatrixDirector::singleton = nullptr;

    MatrixDirector *MatrixDirector::getInstance()
    {
        if (singleton == nullptr)
            singleton = new MatrixDirector();

        return singleton;
    }

    void MatrixDirector::update(float dt)
    {
        if (currentDisplay != nullptr)
            currentDisplay->preupdate(dt);
    }

    void MatrixDirector::draw()
    {
        if (currentDisplay != nullptr)
            currentDisplay->draw();
    }

    void MatrixDirector::replaseScene(Display *nextDisplay)
    {
        delete currentDisplay;

        currentDisplay = nextDisplay;
    }

    void MatrixDirector::runWithScene(Display *display)
    {
        currentDisplay = display;
    }
} // namespace vtrx