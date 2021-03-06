#include <cppJoshi>
#include <iostream>
#include <string>
#include <cmath>

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
    // Exercise 2.1

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
    // Exercise 2.2

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

void simpleMCMain3()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(100.);
    unsigned long N = 30000;

    PayoffCall2 callPayoff(strike);
    PayoffPut2 putPayoff(130.);

    double resultCall(0), resultPut(0);

    resultCall = simpleMonteCarlo2(callPayoff, expiry, spot, vol, r, N);
    resultPut = simpleMonteCarlo2(putPayoff, expiry, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << resultCall << std::endl;

    std::cout << "Price of a put with simple Monte Carlo simulation : " << resultPut << std::endl;
    return;
}

void simpleMCMain4()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(100.);
    unsigned long N = 30000;

    Payoff2 *thePayoffPtr(0);

    std::cout << "Enter 0 for a call, 1 for a put" << std::endl;

    int ans(0);
    std::cout << "Enter the option>>";
    std::cin >> ans;

    if (ans == 0)
    {
        thePayoffPtr = new PayoffCall2(strike);
    }

    else
    {
        thePayoffPtr = new PayoffPut2(130.);
    }

    double result(0);
    result = simpleMonteCarlo2(*thePayoffPtr, expiry, spot, vol, r, N);

    if (ans == 0)
    {
        std::cout << "Price of a call with simple Monte Carlo simulation : " << result << std::endl;
    }

    else
    {
        std::cout << "Price of a put with simple Monte Carlo simulation : " << result << std::endl;
    }
    delete thePayoffPtr;

    return;
}

void simpleMCMain5()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.), strike1(80.);
    unsigned long N = 30000;

    Payoff2 *thePayoffPtr(0);

    thePayoffPtr = new PayoffDoubleDigital2(strike1, strike);

    double result(0);
    result = simpleMonteCarlo2(*thePayoffPtr, expiry, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << result << std::endl;

    delete thePayoffPtr;

    return;
}

void exercise8()
{
    // Exercise 3.1
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.), strike1(80.);
    int power(4);
    unsigned long N = 30000;

    Payoff2 *thePayoffPtr(0);

    std::cout << "Enter 0 for a power call, 1 for a  power put" << std::endl;

    int ans(0);
    std::cout << "Enter the option>>";
    std::cin >> ans;

    if (ans == 0)
    {
        thePayoffPtr = new PayoffPowerCall2(strike, power);
    }

    else
    {
        thePayoffPtr = new PayoffPowerPut2(130., power);
    }

    double result(0);
    result = simpleMonteCarlo2(*thePayoffPtr, expiry, spot, vol, r, N);

    if (ans == 0)
    {
        std::cout << "Price of a power call with simple Monte Carlo simulation : " << result << std::endl;
    }

    else
    {
        std::cout << "Price of a power put with simple Monte Carlo simulation : " << result << std::endl;
    }
    delete thePayoffPtr;

    return;
}

void exercise9()
{
    // Exercise 3.2
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.), strike1(80.);
    int power(4);
    unsigned long N = 30000;

    Payoff2 *thePayoffPtr(0);

    std::cout << "Enter the payoff" << std::endl;

    std::cout << "Enter the option>>";
    std::string payoff("");

    std::getline(std::cin, payoff);

    if (payoff == "call")
    {
        thePayoffPtr = new PayoffCall2(strike);
    }

    else if (payoff == "put")
    {
        thePayoffPtr = new PayoffPut2(strike);
    }

    else if (payoff == "double digital")
    {
        thePayoffPtr = new PayoffDoubleDigital2(strike1, strike);
    }

    else if (payoff == "power call")
    {
        thePayoffPtr = new PayoffPowerCall2(strike, power);
    }

    else if (payoff == "power put")
    {
        thePayoffPtr = new PayoffPowerPut2(strike, power);
    }

    else
    {
        std::cout << "The only payoffs accpeted are:" << std::endl;
        std::cout << "call\nput\ndouble digital\npower call\npower put." << std::endl;
        return;
    }

    double result(0);
    result = simpleMonteCarlo2(*thePayoffPtr, expiry, spot, vol, r, N);

    std::cout << "Price of the option with pay off: " << payoff << " with simple Monte Carlo simulation : " << result << std::endl;

    delete thePayoffPtr;

    return;
}

