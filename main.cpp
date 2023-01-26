#include <iostream>
#include <fstream>
#include "RadPattern.h"
#include <cmath>

void init(double dX, double dY, int nX, int nY, double freq){
    auto rp1 = RadPattern(dX, dY, nX, nY, freq);

    std::ofstream data("data.dat");
    for (int i = -180; i <= 180; ++i){
        for (int j = -180; j <= 180; ++j){
            double r = rp1.getPattern(i * M_PI / 180., j * M_PI / 180.);
            double v = i * M_PI / 180.;
            double u = j * M_PI / 180.;
            //data << i * M_PI / 180 << " " << j * M_PI / 180.<< " " << rp1.getPattern(i * M_PI / 180., j * M_PI / 180.) << '\n';
            data << r * cos(v) * cos(u) << " " << r * cos(v) * sin(u) << " " << r * sin(v) << '\n';
        }
    }

    system("cd ../ \n gnuplot out.p");
    data.close();
}

int main()
{
    double dX = 0.05;
    double dY = 0.05;
    int nX = 3;
    int nY = 3;
    double freq = 3e9;
    init(dX, dY, nX, nY, freq);

    return 0;
}