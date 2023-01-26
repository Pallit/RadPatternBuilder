#ifndef RADPATTERN_H
#define RADPATTERN_H


class RadPattern
{
public:
    virtual double getPattern(double thetaX, double thetaY) { return 0; };
    virtual ~RadPattern() = default;
    void init();
};

class RadLinearPattern: public RadPattern{
private:
    double m_d;
    int m_n;
    double m_freq;
public:
    RadLinearPattern(double d, int n, double freq);
    ~RadLinearPattern() override = default;
    double getPattern(double thetaX, double thetaY) override;
};

class RadFlatPattern: public RadPattern{
private:
    double m_dX;
    double m_dY;
    int m_nX;
    int m_nY;
    RadLinearPattern m_rlpX;
    RadLinearPattern m_rlpY;
public:
    RadFlatPattern(double dX, double dY, int nX, int nY, double freq);
    ~RadFlatPattern() override = default;
    double getPattern(double thetaX, double thetaY) override;
};
    /*
private:
    double m_dX;
    double m_dY;
    int m_nX;
    int m_nY;
    double m_freq;
public:
    RadPattern(double dX, double dY, int nX, int nY, double freq);
    double getFlatPattern(double thetaX, double thetaY) const;
    double getLinearPattern(double theta, double n, double d) const;
    double getArcPattern(int M, int N) const;
};

*/
#endif //RADPATTERN_H
