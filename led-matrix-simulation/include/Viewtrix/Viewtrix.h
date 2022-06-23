#ifndef Viewtrix_h
#define Viewtrix_h

#include <cstdint>
#include <LedControl.h>

namespace vtrx
{
    class Viewtrix
    {
    private:
        LedControl *lc;

        uint8_t width = 8;
        uint8_t height = 8;
        uint8_t *render;

        unsigned long oldTime;
        bool firstUpdate;

    protected:
        static Viewtrix *singleton;

        Viewtrix(LedControl *&lc) : lc(lc),
                                    oldTime(0),
                                    firstUpdate(false),
                                    render(new uint8_t[height * uint8_t(lc->getDeviceCount())]{0})
        {
        }

        ~Viewtrix()
        {
            delete &width, &height;
            delete[] render;
        }

    public:
        Viewtrix(Viewtrix &other) = delete;
        void operator=(const Viewtrix &) = delete;

        static Viewtrix *getInstance();
        static void init(LedControl *&lc);

        void update(unsigned long millis);
        uint8_t getMatrixCount() { return lc->getDeviceCount(); }
        uint8_t getWidth() { return width; }
        uint8_t getHeight() { return height; }

        uint8_t *getRender() { return render; }
    };
} // namespace vtrx

#endif