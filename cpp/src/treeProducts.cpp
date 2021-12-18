#include "../include/cppJoshi_bits/treeProducts.hpp"

TreeProduct::TreeProduct(double finalTime) : finalTime(finalTime)
{
}

double TreeProduct::getFinalTime() const
{
    return finalTime;
}