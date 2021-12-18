#ifndef BLACKSCHOLESFORMULAS_H
#define BLACKSCHOLESFORMULAS_H

double blackScholesCall(double spot, double strike, double r, double d, double vol, double expiry);

double blackScholesPut(double spot, double strike, double r, double d, double vol, double expiry);

double blackScholesDigitalCall(double spot, double strike, double r, double d, double vol, double expiry);

double blackScholesDigitalPut(double spot, double strike, double r, double d, double vol, double expiry);

double blackScholesCallVega(double spot, double strike, double r, double d, double vol, double expiry);

#endif