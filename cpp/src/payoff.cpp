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