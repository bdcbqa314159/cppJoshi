#include "../include/cppJoshi_bits/vanilla.hpp"

VanillaOption1::VanillaOption1(Payoff2 &thePayoff, double expiry) : thePayoff(thePayoff), expiry(expiry)
{
}

double VanillaOption1::getExpiry() const
{
    return expiry;
}

double VanillaOption1::OptionPayoff(double spot) const
{
    return thePayoff(spot);
}