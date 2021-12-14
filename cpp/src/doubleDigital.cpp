#include "../include/cppJoshi_bits/doubleDigital.hpp"
#include <algorithm>

PayoffDoubleDigital2::PayoffDoubleDigital2(double lowerLevel, double upperLevel) : lowerLevel(lowerLevel), upperLevel(upperLevel)
{
}

double PayoffDoubleDigital2::operator()(double spot) const
{
    if (spot <= lowerLevel)
    {
        return 0.;
    }

    if (spot >= upperLevel)
    {
        return 0.;
    }

    return 1.;
}

PayoffDoubleDigital3::PayoffDoubleDigital3(double lowerLevel, double upperLevel) : lowerLevel(lowerLevel), upperLevel(upperLevel)
{
}

double PayoffDoubleDigital3::operator()(double spot) const
{
    if (spot <= lowerLevel)
    {
        return 0.;
    }

    if (spot >= upperLevel)
    {
        return 0.;
    }

    return 1.;
}

PayoffDoubleDigital3 *PayoffDoubleDigital3::clone() const
{
    return new PayoffDoubleDigital3(*this);
}