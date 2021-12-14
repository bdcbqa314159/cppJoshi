#ifndef VANILLA_H
#define VANILLA_H

#include "payoff.hpp"

class VanillaOption1
{

public:
    VanillaOption1(Payoff2 &thePayoff, double expiry);
    double getExpiry() const;
    double OptionPayoff(double spot) const;

private:
    double expiry;
    Payoff2 &thePayoff;
};

#endif