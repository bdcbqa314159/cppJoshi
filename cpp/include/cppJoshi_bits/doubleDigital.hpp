#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H

#include "payoff.hpp"

class PayoffDoubleDigital2 : public Payoff2
{
public:
    PayoffDoubleDigital2(double lowerLevel, double upperLevel);
    virtual double operator()(double spot) const;
    virtual ~PayoffDoubleDigital2(){};

private:
    double lowerLevel;
    double upperLevel;
};

class PayoffDoubleDigital3 : public Payoff3
{

public:
    PayoffDoubleDigital3(double lowerLevel, double upperLevel);

    virtual double operator()(double spot) const;
    virtual ~PayoffDoubleDigital3() {}
    virtual PayoffDoubleDigital3 *clone() const;

private:
    double lowerLevel;
    double upperLevel;
};

#endif