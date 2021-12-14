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

class Payoff2
{
public:
    Payoff2(){};
    virtual double operator()(double spot) const = 0;
    virtual ~Payoff2(){};

private:
};

class PayoffCall2 : public Payoff2
{
public:
    PayoffCall2(double strike);
    virtual double operator()(double spot) const;
    virtual ~PayoffCall2() {}

private:
    double strike;
};

class PayoffPut2 : public Payoff2
{
public:
    PayoffPut2(double strike);
    virtual double operator()(double spot) const;
    virtual ~PayoffPut2() {}

private:
    double strike;
};

class Payoff3
{
public:
    Payoff3(){};

    virtual double operator()(double spot) const = 0;
    virtual ~Payoff3() {}
    virtual Payoff3 *clone() const = 0;

private:
};

class PayoffCall3 : public Payoff3
{

public:
    PayoffCall3(double strike);

    virtual double operator()(double spot) const;
    virtual ~PayoffCall3() {}
    virtual PayoffCall3 *clone() const;

private:
    double strike;
};

class PayoffPut3 : public Payoff3
{

public:
    PayoffPut3(double strike);

    virtual double operator()(double spot) const;
    virtual ~PayoffPut3() {}
    virtual PayoffPut3 *clone() const;

private:
    double strike;
};

#endif
