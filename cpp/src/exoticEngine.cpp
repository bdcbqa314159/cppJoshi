#include "../include/cppJoshi_bits/exoticEngine.hpp"

#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent> &theProduct, const Parameters &r) : theProduct(theProduct), r(r), discounts(theProduct->possibleCashFlowTimes())
{

    for (unsigned long i = 0; i < discounts.getSize(); i++)
    {
        discounts[i] = exp(-r.Integral(0., discounts[i]));
    }

    theseCashFlows.resize(theProduct->maxNumberOfCashFlows());
}

void ExoticEngine::doSimulation(StatisticsMC &theGatherer, unsigned long numberOfPaths)
{
    Array spotValues(theProduct->getLookAtTimes().getSize());
    theseCashFlows.resize(theProduct->maxNumberOfCashFlows());

    double thisValue{};

    for (unsigned long i{}; i < numberOfPaths; i++)
    {
        getOnePath(spotValues);
        thisValue = doOnePath(spotValues);
        theGatherer.dumpOneResult(thisValue);
    }

    return;
}

double ExoticEngine::doOnePath(const Array &spotValues) const
{
    unsigned long numberFlows = theProduct->cashFlows(spotValues, theseCashFlows);
    double value{};
    for (unsigned long i{}; i < numberFlows; i++)
    {
        value += theseCashFlows[i].amount * discounts[theseCashFlows[i].timeIndex];
    }

    return value;
}