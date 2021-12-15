#include "../include/cppJoshi_bits/mcStatistics.hpp"

StatisticsMean::StatisticsMean() : runningSum(0), pathsDone(0UL)
{
}

void StatisticsMean::dumpOneResult(double result)
{
    pathsDone++;
    runningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::getResultsSoFar() const
{
    std::vector<std::vector<double>> results(1);

    results[0].resize(1);
    results[0][0] = runningSum / pathsDone;

    return results;
}

StatisticsMC *StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}