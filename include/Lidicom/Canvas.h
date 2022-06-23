#ifndef Canvas_h
#define Canvas_h

#include <cstdint>

#include <Lidicom/Canvas/Rect.h>
#include <Lidicom/LedMatrixBase.h>

namespace ldcom
{
    class Canvas
    {
        bool animating;
        int delayAccumulated;

        LedMatrixBase *lmc;

        uint8_t **matrixByteLayers;

        void setRectangle(Rect rect, bool v, uint8_t layer);

    public:
        uint8_t width() { return 8; }
        uint8_t height() { return 8; }
        uint8_t matrixCount() { return lmc->getMatrixCount(); }

        uint8_t layersCount;

        Canvas(LedMatrixBase *lmc, uint8_t layersCount = 1);
        Rect drawText(const char *v, int x, int y, uint8_t layer = 0);
        Rect drawRectangle(Rect rect, uint8_t layer = 0);
        Rect drawPixel(int x, int y, bool value, uint8_t layer = 0);

        void clear(uint8_t layer = 0);
        void clear(Rect rect, uint8_t layer = 0);
        void clearAll();

        // Get bytes whit all layers merged
        uint8_t *getBytes()
        {
            uint8_t *r = new uint8_t[matrixCount() * width()]{0};

            for (uint8_t l = 0; l < layersCount; l++)
                for (int i = 0; i < matrixCount() * width(); i++)
                    r[i] |= matrixByteLayers[l][i];

            return r;
        };
    };
} // namespace ldcom
#endif