#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "payoff.hpp"
#include "vanilla.hpp"
#include "parameters.hpp"
#include "mcStatistics.hpp"

double simpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths);

//Exercice 1.1
double simpleMonteCarloPut(double expiry, double strike, double spot, double vol, double r, unsigned long numberOfPaths);

//Exercice 1.2
double simpleMonteCarloDD(double expiry, double strike1, double strike2, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo2(const Payoff1 &thePayoff, double expiry, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo2(const Payoff2 &thePayoff, double expiry, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo3(const VanillaOption1 &theOption, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo3(const VanillaOption2 &theOption, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo3(const VanillaOption3 &theOption, double spot, double vol, double r, unsigned long numberOfPaths);

double simpleMonteCarlo4(const VanillaOption3 &theOption, double spot, const Parameters &vol, const Parameters &r, unsigned long numberOfPaths);

void simpleMonteCarlo5(const VanillaOption3 &theOption, double spot, const Parameters &vol, const Parameters &r, unsigned long numberOfPaths, StatisticsMC &gatherer);

#endif