void exercise10()
{
    // Exercise 3.3
    std::cout << "We have inheritance between digitals as payoffs." << std::endl;
    std::cout << "We have inheritance between all asians put/calls geometric/arithmetic & digitals from asian as exotic." << std::endl;
    std::cout << "jump diffusion as model pricing" << std::endl;
    std::cout << "statistics errors from standard errors" << std::endl;
    return;
}

void vanillaMain1()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.), strike1(80.);
    unsigned long N = 30000;

    double result(0);

    PayoffDoubleDigital2 thePayoff(strike1, strike);
    VanillaOption1 theOption(thePayoff, expiry);

    result = simpleMonteCarlo3(theOption, spot, vol, r, N);

    std::cout << "Price of Double Digital with simple Monte Carlo simulation : " << result << std::endl;

    return;
}

void vanillaMain2()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.);
    unsigned long N = 30000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption2 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);

    resultCall = simpleMonteCarlo3(theOption, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << resultCall << std::endl;

    VanillaOption2 secondOption(theOption);

    resultCall = simpleMonteCarlo3(secondOption, spot, vol, r, N);

    std::cout << "Price of another call with simple Monte Carlo simulation : " << resultCall << std::endl;

    PayoffPut3 otherPayoff(strike);
    VanillaOption2 otherOption(otherPayoff, expiry);
    resultPut = simpleMonteCarlo3(otherOption, spot, vol, r, N);

    std::cout << "Price of a put with simple Monte Carlo simulation : " << resultPut << std::endl;
    return;
}

void vanillaMain3()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.);
    unsigned long N = 30000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption3 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);

    resultCall = simpleMonteCarlo3(theOption, spot, vol, r, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << resultCall << std::endl;

    VanillaOption3 secondOption(theOption);

    resultCall = simpleMonteCarlo3(secondOption, spot, vol, r, N);

    std::cout << "Price of another call with simple Monte Carlo simulation : " << resultCall << std::endl;

    PayoffPut3 otherPayoff(strike);
    VanillaOption3 otherOption(otherPayoff, expiry);
    resultPut = simpleMonteCarlo3(otherOption, spot, vol, r, N);

    std::cout << "Price of a put with simple Monte Carlo simulation : " << resultPut << std::endl;
    return;
}

void vanillaMain4()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(140.);
    unsigned long N = 30000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption3 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);

    resultCall = simpleMonteCarlo4(theOption, spot, volParam, rParam, N);

    std::cout << "Price of a call with simple Monte Carlo simulation : " << resultCall << std::endl;

    return;
}

void exercise11()
{
    // Exercise 4.1
    std::cout << "Testing if new is slow is irrelevant by now." << std::endl;
}

void exercise12()
{
    // Exercise 4.2
    std::cout << "auto_ptr is now deprecated, it is an example of smart pointer." << std::endl;
}

void exercise13()
{
    // Exercise 4.3
    std::cout << "Testing PieceWise paramters" << std::endl;
    std::vector<double> values = {1, 2};
    std::vector<double> times = {0, 3, 5};
    ParametersPieceWise f(values, times);
    double integral = f.Integral(0, 4);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(0, 8);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(2, 8);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(-2, 8);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(0, 5);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(-1, 0);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(5, 100);
    std::cout << "Integral " << integral << std::endl;

    integral = f.Integral(3, 100);
    std::cout << "Integral " << integral << std::endl;
}

