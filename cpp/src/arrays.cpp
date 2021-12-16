#include "../include/cppJoshi_bits/arrays.hpp"
#include <algorithm>
#include <numeric>

Array::Array(unsigned long size) : size(size), capacity(size)
{

    if (size > 0)
    {
        valuesPtr = new double[size];
        endPtr = valuesPtr;
        endPtr += size;
    }

    else
    {
        valuesPtr = 0;
        endPtr = 0;
    }
}

Array::Array(const Array &original) : size(original.size), capacity(original.capacity)
{
    if (size > 0)
    {
        valuesPtr = new double[size];
        endPtr = valuesPtr;
        endPtr += size;

        std::copy(original.valuesPtr, original.endPtr, valuesPtr);
    }

    else
    {
        valuesPtr = endPtr = 0;
    }
}

Array::~Array()
{

    if (size > 0)
    {
        delete[] valuesPtr;
    }
}

Array &Array::operator=(const Array &original)
{
    if (&original == this)
    {
        return *this;
    }

    if (original.size > capacity)
    {
        if (capacity > 0)
        {
            delete[] valuesPtr;
        }

        valuesPtr = new double[original.size];
        capacity = original.size;
    }

    size = original.size;

    endPtr = valuesPtr;
    endPtr += size;

    std::copy(original.valuesPtr, original.endPtr, valuesPtr);
    return *this;
}

void Array::resize(unsigned long newSize)
{
    if (newSize > capacity)
    {

        if (capacity > 0)
        {
            delete[] valuesPtr;
        }

        valuesPtr = new double[newSize];
        capacity = newSize;
    }

    size = newSize;
    endPtr = valuesPtr + size;
}

Array &Array::operator+=(const Array &operand)
{

#ifdef RANGE_CHECKING
    if (size != operand.size())
    {
        throw("to apply += two arrays must be of same size");
    }
#endif

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] += operand[i];
    }

    return *this;
}

Array &Array::operator-=(const Array &operand)
{

#ifdef RANGE_CHECKING
    if (size != operand.size())
    {
        throw("to apply -= two arrays must be of same size");
    }
#endif

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] -= operand[i];
    }

    return *this;
}

Array &Array::operator/=(const Array &operand)
{

#ifdef RANGE_CHECKING
    if (size != operand.size())
    {
        throw("to apply /= two arrays must be of same size");
    }
#endif

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] /= operand[i];
    }

    return *this;
}

Array &Array::operator*=(const Array &operand)
{

#ifdef RANGE_CHECKING
    if (size != operand.size())
    {
        throw("to apply *= two arrays must be of same size");
    }
#endif

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] *= operand[i];
    }

    return *this;
}

Array &Array::operator+=(const double &operand)
{

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] += operand;
    }

    return *this;
}

Array &Array::operator-=(const double &operand)
{

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] -= operand;
    }

    return *this;
}

Array &Array::operator/=(const double &operand)
{

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] /= operand;
    }

    return *this;
}

Array &Array::operator*=(const double &operand)
{

    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] *= operand;
    }

    return *this;
}

Array &Array::operator=(const double &val)
{
    for (unsigned long i = 0; i < size; i++)
    {
        valuesPtr[i] = val;
    }

    return *this;
}

double Array::sum() const
{
    return std::accumulate(valuesPtr, endPtr, 0.);
}

double Array::min() const
{
#ifdef RANGE_CHECKING
    if (size == 0)
    {
        throw("cannot take min of empty array");
    }
#endif
    double *tmp = valuesPtr;
    double *endTmp = endPtr;

    return *std::min_element(tmp, endTmp);
}

double Array::max() const
{
#ifdef RANGE_CHECKING
    if (size == 0)
    {
        throw("cannot take max of empty array");
    }
#endif
    double *tmp = valuesPtr;
    double *endTmp = endPtr;

    return *std::max_element(tmp, endTmp);
}

Array Array::apply(double f(double)) const
{

    Array result(getSize());
    std::transform(valuesPtr, endPtr, result.valuesPtr, f);

    return result;
}
