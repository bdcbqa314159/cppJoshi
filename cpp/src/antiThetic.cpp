#include "../include/cppJoshi_bits/antiThetic.hpp"

AntiThetic::AntiThetic(const Wrapper<RandomBase> &innerGenerator) : RandomBase(*innerGenerator), innerGenerator(innerGenerator)
{
    (this->innerGenerator)->reset();
    oddEven = true;
    nextVariates.resize(getDimensionality());
}

RandomBase *AntiThetic::clone() const
{

    return new AntiThetic(*this);
}

void AntiThetic::getUniforms(Array &variates)
{
    if (oddEven)
    {
        innerGenerator->getUniforms(variates);

        for (unsigned long i = 0; i < getDimensionality(); i++)
        {
            nextVariates[i] = 1. - variates[i];
        }

        oddEven = false;
    }

    else
    {
        variates = nextVariates;
        oddEven = true;
    }
}

void AntiThetic::setSeed(unsigned long seed)
{

    innerGenerator->setSeed(seed);
    oddEven = true;
}

void AntiThetic::skip(unsigned long numberOfPaths)
{
    if (numberOfPaths == 0)
    {
        return;
    }

    if (oddEven)
    {
        oddEven = false;
        numberOfPaths--;
    }

    innerGenerator->skip(numberOfPaths / 2);

    if (numberOfPaths % 2)
    {
        Array tmp(getDimensionality());

        getUniforms(tmp);
    }
}

void AntiThetic::resetDimensionality(unsigned long newDimensionality)
{
    RandomBase::resetDimensionality(newDimensionality);
    nextVariates.resize(newDimensionality);
    innerGenerator->resetDimensionality(newDimensionality);
}

void AntiThetic::reset()
{
    innerGenerator->reset();
    oddEven = true;
}
