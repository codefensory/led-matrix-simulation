#include <cstring>
#include <cstdlib>
#include <bitset>
#include <math.h>

#include <iostream>

#include <Lidicom/Canvas.h>
#include <Lidicom/Canvas/Font5px.h>
#include <Lidicom/Canvas/Rect.h>
#include <Lidicom/LedMatrixBase.h>

using namespace ldcom;

Canvas::Canvas(LedMatrixBase *baseMatrix, uint8_t layersCount) : lmc(baseMatrix)
{
    if (layersCount <= 0)
        layersCount = 1;

    this->layersCount = layersCount;
    matrixByteLayers = new uint8_t *[layersCount];

    for (uint8_t i = 0; i < layersCount; i++)
        matrixByteLayers[i] = new uint8_t[matrixCount() * width()]{0};
}

void Canvas::setRectangle(Rect rect, bool active, uint8_t layer)
{
    int8_t x = rect.x;
    int8_t y = rect.y;
    int8_t w = rect.width;
    int8_t h = rect.height;

    int8_t xTarget = x + w;
    int8_t yTarget = y + h;
    int8_t matrixTarget = xTarget / width();
    int8_t normalTargetPos = xTarget - (matrixTarget * width());

    uint8_t mc = abs(matrixTarget - x / width()) + 1;

    for (uint8_t r = 0; r < abs(h); r++)
    {
        int nx = x;

        int nr = r + y;

        for (uint8_t c = 0; c < mc; c++)
        {
            int8_t matrix = nx / width();
            int8_t normalPos = nx - (matrix * width());
            int8_t diference = xTarget - nx;

            bool isHigher = diference >= 0;
            diference = abs(diference);

            uint8_t v = 255 >> 8 - (diference > 8 ? 8 : diference);

            if (diference < 8)
                v <<= 8 - (isHigher ? normalTargetPos : normalPos);

            if (active)
                matrixByteLayers[layer][matrix * width() + nr] |= v;
            else
                matrixByteLayers[layer][matrix * width() + nr] &= ~v;

            nx = isHigher ? nx + (8 - normalPos) : nx - 1 - normalPos;
        }

        y = (h > 0) ? y + 1 : y - 1;
    }
}

Rect Canvas::drawText(const char *v, int x, int y, uint8_t layer)
{
}

Rect Canvas::drawRectangle(Rect rect, uint8_t layer)
{
    setRectangle(rect, true, layer);
    return rect;
}

Rect Canvas::drawPixel(int x, int y, bool value, uint8_t layer)
{
    uint8_t matrix = x / width();
    uint8_t normalPos = x - (matrix * width());
    uint8_t pixel = pow(2, 7 - normalPos);

    if (value)
        matrixByteLayers[layer][matrix * width() + y] |= pixel;
    else
        matrixByteLayers[layer][matrix * width() + y] &= ~pixel;

    return Rect(x, y, 1, 1);
}

void Canvas::clear(uint8_t layer)
{
    for (int i = 0; i < matrixCount() * width(); i++)
        matrixByteLayers[layer][i] = 0;
}

void Canvas::clear(Rect rect, uint8_t layer)
{
    setRectangle(rect, false, layer);
}

void Canvas::clearAll()
{
    for (uint8_t i = 0; i < layersCount; i++)
        clear(i);
}