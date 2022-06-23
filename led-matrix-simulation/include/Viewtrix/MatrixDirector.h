#ifndef MatrixDirector_h
#define MatrixDirector_h

#include <cstdint>

#include "Display.h"

namespace vtrx
{
    class MatrixDirector
    {
    protected:
        MatrixDirector() : currentDisplay(nullptr),
                           pendingDisplay(nullptr) {}

        static MatrixDirector *singleton;

        Display *currentDisplay;
        Display *pendingDisplay;

    public:
        MatrixDirector(MatrixDirector &other) = delete;
        void operator=(const MatrixDirector &) = delete;

        static MatrixDirector *getInstance();

        void update(float dt);
        void draw();

        void replaseScene(Display *nextDisplay);
        void runWithScene(Display *display);
    };
} // namespace vtrx

#endif