#ifndef Draw_h
#define Draw_h

#include <cstdint>

#include <Lidicom/LedMatrixBase.h>
#include <Lidicom/Canvas/Rect.h>

namespace ldcom
{
    class Draw
    {
    private:
        static uint8_t getLenghtByte(uint8_t v);
        static uint8_t getMaxLengthByte(const uint8_t v[]);

    public:
        static Rect createText(LedMatrixBase &lm, const char *v, int x, int y);
    };
} // namespace ldcom

#endif