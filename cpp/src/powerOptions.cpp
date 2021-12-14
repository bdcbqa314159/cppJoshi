#include "../include/cppJoshi_bits/powerOptions.hpp"
#include <algorithm>
#include <cmath>

PayoffPowerCall2::PayoffPowerCall2(double strike, int power) : strike(strike), power(power)
{
}

double PayoffPowerCall2::operator()(double spot) const
{
    return std::max(pow(spot, power) - strike, 0.);
}

PayoffPowerPut2::PayoffPowerPut2(double strike, int power) : strike(strike), power(power)
{
}

double PayoffPowerPut2::operator()(double spot) const
{
    return std::max(strike - pow(spot, power), 0.);
}
