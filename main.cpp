#include <iostream>

// uncomment line below to get debugging information
//#define _CALC_DEBUG

#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main(void)
{

  Calculator c;
  string s;

  cout << "Enter an infix expression to be computed: ";
  getline(cin, s);

  cout << s << " = " << c.CalculateFromInfix(s) << endl;

  return 0;
}
