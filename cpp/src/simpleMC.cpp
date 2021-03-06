#include "../include/cppJoshi_bits/simpleMC.hpp"
#include "../include/cppJoshi_bits/arrays.hpp"

#include <cmath>
#include <iostream>
#include <algorithm>

double simpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths)
{
    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - strike;

        thisPayoff = thisPayoff > 0 ? thisPayoff : 0.;
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarloPut(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths)
{
    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = strike - thisSpot;

        thisPayoff = thisPayoff > 0 ? thisPayoff : 0.;
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarloDD(double expiry, double strike1, double strike2, double spot, double vol, double r, unsigned long numberOfPaths)
{

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff(0);

        if (thisSpot < std::max(strike1, strike2) && thisSpot > std::min(strike1, strike2))
        {
            thisPayoff = 1.;
        }

        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo2(const Payoff1 &thePayoff, double expiry, double spot, double vol, double r, unsigned long numberOfPaths)
{

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thePayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo2(const Payoff2 &thePayoff, double expiry, double spot, double vol, double r, unsigned long numberOfPaths)
{

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thePayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo3(const VanillaOption1 &theOption, double spot, double vol, double r, unsigned long numberOfPaths)
{

    double expiry = theOption.getExpiry();

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);

    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo3(const VanillaOption2 &theOption, double spot, double vol, double r, unsigned long numberOfPaths)
{
    double expiry = theOption.getExpiry();

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);
    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo3(const VanillaOption3 &theOption, double spot, double vol, double r, unsigned long numberOfPaths)
{
    double expiry = theOption.getExpiry();

    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrection);
    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}

double simpleMonteCarlo4(const VanillaOption3 &theOption, double spot, const Parameters &vol, const Parameters &r, unsigned long numberOfPaths)
{
    double expiry = theOption.getExpiry();

    double variance = vol.IntegralSquare(0, expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r.Integral(0, expiry) + itoCorrection);
    double thisSpot(0);
    double runningSum(0);

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / numberOfPaths;
    mean *= exp(-r.Integral(0, expiry));

    return mean;
}

void simpleMonteCarlo5(const VanillaOption3 &theOption, double spot, const Parameters &vol, const Parameters &r, unsigned long numberOfPaths, StatisticsMC &gatherer)
{
    double expiry = theOption.getExpiry();

    double variance = vol.IntegralSquare(0, expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r.Integral(0, expiry) + itoCorrection);
    double thisSpot(0);
    double discounting = exp(-r.Integral(0, expiry));

    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        gatherer.dumpOneResult(thisPayoff * discounting);
    }

    return;
}

void simpleMonteCarlo6(const VanillaOption3 &theOption, double spot, const Parameters &vol, const Parameters &r, unsigned long numberOfPaths, StatisticsMC &gatherer, RandomBase &generator)
{
    generator.resetDimensionality(1);

    double expiry = theOption.getExpiry();
    double variance = vol.IntegralSquare(0, expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r.Integral(0, expiry) + itoCorrection);
    double thisSpot(0);
    double discounting = exp(-r.Integral(0, expiry));

    Array variateArray(1);
    for (unsigned long i = 0; i < numberOfPaths; i++)
    {
        generator.getGaussians(variateArray);
        thisSpot = movedSpot * exp(rootVariance * variateArray[0]);
        double thisPayoff = theOption.optionPayoff(thisSpot);
        gatherer.dumpOneResult(thisPayoff * discounting);
    }

    return;
}