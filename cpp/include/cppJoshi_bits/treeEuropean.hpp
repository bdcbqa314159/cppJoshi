#ifndef TREEEUROPEAN_H
#define TREEEUROPEAN_H

#include "treeProducts.hpp"
#include "payoffBridge.hpp"

class TreeEuropean : public TreeProduct
{
public:
    TreeEuropean(double finalTime, const PayoffBridge &thePayoff);
    virtual TreeProduct *clone() const;
    virtual double finalPayoff(double spot) const;
    virtual double preFinalValue(double spot, double time, double discountedFutureValue) const;
    virtual ~TreeEuropean() {}

private:
    PayoffBridge thePayoff;
};

#endif