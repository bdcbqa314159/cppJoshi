#ifndef ARRAYS_H
#define ARRAYS_H

class Array
{
public:
    explicit Array(unsigned long size = 0);
    Array(const Array &original);
    ~Array();

    Array &operator=(const Array &original);
    Array &operator=(const double &val);

    Array &operator+=(const Array &operand);
    Array &operator-=(const Array &operand);
    Array &operator/=(const Array &operand);
    Array &operator*=(const Array &operand);

    Array &operator+=(const double &operand);
    Array &operator-=(const double &operand);
    Array &operator/=(const double &operand);
    Array &operator*=(const double &operand);

    Array apply(double f(double)) const;

    inline double operator[](unsigned long i) const;
    inline double &operator[](unsigned long i);

    inline unsigned long getSize() const;
    void resize(unsigned long newSize);

    double sum() const;
    double min() const;
    double max() const;

private:
    double *valuesPtr;
    double *endPtr;

    unsigned long size;
    unsigned long capacity;
};

inline double Array::operator[](unsigned long i) const
{

#ifdef RANGE_CHECKING
    if (i >= Size)
    {
        std::throw("Index out of bounds");
    }
#endif
    return valuesPtr[i];
}

inline double &Array::operator[](unsigned long i)
{

#ifdef RANGE_CHECKING
    if (i >= Size)
    {
        std::throw("Index out of bounds");
    }
#endif
    return valuesPtr[i];
}

inline unsigned long Array::getSize() const
{
    return size;
}

#endif