#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "payoff.hpp"

class PayoffBridge
{

public:
    PayoffBridge(const PayoffBridge &original);
    PayoffBridge(const Payoff3 &innerPayoff);

    inline double operator()(double spot) const;
    ~PayoffBridge();
    PayoffBridge &operator=(const PayoffBridge &original);

private:
    Payoff3 *thePayoffPtr;
};

inline double PayoffBridge::operator()(double spot) const
{
    return thePayoffPtr->operator()(spot);
}

#endif