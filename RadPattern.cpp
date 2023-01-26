#include "RadPattern.h"
#include <fstream>
#include <cmath>
#define c 299792458

RadLinearPattern::RadLinearPattern(double d, int n, double freq)
    : m_d(d), m_n(n), m_freq(freq)
{}

double RadLinearPattern::getPattern(double az, double el)
{
    if (az == 0)
        return 1;
    double k = 2 * M_PI * m_freq / c;
    return (sin(m_n * k * m_d * 0.5 * sin(az))) / (m_n * sin(k * m_d * 0.5 * sin(az)));
}

void RadLinearPattern::drowAntenna()
{
    std::ofstream antenna("../antenna.dat");
    for (int i = 0; i <= m_n; ++i){
        antenna << 0 << " " << i * m_d - 0.5 * (m_n - 1) * m_d << " " <<  0 << '\n';
    }
    antenna.close();
}

RadFlatPattern::RadFlatPattern(double dX, double dY, int nX, int nY, double freq)
    : m_dX(dX), m_dY(dY), m_nX(nX), m_nY(nY), m_rlpX(RadLinearPattern(dX, nX, freq)), m_rlpY(RadLinearPattern(dY, nY, freq))
{}

double RadFlatPattern::getPattern(double az, double el)
{
    return m_rlpX.getPattern(az, el) * m_rlpY.getPattern(el, az);
}
void RadFlatPattern::drowAntenna()
{
    std::ofstream antenna("../antenna.dat");
    for (int i = 0; i < m_nX; ++i)
        for (int j = 0; j < m_nY; ++j){
            antenna << 0 << " " << j * m_dY - 0.5 * (m_nY - 1) * m_dY << " " << i * m_dX - 0.5 * (m_nX - 1) * m_dX << '\n';
        }
    antenna.close();
}

void RadPattern::init()
{
    std::ofstream data("../data.dat");
    for (int i = -180; i <= 180; ++i) {
        for (int j = -180; j <= 180; ++j) {
            double r = getPattern(i * M_PI / 180., j * M_PI / 180.);
            double v = i * M_PI / 180.;
            double u = j * M_PI / 180.;
            data << r * cos(v) * cos(u) << " " << r * cos(v) * sin(u) << " " << r * sin(v) << '\n';
        }
    }
    drowAntenna();
    system("cd ../ \n gnuplot out.p");
    data.close();
}
