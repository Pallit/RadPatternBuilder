#include "RadPattern.h"
#include <fstream>
#include <cmath>
#define c 299792458

RadLinearPattern::RadLinearPattern(double d, int n, double freq)
    : m_d(d), m_n(n), m_freq(freq)
{}

double RadLinearPattern::getPattern(double thetaX, double thetaY)
{
    if (thetaX == 0)
        return 1;
    double k = 2 * M_PI * m_freq / c;
    return (sin(m_n * k * m_d * 0.5 * sin(thetaX))) / (m_n * sin(k * m_d * 0.5 * sin(thetaX)));
}

RadFlatPattern::RadFlatPattern(double dX, double dY, int nX, int nY, double freq)
    : m_dX(dX), m_dY(dY), m_nX(nX), m_nY(nY), m_rlpX(RadLinearPattern(dX, nX, freq)), m_rlpY(RadLinearPattern(dY, nY, freq))
{}

double RadFlatPattern::getPattern(double thetaX, double thetaY)
{
    return m_rlpX.getPattern(thetaX, thetaY) * m_rlpY.getPattern(thetaY, thetaX);
}

void RadPattern::init()
{
    std::ofstream data("data.dat");
    for (int i = -180; i <= 180; ++i) {
        for (int j = -180; j <= 180; ++j) {
            double r = getPattern(i * M_PI / 180., j * M_PI / 180.);
            double v = i * M_PI / 180.;
            double u = j * M_PI / 180.;
            data << r * cos(v) * cos(u) << " " << r * cos(v) * sin(u) << " " << r * sin(v) << '\n';
        }
    }

    system("cd ../ \n gnuplot out.p");
    data.close();
}
