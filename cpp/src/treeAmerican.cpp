#include "treeAmerican.hpp"
#include <algorithm>

TreeAmerican::TreeAmerican(double finalTime, const PayoffBridge &thePayoff) : TreeProduct(finalTime), thePayoff(thePayoff)
{
}

TreeProduct *TreeAmerican::clone() const
{
    return new TreeAmerican(*this);
}

double TreeAmerican::finalPayoff(double spot) const
{
    return thePayoff(spot);
}

double TreeAmerican::preFinalValue(double spot, double time, double discountedFutureValue) const
{
    return std::max(thePayoff(spot), discountedFutureValue);
}