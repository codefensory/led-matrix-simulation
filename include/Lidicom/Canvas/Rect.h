#ifndef Rect_h
#define Rect_h

namespace vtrx
{
    class Rect
    {
    public:
        int x;
        int y;
        int width;
        int height;

        Rect(int x, int y, int width, int height)
        {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }
    };
} // namespace vtrx

#endif