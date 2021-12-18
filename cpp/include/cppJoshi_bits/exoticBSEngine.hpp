#ifndef EXOTICBSENGINE_H
#define EXOTICBSENGINE_H

#include "exoticEngine.hpp"
#include "random.hpp"

class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent> &theProduct, const Parameters &r, const Parameters &d, const Parameters &vol, const Wrapper<RandomBase> &theGenerator, double spot);

    virtual void getOnePath(Array &spotValues);
    virtual ~ExoticBSEngine() {}

private:
    Wrapper<RandomBase> theGenerator;
    Array drifts;
    Array standardDeviations;
    double logSpot;
    unsigned long numberOfTimes;
    Array variates;
};

#endif