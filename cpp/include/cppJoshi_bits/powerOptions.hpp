#ifndef POWEROPTIONS_H
#define POWEROPTIONS_H

#include "payoff.hpp"

//Exercise 3.1 ->power options

class PayoffPowerCall2 : public Payoff2
{
public:
    PayoffPowerCall2(double strike, int power);
    virtual double operator()(double spot) const;
    virtual ~PayoffPowerCall2() {}

private:
    double strike;
    int power;
};

class PayoffPowerPut2 : public Payoff2
{
public:
    PayoffPowerPut2(double strike, int power);
    virtual double operator()(double spot) const;
    virtual ~PayoffPowerPut2() {}

private:
    double strike;
    int power;
};

#endif