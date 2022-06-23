#include <cstring>
#include <cstdlib>

#include "Text.h"

#include "Vmath.h"
#include "Font5px.h"

namespace vtrx
{
    Text *Text::create()
    {
        Text *nt = new Text();
        nt->init();
        return nt;
    }

    void Text::updateText(const char *ntext)
    {
        if (ntext == nullptr)
            return;

        uint8_t ntLength = strlen(ntext);

        if (ntLength > count)
        {
            delete[] text;
            text = new char[ntLength];
            count = ntLength;
        }

        strcpy(text, ntext);
    }

    void Text::draw(uint8_t *render, const uint8_t width, const uint8_t height, const uint8_t mcount)
    {
        int8_t x = getPosition().x;
        int8_t y = getPosition().y;

        uint8_t lengthV = strlen(text);

        for (uint8_t c = 0; c < lengthV; c++)
        {
            const uint8_t *font = fonts5px[text[c]];

            uint8_t lenght = Vmath::getMaxLengthByte(font);

            int8_t matrixPos = x / width;
            int8_t normalPos = x - (matrixPos * width);
            int8_t toMove = 8 - lenght - normalPos;

            for (int row = 0; row < height; row++)
            {
                uint8_t fontRow = font[row];
                uint8_t mRow = row + y;

                if (mRow >= height)
                    continue;

                uint8_t rRow = toMove > 0 ? fontRow << toMove : fontRow >> abs(toMove);

                render[matrixPos * width + mRow] |= rRow;

                int8_t newNormalPos = normalPos + lenght - 8;

                if (newNormalPos > 0)
                {
                    int8_t newMatrixPos = matrixPos + 1;
                    int8_t toMove = 8 - newNormalPos;

                    rRow = fontRow << toMove;
                    render[newMatrixPos * width + mRow] |= rRow;
                }
            }

            x += lenght;

            if (c != lengthV - 1)
                x += 1; // margen
        }
    }

} // namespace vtrx