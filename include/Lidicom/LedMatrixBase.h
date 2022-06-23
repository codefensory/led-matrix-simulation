#ifndef LedMatrixBase_h
#define LedMatrixBase_h

#include <cstdint>

#include <LedControl.h>

namespace ldcom
{
    class LedMatrixBase
    {
    protected:
        LedControl *lc;
        uint8_t *matrixBytes;

        virtual void updateRow(uint8_t matrix, uint8_t row, uint8_t val) const;

    public:
        LedMatrixBase(LedControl *lc) : lc(lc)
        {
            matrixBytes = new uint8_t[getMatrixCount() * 8];
        }

        uint8_t width() { return 8; }
        uint8_t height() { return 8; }
        uint8_t getMatrixCount() { return lc->getDeviceCount(); }

        void draw(uint8_t matrix, uint8_t row, uint8_t val);
        void update();
    };
} // namespace ldcom

#endif