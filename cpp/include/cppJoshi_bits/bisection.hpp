#ifndef BISECTION_H
#define BISECTION_H
#include <cmath>

template <class T>
double bisection(double target, double low, double high, double tolerance, T theFunction)
{
    double x = 0.5 * (low + high);
    double y = theFunction(x);

    do
    {
        if (y < target)
        {
            low = x;
        }
        if (y > target)
        {
            high = x;
        }
        x = 0.5 * (low + high);
        y = theFunction(x);
    } while (fabs(y - target) > tolerance);

    return x;
}

#endif