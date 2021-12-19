#ifndef BSCALL_H
#define BSCALL_H

class BSCall1
{

public:
    BSCall1(double r, double d, double expiry, double spot, double strike);
    double operator()(double vol) const;

private:
    double r;
    double d;
    double expiry;
    double spot;
    double strike;
};

class BSCall2
{

public:
    BSCall2(double r, double d, double expiry, double spot, double strike);
    double price(double vol) const;
    double vega(double vol) const;

private:
    double r;
    double d;
    double expiry;
    double spot;
    double strike;
};

#endif