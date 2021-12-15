#include "../include/cppJoshi_bits/parameters.hpp"
#include <algorithm>
#include <iostream>

Parameters::Parameters(const ParametersInner &innerObject)
{
    innerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters &original)
{
    innerObjectPtr = original.innerObjectPtr->clone();
}

Parameters &Parameters::operator=(const Parameters &original)
{

    if (this != &original)
    {
        delete innerObjectPtr;
        innerObjectPtr = original.innerObjectPtr->clone();
    }

    return *this;
}

Parameters::~Parameters()
{
    delete innerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const
{
    double total = Integral(time1, time2);
    return total / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const
{
    double total = IntegralSquare(time1, time2);
    return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double constant) : constant(constant), constantSquare(constant * constant)
{
}

ParametersInner *ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const
{
    return (time2 - time1) * constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const
{
    return (time2 - time1) * constantSquare;
}

ParametersPieceWise::ParametersPieceWise(std::vector<double> constants, std::vector<double> times) : constants(constants), times(times)
{
    std::sort(times.begin(), times.end());
    if (times.size() != constants.size() + 1)
    {
        std::cout << "check PieceWise Parameters inputs!" << std::endl;
    }
}

ParametersInner *ParametersPieceWise::clone() const
{
    return new ParametersPieceWise(*this);
}

double ParametersPieceWise::Integral(double time1, double time2) const
{
    double integral = 0;
    int i(0);
    int N = constants.size();

    if (time1 > times[0])
    {
        while (times[i] < time1 && i < N)
        {
            i++;
        }

        integral += constants[i - 1] * (times[i] - time1);
    }

    while (times[i] < time2 && i < N)
    {
        if (times[i + 1] < time2)
        {
            integral += constants[i] * (times[i + 1] - times[i]);
            i++;
        }
        else
        {
            break;
        }
    }

    if (i >= N)
    {
        return integral;
    }
    else
    {
        integral += constants[i] * (time2 - times[i]);
        return integral;
    }
}

double ParametersPieceWise::IntegralSquare(double time1, double time2) const
{
    double integral = 0;
    int i = 0;
    while (times[i] < time1)
    {
        i++;
    }
    integral += constants[i] * constants[i] * (times[i] - time1);

    while (times[i] < time2)
    {
        if (times[i + 1] < time2)
        {
            integral += constants[i] * constants[i] * (times[i + 1] - times[i]);
            i++;
        }
        else
        {
            break;
        }
    }

    integral += constants[i] * constants[i] * (time2 - times[i]);
    return integral;
}