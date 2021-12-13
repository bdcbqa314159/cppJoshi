#include <cppJoshi>
#include <iostream>
#include <string>

void simpleMCMain1()
{

    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(100.);
    unsigned long N = 30000;

    double result(0);

    result = simpleMonteCarlo1(expiry, strike, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << result << std::endl;
    return;
}

void exercise1()
{

    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(130.);
    unsigned long N = 30000;

    double result(0);

    result = simpleMonteCarloPut(expiry, strike, spot, vol, r, N);

    std::cout << "Price of a put with simple Monte Carlo simulation : " << result << std::endl;
    return;
}

void exercise2()
{

    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike1(130.), strike2(90.);
    unsigned long N = 30000;

    double result(0);

    result = simpleMonteCarloDD(expiry, strike1, strike2, spot, vol, r, N);

    std::cout << "Price of a double digital with simple Monte Carlo simulation : " << result << std::endl;
    return;
}

void exercise3()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike1(130.), strike2(90.);
    unsigned long N = 30000;

    double result(0);

    std::string payoff("");

    std::cout << "enter pay off?" << std::endl;
    std::getline(std::cin, payoff);

    if (payoff == "call")
    {
        result = simpleMonteCarlo1(expiry, strike1, spot, vol, r, N);

        std::cout << "Price of a call with simple Monte Carlo simulation : " << result << std::endl;
        return;
    }

    else if (payoff == "put")
    {
        result = simpleMonteCarloPut(expiry, strike1, spot, vol, r, N);

        std::cout << "Price of a put with simple Monte Carlo simulation : " << result << std::endl;
        return;
    }

    else if (payoff == "double digital")
    {
        result = simpleMonteCarloDD(expiry, strike1, strike2, spot, vol, r, N);

        std::cout << "Price of a double digital with simple Monte Carlo simulation : " << result << std::endl;
        return;
    }

    else
    {
        std::cout << "pay off no recognized, we only accept: call - put - double digital." << std::endl;
        return;
    }
}

void exercise4()
{
    std::cout << "Classes on the evil boss's list of demands:" << std::endl;
    std::cout << "1.euro options." << std::endl;
    std::cout << "2.asian options." << std::endl;
    std::cout << "3.MC features." << std::endl;
    std::cout << "3.Pricing models" << std::endl;
}

void simpleMCMain2()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(100.);
    unsigned long N = 30000;

    Payoff1 callPayoff(strike, Payoff1::call);
    Payoff1 putPayoff(130., Payoff1::put);

    double resultCall(0), resultPut(0);

    resultCall = simpleMonteCarlo2(callPayoff, expiry, spot, vol, r, N);
    resultPut = simpleMonteCarlo2(putPayoff, expiry, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << resultCall << std::endl;

    std::cout << "Price of a put with simple Monte Carlo simulation : " << resultPut << std::endl;
    return;
}

void exercise5()
{
    //Exercise 2.1

    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(100.);
    unsigned long N = 30000;

    Payoff1 digitalCallPayoff(strike, Payoff1::digitalCall);
    Payoff1 digitalPutPayoff(100, Payoff1::digitalPut);

    double resultDigitalCall(0), resultDigitalPut(0);

    resultDigitalCall = simpleMonteCarlo2(digitalCallPayoff, expiry, spot, vol, r, N);
    resultDigitalPut = simpleMonteCarlo2(digitalPutPayoff, expiry, spot, vol, r, N);

    std::cout << "Price of a digital call with simple Monte Carlo simulation : " << resultDigitalCall << std::endl;

    std::cout << "Price of a digital put with simple Monte Carlo simulation : " << resultDigitalPut << std::endl;
    return;
}

void exercise6()
{
    //Exercise 2.2

    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(80.), strikeDD(200.);
    unsigned long N = 30000;

    Payoff1 doubleDigital(strike, strikeDD, Payoff1::doubleDigital);

    double resultDoubleDigital(0.);

    resultDoubleDigital = simpleMonteCarlo2(doubleDigital, expiry, spot, vol, r, N);

    std::cout << "Price of a double digital with simple Monte Carlo simulation : " << resultDoubleDigital << std::endl;

    return;
}

void exercise7()
{
    std::cout << "No need to test the speed of the compiler with or without const. I use const with the best practice usage." << std::endl;
}

int main()
{
    // std::cout << "======Chapter 1======" << std::endl;
    // simpleMCMain1();
    // exercise1();
    // exercise2();
    // exercise3();
    // exercise4();

    std::cout << "======Chapter 2======" << std::endl;
    simpleMCMain2();
    exercise5();
    exercise6();

    return 0;
}
