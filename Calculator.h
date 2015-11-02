/** @file Calculator.h */
#ifndef _CALCULATOR
#define _CALCULATOR

#include <string>
#include "Stack.h"

using namespace std;

class Calculator
{
private:

    Stack<double> valStack;
    Stack<char> opStack;

    int precedence(char ch);
    void executeSteps();

public:

    double CalculateFromInfix(string in);

}; // end Calculator

#include "Calculator.cpp"
#endif // _CALCULATOR
