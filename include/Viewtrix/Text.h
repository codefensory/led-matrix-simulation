#ifndef Text_h
#define Text_h

#include "Node.h"

namespace vtrx
{
    class Text : public Node
    {
    private:
    protected:
        uint8_t count;

        Text() : text(new char[0]), count(0)
        {
        }
        ~Text()
        {
            delete[] text;
        }

        virtual void draw(uint8_t *render, const uint8_t width, const uint8_t height, const uint8_t mcount) override;

    public:
        void updateText(const char *nText);
        char *text;
        static Text *create();
    };
} // namespace vtrx

#endif