#include "../include/cppJoshi_bits/binomialTree.hpp"
#include "../include/cppJoshi_bits/arrays.hpp"

#include <cmath>

SimpleBinomialTree::SimpleBinomialTree(double spot, const Parameters &r, const Parameters &d, double vol, unsigned long steps, double time) : spot(spot), r(r), d(d), vol(vol), steps(steps), time(time), discounts(steps), treeBuilt(false)
{
}

void SimpleBinomialTree::buildTree()
{
    treeBuilt = true;
    theTree.resize(steps + 1);
    double initialLogSpot = log(spot);

    for (unsigned long i = 0; i <= steps; i++)
    {
        theTree[i].resize(i + 1);
        double thisTime = (i * time) / steps;
        double movedLogSpot = initialLogSpot + r.Integral(0., thisTime) - d.Integral(0., thisTime);

        movedLogSpot -= 0.5 * vol * vol * thisTime;
        double sd = vol * sqrt(time / steps);

        for (long j = -static_cast<long>(i), k = 0; j <= static_cast<long>(i); j = j + 2, k++)
        {
            theTree[i][k].first = exp(movedLogSpot + j * sd);
        }
    }

    for (unsigned long l = 0; l < steps; l++)
    {
        discounts[l] = exp(-r.Integral(l * time / steps, (l + 1) * time / steps));
    }
}

double SimpleBinomialTree::getThePrice(const TreeProduct &theProduct)
{

    if (!treeBuilt)
    {
        buildTree();
    }

    if (theProduct.getFinalTime() != time)
    {
        throw("mismatched product in SimpleBinomialTree");
    }

    for (long j = -static_cast<long>(steps), k = 0; j <= static_cast<long>(steps); j = j + 2, k++)
    {
        theTree[steps][k].second = theProduct.finalPayoff(theTree[steps][k].first);
    }

    for (unsigned long i = 1; i <= steps; i++)
    {
        unsigned long index = steps - i;
        double thisTime = index * time / steps;

        for (long j = -static_cast<long>(index), k = 0; j <= static_cast<long>(index); j = j + 2, k++)
        {
            double spot = theTree[index][k].first;
            double futureDiscountedValue = 0.5 * discounts[index] * (theTree[index + 1][k].second + theTree[index + 1][k + 1].second);
            theTree[index][k].second = theProduct.preFinalValue(spot, thisTime, futureDiscountedValue);
        }
    }

    return theTree[0][0].second;
}