#ifndef TREEAMERICAN_H
#define TREEAMERICAN_H

#include "treeProducts.hpp"
#include "payoffBridge.hpp"

class TreeAmerican : public TreeProduct
{
public:
    TreeAmerican(double finalTime, const PayoffBridge &thePayoff);
    virtual TreeProduct *clone() const;
    virtual double finalPayoff(double spot) const;
    virtual double preFinalValue(double spot, double time, double discountedFutureValue) const;
    virtual ~TreeAmerican() {}

private:
    PayoffBridge thePayoff;
};

#endif