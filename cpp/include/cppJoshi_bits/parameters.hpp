#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <vector>

class ParametersInner
{

public:
    ParametersInner() {}
    virtual ParametersInner *clone() const = 0;
    virtual double Integral(double time1, double time2) const = 0;
    virtual double IntegralSquare(double time1, double time2) const = 0;
    virtual ~ParametersInner() {}

private:
};

class Parameters
{

public:
    Parameters(const ParametersInner &innerObject);
    Parameters(const Parameters &original);
    Parameters &operator=(const Parameters &original);
    virtual ~Parameters();

    inline double Integral(double time1, double time2) const;

    inline double IntegralSquare(double time1, double time2) const;

    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;

private:
    ParametersInner *innerObjectPtr;
};

inline double Parameters::Integral(double time1, double time2) const
{
    return innerObjectPtr->Integral(time1, time2);
}

inline double Parameters::IntegralSquare(double time1, double time2) const
{
    return innerObjectPtr->IntegralSquare(time1, time2);
}

class ParametersConstant : public ParametersInner
{

public:
    ParametersConstant(double constant);
    virtual ParametersInner *clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;

private:
    double constant;
    double constantSquare;
};

//Exercise 4.1
class ParametersPieceWise : public ParametersInner
{

public:
    ParametersPieceWise(std::vector<double> constants, std::vector<double> times);
    virtual ParametersInner *clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;

private:
    std::vector<double> constants;
    std::vector<double> times;
};

#endif