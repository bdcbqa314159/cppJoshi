#ifndef VANILLA_H
#define VANILLA_H

#include "payoff.hpp"
#include "payoffBridge.hpp"

class VanillaOption1
{

public:
    VanillaOption1(Payoff2 &thePayoff, double expiry);
    double getExpiry() const;
    double optionPayoff(double spot) const;

private:
    double expiry;
    Payoff2 &thePayoff;
};

class VanillaOption2
{

public:
    VanillaOption2(const Payoff3 &thePayoff, double expiry);
    VanillaOption2(const VanillaOption2 &original);
    VanillaOption2 &operator=(const VanillaOption2 &original);
    ~VanillaOption2();

    double getExpiry() const;
    double optionPayoff(double spot) const;

private:
    double expiry;
    Payoff3 *thePayoffPtr;
};

class VanillaOption3
{

public:
    VanillaOption3(const PayoffBridge &thePayoff, double expiry);
    double optionPayoff(double spot) const;
    double getExpiry() const;

private:
    double expiry;
    PayoffBridge thePayoff;
};

#endif