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

#endif