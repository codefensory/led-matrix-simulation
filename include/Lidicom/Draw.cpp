#include <cstdint>
#include <cstring>

#include <Lidicom/Draw.h>
#include <Lidicom/Canvas/Rect.h>
#include <Lidicom/Canvas/Font5px.h>

using namespace ldcom;

uint8_t Draw::getLenghtByte(unsigned char v)
{
    uint8_t count = 0;
    unsigned char r = v;

    while (r > 0)
    {
        count += r & 1;
        r >>= 1;
    }

    return count;
}

uint8_t Draw::getMaxLengthByte(const uint8_t *v)
{
    uint8_t lengthFont = 0;

    for (int i = 0; i < 8; i++)
    {
        uint8_t l = getLenghtByte(v[i]);
        lengthFont = (l > lengthFont) ? l : lengthFont;
    }

    return lengthFont;
}

Rect Draw::createText(LedMatrixBase &lm, const char *v, int x, int y)
{
    int pos = x;
    uint8_t lengthV = strlen(v);
    for (int c = 0; c < lengthV; c++)
    {
        const uint8_t *font = fonts5px[v[c]];

        int lenght = getMaxLengthByte(font);

        int matrixPos = pos / lm.width();
        int normalPos = pos - (matrixPos * lm.width());
        int toMove = 8 - lenght - normalPos;

        for (int row = 0; row < lm.height(); row++)
        {
            uint8_t fontRow = font[row];
            int mRow = row + y;

            if (mRow >= lm.height())
                continue;

            uint8_t rRow = toMove > 0 ? fontRow << toMove : fontRow >> abs(toMove);
            lm.draw(matrixPos, mRow, rRow);

            int newNormalPos = normalPos + lenght - 8;

            if (newNormalPos > 0)
            {
                int nextMatrixPos = matrixPos + 1;
                int toMove = 8 - newNormalPos;
                rRow = fontRow << toMove;
                lm.draw(nextMatrixPos, mRow, rRow);
            }
        }

        pos += lenght;

        if (c != lengthV - 1)
            pos += 1; // margen
    }

    return Rect(x, y, pos, 5);
}