#include <cstring>
#include <cstdlib>

#include "Rectangle.h"

#include "Vmath.h"
#include "Font5px.h"

#include <iostream>

namespace vtrx
{
    Rectangle *Rectangle::create()
    {
        Rectangle *nt = new Rectangle();
        nt->init();
        return nt;
    }

    void Rectangle::setSize(int8_t width, int8_t height)
    {
        rwidth = width;
        rheight = height;
    }

    void Rectangle::setSizeWidth(int8_t width)
    {
        rwidth = width;
    }

    void Rectangle::setSizeHeight(int8_t height)
    {
        rheight = height;
    }

    void Rectangle::draw(uint8_t *render, const uint8_t width, const uint8_t height, const uint8_t mcount)
    {
        int8_t x = getPosition().x;
        int8_t y = getPosition().y;

        int8_t w = rwidth;
        int8_t h = rheight;

        int8_t xTarget = x + w;
        int8_t yTarget = y + h;
        int8_t matrixTarget = (xTarget) / width;
        int8_t normalTargetPos = xTarget - (matrixTarget * width);

        uint8_t mc = abs(matrixTarget - x / width) + 1;
        for (uint8_t r = 0; r < abs(h); r++)
        {
            int nx = x;

            for (uint8_t c = 0; c < mc; c++)
            {
                int8_t matrix = nx / width;
                int8_t normalPos = nx - (matrix * width);
                int8_t diference = xTarget - nx;

                bool isHigher = diference >= 0;
                diference = abs(diference);

                uint8_t v = 255 >> 8 - (diference > 8 ? 8 : diference);

                if (matrix == matrixTarget)
                    v <<= 8 - (isHigher ? normalTargetPos : normalPos);
                else
                    v >>= normalPos;

                render[matrix * width + y] |= v;

                nx = isHigher ? nx + (8 - normalPos) : nx - 1 - normalPos;
            }

            y = (h > 0) ? y + 1 : y - 1;
        }
    }

} // namespace vtrx