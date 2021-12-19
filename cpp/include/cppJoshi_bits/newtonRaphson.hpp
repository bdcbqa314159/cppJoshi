#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include <cmath>

template <class T, double (T::*value)(double) const, double (T::*derivative)(double) const>
double newtonRaphson(double target, double start, double tolerance, const T &theObject)
{

    double y = (theObject.*value)(start);
    double x = start;

    while (fabs(y - target) > tolerance)
    {
        double d = (theObject.*derivative)(x);
        x += (target - y) / d;
        y = (theObject.*value)(x);
    }

    return x;
}

#endif