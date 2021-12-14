#include "../include/cppJoshi_bits/vanilla.hpp"

VanillaOption1::VanillaOption1(Payoff2 &thePayoff, double expiry) : thePayoff(thePayoff), expiry(expiry)
{
}

double VanillaOption1::getExpiry() const
{
    return expiry;
}

double VanillaOption1::optionPayoff(double spot) const
{
    return thePayoff(spot);
}

VanillaOption2::VanillaOption2(const Payoff3 &thePayoff, double expiry) : expiry(expiry)
{
    this->thePayoffPtr = thePayoff.clone();
}

double VanillaOption2::getExpiry() const
{
    return expiry;
}

double VanillaOption2::optionPayoff(double spot) const
{
    return (*thePayoffPtr)(spot);
}

VanillaOption2::VanillaOption2(const VanillaOption2 &original)
{
    this->expiry = original.expiry;
    this->thePayoffPtr = original.thePayoffPtr->clone();
}

VanillaOption2 &VanillaOption2::operator=(const VanillaOption2 &original)
{
    if (this != &original)
    {
        this->expiry = original.expiry;
        delete thePayoffPtr;

        this->thePayoffPtr = original.thePayoffPtr->clone();
    }

    return *this;
}

VanillaOption2::~VanillaOption2()
{
    delete thePayoffPtr;
}

VanillaOption3::VanillaOption3(const PayoffBridge &thePayoff, double expiry) : thePayoff(thePayoff), expiry(expiry)
{
}

double VanillaOption3::getExpiry() const
{
    return expiry;
}

double VanillaOption3::optionPayoff(double spot) const
{
    return thePayoff(spot);
}
