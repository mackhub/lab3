#include <iostream>

#include "Stack.h"

using namespace std;

int main(void)
{

  int i;
  string s;

  // test stack with numbers
  cout << "Testing stack with integers" << endl
       << "---------------------------" << endl;;
  Stack<int> stack;

  cout << "Stack empty? " << ((stack.isEmpty() == true) ? "Yes" : "No") << endl;

  cout << "Push 1" << endl;
  stack.push(1);
  cout << "Push 2" << endl;
  stack.push(2);
  cout << "Push 3" << endl;
  stack.push(3);

  cout << "Stack empty? " << ((stack.isEmpty() == true) ? "Yes" : "No") << endl;

  i = stack.peek();
  cout << "peek top of stack: " << i << endl;

  cout << "pop top of stack" << endl;
  stack.pop();

  i = stack.peek();
  cout << "peek top of stack: " << i << endl;

  cout << "pop top of stack" << endl;
  stack.pop();

  i = stack.peek();
  cout << "peek top of stack: " << i << endl;

  cout << "pop top of stack" << endl;
  stack.pop();

  cout << "Stack empty? " << ((stack.isEmpty() == true) ? "Yes" : "No") << endl << endl;;

  // test stack with strings
  cout << "Testing stack with strings" << endl
       << "--------------------------" << endl;;
  Stack<string> strstack;

  cout << "Stack empty? " << ((strstack.isEmpty() == true) ? "Yes" : "No") << endl;

  cout << "Push \"California\"" << endl;
  strstack.push("California");
  cout << "Push \"New York\"" << endl;
  strstack.push("New York");
  cout << "Push \"Illinois\"" << endl;
  strstack.push("Illinois");

  cout << "Stack empty? " << ((strstack.isEmpty() == true) ? "Yes" : "No") << endl;

  s = strstack.peek();
  cout << "peek top of stack: " << s << endl;

  cout << "pop top of stack" << endl;
  strstack.pop();

  s = strstack.peek();
  cout << "peek top of stack: " << s << endl;

  cout << "pop top of stack" << endl;
  strstack.pop();

  s = strstack.peek();
  cout << "peek top of stack: " << s << endl;

  cout << "pop top of stack" << endl;
  strstack.pop();

  cout << "Stack empty? " << ((strstack.isEmpty() == true) ? "Yes" : "No") << endl << endl;;

  return 0;
}
