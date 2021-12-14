#include "../include/cppJoshi_bits/payoffBridge.hpp"

PayoffBridge::PayoffBridge(const PayoffBridge &original)
{
    thePayoffPtr = original.thePayoffPtr->clone();
}

PayoffBridge::PayoffBridge(const Payoff3 &innerPayoff)
{
    thePayoffPtr = innerPayoff.clone();
}

PayoffBridge::~PayoffBridge()
{
    delete thePayoffPtr;
}

PayoffBridge &PayoffBridge::operator=(const PayoffBridge &original)
{

    if (this != &original)
    {
        delete thePayoffPtr;
        thePayoffPtr = original.thePayoffPtr->clone();
    }

    return *this;
}
