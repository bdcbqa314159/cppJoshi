#include "../include/cppJoshi_bits/bsCall.hpp"
#include "../include/cppJoshi_bits/blackScholesFormulas.hpp"

BSCall1::BSCall1(double r, double d, double expiry, double spot, double strike) : r(r), d(d), expiry(expiry), spot(spot), strike(strike)
{
}

double BSCall1::operator()(double vol) const
{
    return blackScholesCall(spot, strike, r, d, vol, expiry);
}