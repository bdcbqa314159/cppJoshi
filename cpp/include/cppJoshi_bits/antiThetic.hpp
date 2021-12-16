#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "random.hpp"
#include "wrapper.hpp"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase> &innerGenerator);
    virtual RandomBase *clone() const;
    virtual void getUniforms(Array &variates);
    virtual void skip(unsigned long numberOfPaths);
    virtual void setSeed(unsigned long seed);
    virtual void resetDimensionality(unsigned long newDimensionality);

    virtual void reset();

private:
    Wrapper<RandomBase> innerGenerator;
    bool oddEven;
    Array nextVariates;
};

#endif
