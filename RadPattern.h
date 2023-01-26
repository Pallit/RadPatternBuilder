//
// Created by niyaz on 25.01.23.
//

#ifndef RADPATTERN_H
#define RADPATTERN_H


class RadPattern
{
private:
    double m_dX;
    double m_dY;
    int m_nX;
    int m_nY;
    double m_freq;
    double getLeniarPattern(double theta, double n, double d) const;
public:
    RadPattern(double dX, double dY, int nX, int nY, double freq);
    double getPattern(double thetaX, double thetaY) const;
};


#endif //RADPATTERN_H
