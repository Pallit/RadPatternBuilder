//
// Created by niyaz on 25.01.23.
//

#include "RadPattern.h"
#include <cmath>
#define c 299792458

RadPattern::RadPattern(double dX, double dY, int nX, int nY, double freq)
    : m_dX(dX), m_dY(dY), m_nX(nX), m_nY(nY), m_freq(freq)
{
}

double RadPattern::getLeniarPattern(double theta, double n, double d) const
{
    if (theta == 0)
        return 1;
    double k = 2 * M_PI * m_freq / c;
    return (sin(n * k * d * 0.5 * sin(theta))) / (n * sin(k * d * 0.5 * sin(theta)));
}

double RadPattern::getPattern(double thetaX, double thetaY) const
{
    return getLeniarPattern(thetaX, m_nX, m_dX) * getLeniarPattern(thetaY, m_nY, m_dY);
}

