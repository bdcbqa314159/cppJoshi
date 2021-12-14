#include "../include/cppJoshi_bits/simpleMC.hpp"
#include "../include/cppJoshi_bits/random.hpp"

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