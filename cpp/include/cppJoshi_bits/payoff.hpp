#ifndef PAYOFF_H
#define PAYOFF_H

//Exercise 2.1 ->digital calls & puts
//Exercise 2.2 ->double digital

class Payoff1
{

public:
    enum optionType
    {
        call,
        put,
        digitalCall,
        digitalPut,
        doubleDigital
    };

    Payoff1(double strike, optionType theOptionType);
    Payoff1(double strike, double strikeDD, optionType theOptionType);
    double operator()(double spot) const;

private:
    double strike;
    double strikeDD;
    optionType theOptionType;
};

#endif
