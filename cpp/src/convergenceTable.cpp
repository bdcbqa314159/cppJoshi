#include "../include/cppJoshi_bits/convergenceTable.hpp"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC> &inner) : inner(inner), stoppingPoint(2), pathsDone(0)
{
}

StatisticsMC *ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::dumpOneResult(double result)
{
    inner->dumpOneResult(result);
    pathsDone++;

    if (pathsDone == stoppingPoint)
    {
        stoppingPoint *= 2;
        std::vector<std::vector<double>> thisResult(inner->getResultsSoFar());

        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(pathsDone);
            resultsSoFar.push_back(thisResult[i]);
        }
    }

    return;
}

std::vector<std::vector<double>> ConvergenceTable::getResultsSoFar() const
{
    std::vector<std::vector<double>> tmp(resultsSoFar);

    if (pathsDone * 2 != stoppingPoint)
    {
        std::vector<std::vector<double>> thisResult(inner->getResultsSoFar());

        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(pathsDone);
            tmp.push_back(thisResult[i]);
        }
    }
    return tmp;
}