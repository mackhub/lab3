/** @file Calculator.cpp */

#include "Calculator.h"

#ifdef _CALC_DEBUG
#define CALC_DEBUG(a) a
#else
#define CALC_DEBUG(a)
#endif


double Calculator::CalculateFromInfix(string infix)
{
  char ch;
  double result;

  for (int i = 0; i < infix.size(); i++) {
	ch = infix[i];

	switch (ch) {

	case '0':	case '1':	case '2':	case '3':	case '4':
	case '5':	case '6':	case '7':	case '8':	case '9':

	  // digits, i.e. operands.  assumption is that each operand is a single digit
	  CALC_DEBUG(cout << "pushing val " << ch - '0' << endl);
	  valStack.push(ch - '0');
	  break;

	case '+':	case '-':	case '*':	case '/':

	  // operators
	  if (opStack.isEmpty()) {

	    CALC_DEBUG(cout << "pushing  op " << ch << endl);
	    opStack.push(ch);

	  } else if (precedence(ch) > precedence(opStack.peek())) {

	    CALC_DEBUG(cout << "pushing  op " << ch << endl);
	    opStack.push(ch);

	  } else {

		while (!opStack.isEmpty() && (precedence(ch) <= precedence(opStack.peek()))) {
		  executeSteps();
		}

		CALC_DEBUG(cout << "pushing  op " << ch << endl);
		opStack.push(ch);
	  }
	  break;

	case '(':

	  CALC_DEBUG(cout << "pushing  op " << ch << endl);
	  opStack.push(ch);
	  break;

	case ')':

	  while (opStack.peek() != '(') {
		executeSteps();
	  }
	  CALC_DEBUG(cout << "popping  op " << endl);
	  opStack.pop();
	  break;

	case ' ':
	  // skip spaces
	  break;

	default:
	  // TODO: handle error case
	  cout << "Should not get here:" << ch << endl;
	}
  }

  while (!opStack.isEmpty()) {
	executeSteps();
  }
  
  result = valStack.peek();
  return result;
}


int Calculator::precedence(char c) {

  int result = 0;

  // * and / have higher precedence than + and -
  switch (c) {

  case '*':  case '/':
	result = 2;
	break;

  case '+':  case '-':
	result = 1;
	break;

  default:
	// TODO handle error case - should not get here
	break;
  }
  return result;
}


void Calculator::executeSteps() {

  double result;

  double operand2 = valStack.peek();
  CALC_DEBUG(cout << "popping val " << operand2 << endl);
  valStack.pop();

  double operand1 = valStack.peek();
  CALC_DEBUG(cout << "popping val " << operand1 << endl);
  valStack.pop();

  char op = opStack.peek();
  CALC_DEBUG(cout << "popping  op " << op << endl);
  opStack.pop();

  switch(op) {

	case '+':
	  result = operand1 + operand2;
	  break;

	case '-':
	  result = operand1 - operand2;
	  break;

	case '*':
	  result = operand1 * operand2;
	  break;

	case '/':
	  result = operand1 / double(operand2);
	  break;

	default:
	  // TODO: handle errors - should not get here
	  break;
  }

  CALC_DEBUG(cout << "pushing val " << result << endl);
  valStack.push(result);
  return;
}