void statsMain1()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(90.);
    unsigned long N = 30000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption3 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;

    simpleMonteCarlo5(theOption, spot, volParam, rParam, N, gatherer);

    std::vector<std::vector<double>> results = gatherer.getResultsSoFar();

    std::cout << "For the call price the results are :" << std::endl;

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
        {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void statsMain2()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(90.);
    unsigned long N = 30000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption3 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    simpleMonteCarlo5(theOption, spot, volParam, rParam, N, gathererTwo);

    std::vector<std::vector<double>> results = gathererTwo.getResultsSoFar();

    std::cout << "For the call price the results are :" << std::endl;

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
        {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void randomMain3()
{
    double spot(100.), expiry(1.), r(0.03), vol(0.02), strike(90.);
    unsigned long N = 400000;

    double result(0);

    PayoffCall3 thePayoff(strike);
    VanillaOption3 theOption(thePayoff, expiry);

    double resultCall(0), resultPut(0);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(1);
    AntiThetic genTwo(generator);

    simpleMonteCarlo6(theOption, spot, volParam, rParam, N, gatherer, generator);

    std::vector<std::vector<double>> results = gatherer.getResultsSoFar();

    std::cout << "For the call price the results are :" << std::endl;

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
        {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void equityFXMain()
{
    double spot(100.), expiry(1.), r(0.03), d(0.01), vol(0.02), strike(90.);
    unsigned long numberOfPaths = 4000;
    unsigned long numberOfDates = 10;

    double result(0);

    PayoffCall3 thePayoff(strike);
    Array times(numberOfDates);

    for (unsigned long i{}; i < numberOfDates; i++)
    {
        times[i] = (i + 1.) * expiry / numberOfDates;
    }

    double resultCall(0), resultPut(0);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    PathDependentAsian theOption(times, expiry, thePayoff);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(numberOfDates);
    AntiThetic genTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam, volParam, genTwo, spot);

    theEngine.doSimulation(gathererTwo, numberOfPaths);

    std::vector<std::vector<double>> results = gathererTwo.getResultsSoFar();

    std::cout << "For the call price the results are :" << std::endl;

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
        {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void treeMain()
{

    double spot(200.), expiry(1.), r(0.04), d(0.01), vol(0.02), strike(130.);
    unsigned long steps = 20;

    PayoffCall3 thePayoff(strike);

    double resultCall(0), resultPut(0);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(expiry, thePayoff);
    TreeAmerican americanOption(expiry, thePayoff);

    SimpleBinomialTree theTree(spot, rParam, dParam, vol, steps, expiry);

    double euroPrice = theTree.getThePrice(europeanOption);
    double americanPrice = theTree.getThePrice(americanOption);

    std::cout << "euro price = " << euroPrice << std::endl;
    std::cout << "american price = " << americanPrice << std::endl;

    double bsPrice = blackScholesCall(spot, strike, r, d, vol, expiry);
    std::cout << "BS formula euro price =" << bsPrice << std::endl;

    PayoffForward forwardPayoff(strike);
    TreeEuropean forward(expiry, forwardPayoff);

    double forwardPrice = theTree.getThePrice(forward);
    std::cout << "forward price by tree: " << forwardPrice << std::endl;

    double actualForwardPrice = exp(-r * expiry) * (spot * exp((r - d) * expiry) - strike);
    std::cout << "forward price: " << actualForwardPrice << std::endl;

    steps++;
    SimpleBinomialTree theNewTree(spot, rParam, dParam, vol, steps, expiry);
    double euroNewPrice = theNewTree.getThePrice(europeanOption);
    double americanNewPrice = theNewTree.getThePrice(americanOption);

    std::cout << "new euro price : " << euroNewPrice << std::endl;
    std::cout << "new american price: " << americanNewPrice << std::endl;

    double forwardNewPrice = theNewTree.getThePrice(forward);
    std::cout << "forward price by new tree: " << forwardNewPrice << std::endl;

    double averageEuro = 0.5 * (euroNewPrice + euroPrice);
    double averageAmerican = 0.5 * (americanPrice + americanNewPrice);
    double averageForward = 0.5 * (forwardNewPrice + forwardPrice);

    std::cout << "euro average = " << averageEuro << std::endl;
    std::cout << "forward average = " << averageForward << std::endl;
    std::cout << "american average = " << averageAmerican << std::endl;

    return;
}

void solveMain1()
{

    double spot(200.), expiry(1.), r(0.04), d(0.01), strike(130.);
    double price(73.1073);

    double low = 0.01, high = 1;
    double tolerance = 0.001;

    BSCall1 theCall(r, d, expiry, spot, strike);
    double vol = bisection(price, low, high, tolerance, theCall);
    double priceTwo = blackScholesCall(spot, strike, r, d, vol, expiry);

    std::cout << "vol = " << vol << "  price two " << priceTwo << std::endl;
}

void solveMain2()
{

    double spot(200.), expiry(1.), r(0.04), d(0.01), strike(130.);
    double price(74.3702);

    double start = 0.3;
    double tolerance = 0.0001;

    BSCall2 theCall(r, d, expiry, spot, strike);
    double vol = newtonRaphson<BSCall2, &BSCall2::price, &BSCall2::vega>(price, start, tolerance, theCall);
    double priceTwo = blackScholesCall(spot, strike, r, d, 0.3, expiry);

    std::cout << "vol = " << vol << "  price two " << priceTwo << std::endl;
}

void payoffFactoryMain()
{

    double strike(120.);
    std::string name("call");

    Payoff3 *payoffPtr = PayoffFactory::instance().createPayoff(name, strike);

    if (payoffPtr != NULL)
    {
        double spot(300);
        std::cout << payoffPtr->operator()(spot) << std::endl;
        delete payoffPtr;
    }
}

void wrapperMain()
{
    double S(200.), K1(90.), K2(301.), K3(120.);

    PayoffCall3 one(K1);
    PayoffPut3 two(K2);

    std::cout << "one : " << one(S) << std::endl;

    Payoff3 *p = one.clone();
    Wrapper1<Payoff3> four = p;

    {
        Payoff3 *q = two.clone();
        Wrapper1<Payoff3> five = q;

        std::cout << "four : " << (*four)(S) << std::endl;
        std::cout << "five : " << (*five)(S) << std::endl;

        four = five;
    }
    std::cout << "four : " << (*four)(S) << std::endl;
}

int main()
{
    // std::cout << "======Chapter 1======" << std::endl;
    // simpleMCMain1();
    // exercise1();
    // exercise2();
    // exercise3();
    // exercise4();

    // std::cout << "======Chapter 2======" << std::endl;
    // simpleMCMain2();
    // exercise5();
    // exercise6();
    // exercise7();

    // std::cout << "======Chapter 3======" << std::endl;
    // simpleMCMain3();
    // simpleMCMain4();
    // simpleMCMain5();
    // exercise8();
    // exercise9();
    // exercise10();

    // std::cout << "======Chapter 4======" << std::endl;
    // vanillaMain1();
    // vanillaMain2();
    // vanillaMain3();
    // vanillaMain4();
    // exercise11();
    // exercise12();
    // exercise13();

    // std::cout << "======Chapter 5======" << std::endl;
    // statsMain1();
    // statsMain2();

    // std::cout << "======Chapter 6======" << std::endl;
    // randomMain3();
    // std::cout << "======Chapter 7======" << std::endl;
    // equityFXMain();

    // std::cout << "======Chapter 8======" << std::endl;
    // treeMain();

    // std::cout << "======Chapter 9======" << std::endl;
    // solveMain1();
    // solveMain2();

    // std::cout << "======Chapter 10======" << std::endl;
    // payoffFactoryMain();

    std::cout << "======Chapter 13======" << std::endl;
    wrapperMain();

    return 0;
}
