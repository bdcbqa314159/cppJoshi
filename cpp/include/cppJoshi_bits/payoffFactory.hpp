#ifndef PAYOFFFACTORY_H
#define PAYOFFFACTORY_H

#include "payoff.hpp"

#include <map>
#include <string>

class PayoffFactory
{
public:
    typedef Payoff3 *(*createPayoffFunction)(double);
    static PayoffFactory &instance();
    void registerPayoff(std::string, createPayoffFunction);
    Payoff3 *createPayoff(std::string payoffId, double strike);
    ~PayoffFactory() {}

private:
    std::map<std::string, createPayoffFunction> theCreatorFunctions;
    PayoffFactory() {}
    PayoffFactory(const PayoffFactory &) {}
    PayoffFactory &operator=(const PayoffFactory &) { return *this; }
};

#endif