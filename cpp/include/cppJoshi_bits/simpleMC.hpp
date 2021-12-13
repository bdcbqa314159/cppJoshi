#ifndef SIMPLEMC_H
#define SIMPLEMC_H

double simpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths);

//Exercice 1.1
double simpleMonteCarloPut(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths);

//Exercice 1.2
double simpleMonteCarloDD(double expiry, double strike1, double strike2, double spot, double vol, double r, unsigned long numberOfPaths);

#endif