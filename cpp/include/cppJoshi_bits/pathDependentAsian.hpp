#ifndef PATHDEPENDENTASIAN_H
#define PATHDEPENDENTASIAN_H

#include "pathDependent.hpp"
#include "payoffBridge.hpp"

class PathDependentAsian : public PathDependent
{
public:
    PathDependentAsian(const Array &lookAtTimes, double deliveryTime, const PayoffBridge &thePayOff);

    virtual unsigned long maxNumberOfCashFlows() const;
    virtual Array possibleCashFlowTimes() const;
    virtual unsigned long cashFlows(const Array &spotValues, std::vector<CashFlow> &generatedFlows) const;
    virtual ~PathDependentAsian() {}
    virtual PathDependent *clone() const;

private:
    double deliveryTime;
    PayoffBridge thePayOff;
    unsigned long numberOfTimes;
};

#endif