#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H

#include "arrays.hpp"
#include <vector>

class CashFlow
{
public:
    double amount;
    unsigned long timeIndex;
    CashFlow(unsigned long timeIndex = 0UL, double amount = 0.) : timeIndex(timeIndex), amount(amount)
    {
    }
};

class PathDependent
{
public:
    PathDependent(const Array &lookAtTimes);
    const Array &getLookAtTimes() const;
    virtual unsigned long maxNumberOfCashFlows() const = 0;
    virtual Array possibleCashFlowTimes() const = 0;
    virtual unsigned long cashFlows(const Array &spotValues, std::vector<CashFlow> &generatedFlows) const = 0;
    virtual PathDependent *clone() const = 0;
    virtual ~PathDependent() {}

private:
    Array lookAtTimes;
};

#endif
