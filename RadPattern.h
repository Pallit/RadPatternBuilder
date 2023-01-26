#ifndef RADPATTERN_H
#define RADPATTERN_H


class RadPattern
{
public:
    //! \n Radiation pattern function of direction
    //! \param az azimuth
    //! \param el elevation
    //! \return antenna gain
    virtual double getPattern(double thetaX, double thetaY) { return 0; };

    virtual ~RadPattern() = default;

    //! radiation pattern visualization
    void init();
};

class RadLinearPattern: public RadPattern{
private:
    double m_d;
    int m_n;
    double m_freq;
public:
    //! \param d distance between array elements
    //! \param n number of elements
    //! \param freq radiation frequency
    RadLinearPattern(double d, int n, double freq);

    ~RadLinearPattern() override = default;

    double getPattern(double az, double el) override;
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
    //! \param dX x-axis distance between array elements
    //! \param dY y-axis distance between array elements
    //! \param nX x-axis number of elements
    //! \param nY y-axis number of elements
    //! \param freq radiation frequency
    RadFlatPattern(double dX, double dY, int nX, int nY, double freq);

    ~RadFlatPattern() override = default;

    double getPattern(double az, double el) override;
};

#endif //RADPATTERN_H
