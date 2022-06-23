#ifndef Vector2_h
#define Vector2_h

#include <cstdint>

namespace vtrx
{
    class Vector2
    {
    public:
        int8_t x;
        int8_t y;

        Vector2(int8_t x, int8_t y) : x(x), y(y) {}

        Vector2 operator-(const Vector2 &other)
        {
            return Vector2(this->x - other.x, this->y - other.y);
        }

        Vector2 operator+(const Vector2 &other)
        {
            return Vector2(this->x + other.x, this->y + other.y);
        }
    };
} // namespace vtrx

#endif