#ifndef Vmath_h
#define Vmath_h

#include <cstdint>

namespace vtrx
{
    class Vmath
    {
    public:
        static uint8_t getLenghtByte(uint8_t v);
        static uint8_t getMaxLengthByte(const uint8_t v[]);
    };
} // namespace vtrx

#endif