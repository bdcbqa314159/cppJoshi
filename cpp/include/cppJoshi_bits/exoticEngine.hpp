#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H

#include "wrapper.hpp"
#include "parameters.hpp"
#include "pathDependent.hpp"
#include "mcStatistics.hpp"

#include <vector>

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent> &theProduct, const Parameters &r);

    virtual void getOnePath(Array &spotValues) = 0;
    void doSimulation(StatisticsMC &theGatherer, unsigned long numberOfPaths);
    virtual ~ExoticEngine() {}
    double doOnePath(const Array &spotValues) const;

private:
    Wrapper<PathDependent> theProduct;
    Parameters r;
    Array discounts;
    mutable std::vector<CashFlow> theseCashFlows;
};

#endif