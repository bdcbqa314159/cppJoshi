#include "../include/cppJoshi_bits/exoticBSEngine.hpp"
#include <cmath>

void ExoticBSEngine::getOnePath(Array &spotValues)
{

    theGenerator->getGaussians(variates);
    double currentLogSpot = logSpot;

    for (unsigned long j{}; j < numberOfTimes; j++)
    {
        currentLogSpot += drifts[j];
        currentLogSpot += standardDeviations[j] * variates[j];
        spotValues[j] = exp(currentLogSpot);
    }

    return;
}

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent> &theProduct, const Parameters &r, const Parameters &d, const Parameters &vol, const Wrapper<RandomBase> &theGenerator, double spot) : ExoticEngine(theProduct, r), theGenerator(theGenerator)
{
    Array times(theProduct->getLookAtTimes());
    numberOfTimes = times.getSize();

    (this->theGenerator)->resetDimensionality(numberOfTimes);
    drifts.resize(numberOfTimes);
    standardDeviations.resize(numberOfTimes);

    double variance = vol.IntegralSquare(0, times[0]);

    drifts[0] = r.Integral(0, times[0]) - d.Integral(0., times[0]) - 0.5 * variance;

    standardDeviations[0] = sqrt(variance);

    for (unsigned long j = 1; j < numberOfTimes; j++)
    {
        double thisVariance = vol.IntegralSquare(times[j - 1], times[j]);

        drifts[j] = r.Integral(times[j - 1], times[j]) - d.Integral(times[j - 1], times[j]) - 0.5 * thisVariance;
        standardDeviations[j] = sqrt(thisVariance);
    }

    logSpot = log(spot);
    variates.resize(numberOfTimes);
}