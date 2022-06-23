#include "Viewtrix.h"
#include "MatrixDirector.h"

#include <iostream>

namespace vtrx
{
    Viewtrix *Viewtrix::singleton = nullptr;

    Viewtrix *Viewtrix::getInstance()
    {
        return singleton;
    }

    void Viewtrix::init(LedControl *&lc)
    {
        if (singleton == nullptr)
            singleton = new Viewtrix(lc);
    }

    void Viewtrix::update(unsigned long millis)
    {
        if (!firstUpdate)
        {
            oldTime = millis;
            firstUpdate = true;
            return;
        }

        MatrixDirector *director = MatrixDirector::getInstance();

        director->update(float((millis - oldTime) / 1000.f));
        director->draw();

        uint8_t mcount = getMatrixCount();

        for (uint8_t m = 0; m < mcount; m++)
            for (uint8_t r = 0; r < height; r++)
            {
                lc->setRow(m, r, render[m * height + r]);
                render[m * height + r] = 0;
            }

        oldTime = millis;
    }
} // namespace vtrx