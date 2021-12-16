#ifndef RANDOM_H
#define RANDOM_H

#include "arrays.hpp"

double getOneGaussianBySummation();
double getOneGaussianByBoxMuller();

class RandomBase
{

public:
    RandomBase(unsigned long dimensionality);

    inline unsigned long getDimensionality() const;

    virtual RandomBase *clone() const = 0;

    virtual void getUniforms(Array &variates) = 0;
    virtual void skip(unsigned long numberOfPaths) = 0;
    virtual void setSeed(unsigned long seed) = 0;
    virtual void reset() = 0;

    virtual void getGaussians(Array &variates);
    virtual void resetDimensionality(unsigned long newDimensionality);

private:
    unsigned long dimensionality;
};

inline unsigned long RandomBase::getDimensionality() const
{
    return dimensionality;
}

#endif