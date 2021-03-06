#include "../include/cppJoshi_bits/payoff.hpp"
#include <algorithm>

Payoff1::Payoff1(double strike, optionType theOptionType) : strike(strike), strikeDD(0.), theOptionType(theOptionType)
{
}

Payoff1::Payoff1(double strike, double strikeDD, optionType theOptionType) : strike(strike), strikeDD(strikeDD), theOptionType(theOptionType)
{
}

double Payoff1::operator()(double spot) const
{

    switch (theOptionType)
    {
    case call:
        return std::max(spot - strike, 0.);

    case put:
        return std::max(strike - spot, 0.);

    case digitalCall:
        return 1. * (spot > strike);

    case digitalPut:
        return 1. * (strike > spot);

    case doubleDigital:
        return 1. * (spot > std::min(strike, strikeDD) && spot < std::max(strike, strikeDD));

    default:
        throw("unknow option type found.");
    }
}

PayoffCall2::PayoffCall2(double strike) : strike(strike)
{
}

double PayoffCall2::operator()(double spot) const
{
    return std::max(spot - strike, 0.);
}

PayoffPut2::PayoffPut2(double strike) : strike(strike)
{
}

double PayoffPut2::operator()(double spot) const
{

    return std::max(strike - spot, 0.);
}

PayoffCall3::PayoffCall3(double strike) : strike(strike)
{
}

double PayoffCall3::operator()(double spot) const
{
    return std::max(spot - strike, 0.);
}

PayoffCall3 *PayoffCall3::clone() const
{
    return new PayoffCall3(*this);
}

PayoffPut3::PayoffPut3(double strike) : strike(strike)
{
}

double PayoffPut3::operator()(double spot) const
{
    return std::max(strike - spot, 0.);
}

PayoffPut3 *PayoffPut3::clone() const
{
    return new PayoffPut3(*this);
}