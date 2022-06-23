#ifndef Rectangle_h
#define Rectangle_h

#include "Node.h"

namespace vtrx
{
    class Rectangle : public Node
    {
    private:
    protected:
        int8_t rwidth;
        int8_t rheight;

        Rectangle() : rwidth(0), rheight(0)
        {
        }

        virtual void draw(uint8_t *render, const uint8_t width, const uint8_t height, const uint8_t mcount) override;

    public:
        static Rectangle *create();

        void setSize(int8_t width, int8_t height);
        void setSizeWidth(int8_t width);
        void setSizeHeight(int8_t height);
    };
} // namespace vtrx

#endif