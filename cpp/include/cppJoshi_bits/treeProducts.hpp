#ifndef TREEPRODUCTS_H
#define TREEPRODUCTS_H

class TreeProduct
{
public:
    TreeProduct(double FinalTime);
    virtual double finalPayoff(double spot) const = 0;
    virtual double preFinalValue(double spot, double time, double discountedFutureValue) const = 0;

    virtual ~TreeProduct() {}
    virtual TreeProduct *clone() const = 0;
    double getFinalTime() const;

private:
    double finalTime;
};

#endif