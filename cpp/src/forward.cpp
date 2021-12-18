#include "../include/cppJoshi_bits/forward.hpp"

double PayoffForward::operator()(double spot) const
{
    return spot - strike;
}

PayoffForward::PayoffForward(double strike) : strike(strike)
{
}

Payoff3 *PayoffForward::clone() const
{
    return new PayoffForward(*this);
}