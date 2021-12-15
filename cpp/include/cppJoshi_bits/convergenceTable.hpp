#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "mcStatistics.hpp"
#include "wrapper.hpp"

class ConvergenceTable : public StatisticsMC
{

public:
    ConvergenceTable(const Wrapper<StatisticsMC> &inner);
    virtual StatisticsMC *clone() const;
    virtual void dumpOneResult(double result);
    virtual std::vector<std::vector<double>> getResultsSoFar() const;

private:
    Wrapper<StatisticsMC> inner;
    std::vector<std::vector<double>> resultsSoFar;
    unsigned long stoppingPoint;
    unsigned long pathsDone;
};

#endif