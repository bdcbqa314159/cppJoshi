#ifndef PAYOFFCONSTRUCTIBLE_H
#define PAYOFFCONSTRUCTIBLE_H

#include "payoff.hpp"
#include "payoffFactory.hpp"

#include <iostream>
#include <string>

template <class T>
class PayoffHelper
{
public:
    PayoffHelper(std::string);
    static Payoff3 *create(double);
};

template <class T>
Payoff3 *PayoffHelper<T>::create(double strike)
{
    return new T(strike);
}

template <class T>
PayoffHelper<T>::PayoffHelper(std::string id)
{
    PayoffFactory &thePayoffFactory = PayoffFactory::instance();
    thePayoffFactory.registerPayoff(id, PayoffHelper<T>::create);
}

#endif