#include "../include/cppJoshi_bits/pathDependent.hpp"

PathDependent::PathDependent(const Array &lookAtTimes) : lookAtTimes(lookAtTimes)
{
}

const Array &PathDependent::getLookAtTimes() const
{
    return lookAtTimes;
}