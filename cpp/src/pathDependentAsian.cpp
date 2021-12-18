#include "../include/cppJoshi_bits/pathDependentAsian.hpp"

PathDependentAsian::PathDependentAsian(const Array &lookAtTimes, double deliveryTime, const PayoffBridge &thePayOff) : PathDependent(lookAtTimes), deliveryTime(deliveryTime), thePayOff(thePayOff), numberOfTimes(lookAtTimes.getSize())
{
}

unsigned long PathDependentAsian::maxNumberOfCashFlows() const
{
    return 1UL;
}

Array PathDependentAsian::possibleCashFlowTimes() const
{
    Array tmp(1UL);
    tmp[0] = deliveryTime;
    return tmp;
}

unsigned long PathDependentAsian::cashFlows(const Array &spotValues, std::vector<CashFlow> &generatedFlows) const
{
    double sum = spotValues.sum();
    double mean = sum / numberOfTimes;
    generatedFlows[0].timeIndex = 0UL;
    generatedFlows[0].amount = thePayOff(mean);

    return 1UL;
}

PathDependent *PathDependentAsian::clone() const
{
    return new PathDependentAsian(*this);
}