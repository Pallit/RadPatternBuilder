#include "RadPattern.h"

int main()
{
    double dX = 0.05;
    double dY = 0.05;
    int nX = 3;
    int nY = 3;
    double freq = 3e9;
    auto rflp1 = RadFlatPattern(dX, dY, nX, nY, freq);
    rflp1.init();
    return 0;
}