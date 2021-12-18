#include "../include/cppJoshi_bits/blackScholesFormulas.hpp"
#include "../include/cppJoshi_bits/normals.hpp"

#include <cmath>

double blackScholesCall(double spot, double strike, double r, double d, double vol, double expiry)
{

    double standardDeviation = vol * sqrt(expiry);
    double moneyness = log(spot / strike);
    double d1 = (moneyness + (r - d) * expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
    double d2 = d1 - standardDeviation;

    return spot * exp(-d * expiry) * cumulativeNormal(d1) - strike * exp(-r * expiry) * cumulativeNormal(d2);
}

double blackScholesPut(double spot, double strike, double r, double d, double vol, double expiry)
{
    double standardDeviation = vol * sqrt(expiry);
    double moneyness = log(spot / strike);
    double d1 = (moneyness + (r - d) * expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
    double d2 = d1 - standardDeviation;

    return strike * exp(-r * expiry) * (1. - cumulativeNormal(d2)) - spot * exp(-d * expiry) * (1. - cumulativeNormal(d1));
}

double blackScholesDigitalCall(double spot, double strike, double r, double d, double vol, double expiry)
{
    double standardDeviation = vol * sqrt(expiry);
    double moneyness = log(spot / strike);
    double d2 = (moneyness + (r - d) * expiry - 0.5 * standardDeviation * standardDeviation) / standardDeviation;

    return exp(-r * expiry) * cumulativeNormal(d2);
}

double blackScholesDigitalPut(double spot, double strike, double r, double d, double vol, double expiry)
{
    double standardDeviation = vol * sqrt(expiry);
    double moneyness = log(spot / strike);
    double d2 = (moneyness + (r - d) * expiry - 0.5 * standardDeviation * standardDeviation) / standardDeviation;

    return exp(-r * expiry) * (1. - cumulativeNormal(d2));
}

double blackScholesCallVega(double spot, double strike, double r, double d, double vol, double expiry)
{
    double standardDeviation = vol * sqrt(expiry);
    double moneyness = log(spot / strike);
    double d1 = (moneyness + (r - d) * expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;

    return spot * exp(-d * expiry) * sqrt(expiry) * normalDensity(d1);
}