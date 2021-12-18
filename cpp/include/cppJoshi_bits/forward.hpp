#ifndef FORWARD_H
#define FORWARD_H

#include "payoff.hpp"

class PayoffForward : public Payoff3
{

public:
    PayoffForward(double strike);
    virtual double operator()(double spot) const;
    virtual ~PayoffForward() {}
    virtual Payoff3 *clone() const;

private:
    double strike;
};

#endif