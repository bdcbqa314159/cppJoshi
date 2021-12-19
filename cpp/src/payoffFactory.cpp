#include "../include/cppJoshi_bits/payoffFactory.hpp"
#include <iostream>

void PayoffFactory::registerPayoff(std::string payoffId, createPayoffFunction creatorFunction)
{

    theCreatorFunctions.insert(std::pair<std::string, createPayoffFunction>(payoffId, creatorFunction));
}

Payoff3 *PayoffFactory::createPayoff(std::string payoffId, double strike)
{
    std::map<std::string, createPayoffFunction>::const_iterator i = theCreatorFunctions.find(payoffId);

    if (i == theCreatorFunctions.end())
    {
        std::cout << payoffId << " is an unknown payoff" << std::endl;
        return NULL;
    }

    return (i->second)(strike);
}

PayoffFactory &PayoffFactory::instance()
{
    static PayoffFactory theFactory;
    return theFactory;
}
