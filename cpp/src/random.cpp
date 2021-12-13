#include "../include/cppJoshi_bits/random.hpp"

#include <cmath>
#include <cstdlib>

double getOneGaussianBySummation()
{
    double result(0);
    for (int i = 0; i < 12; i++)
    {

        result += rand() / (static_cast<double>(RAND_MAX));
    }

    result -= 6.;

    return result;
}

double getOneGaussianByBoxMuller()
{

    double result(0), x(0), y(0), sizeSquared(0);

    do
    {
        x = 2. * rand() / (static_cast<double>(RAND_MAX) - 1);

        y = 2. * rand() / (static_cast<double>(RAND_MAX) - 1);

        sizeSquared = x * x + y * y;

    } while (sizeSquared > 1.);

    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

    return result;
}