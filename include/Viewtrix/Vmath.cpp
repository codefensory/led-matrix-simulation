#include "Vmath.h"

#include <cstdint>

namespace vtrx
{
    uint8_t Vmath::getLenghtByte(unsigned char v)
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

    uint8_t Vmath::getMaxLengthByte(const uint8_t *v)
    {
        uint8_t lengthFont = 0;

        for (int i = 0; i < 8; i++)
        {
            uint8_t l = getLenghtByte(v[i]);
            lengthFont = (l > lengthFont) ? l : lengthFont;
        }

        return lengthFont;
    }
} // namespace vtrx