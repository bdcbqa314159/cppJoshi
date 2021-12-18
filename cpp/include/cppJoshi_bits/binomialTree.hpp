#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include "treeProducts.hpp"
#include "parameters.hpp"
#include "arrays.hpp"

#include <vector>

class SimpleBinomialTree
{

public:
    SimpleBinomialTree(double spot, const Parameters &r, const Parameters &d, double vol, unsigned long steps, double time);
    double getThePrice(const TreeProduct &theProduct);

protected:
    void buildTree();

private:
    double spot;
    Parameters r;
    Parameters d;
    double vol;
    unsigned long steps;
    double time;
    bool treeBuilt;
    std::vector<std::vector<std::pair<double, double>>> theTree;
    Array discounts;
};

#endif