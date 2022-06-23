#include <Lidicom/LedMatrixBase.h>
#include <Lidicom/Canvas.h>

using namespace ldcom;

void LedMatrixBase::updateRow(uint8_t matrix, uint8_t row, uint8_t val) const
{
    lc->setRow(matrix, row, val);
}

void LedMatrixBase::update()
{
    for (uint8_t m = 0; m < getMatrixCount(); m++)
        for (uint8_t r = 0; r < 8; r++)
            updateRow(m, r, matrixBytes[m * 8 + r]);
}

void LedMatrixBase::draw(uint8_t matrix, uint8_t row, uint8_t val)
{
}