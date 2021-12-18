#include "treeEuropean.hpp"
#include <algorithm>

TreeEuropean::TreeEuropean(double finalTime, const PayoffBridge &thePayoff) : TreeProduct(finalTime), thePayoff(thePayoff)
{
}

TreeProduct *TreeEuropean::clone() const
{
    return new TreeEuropean(*this);
}

double TreeEuropean::finalPayoff(double spot) const
{
    return thePayoff(spot);
}

double TreeEuropean::preFinalValue(double spot, double time, double discountedFutureValue) const
{
    return discountedFutureValue;
}