#include "Polynomial.hpp"
#include <iostream>
using namespace std;

void introduction() {
   cout << "Polynomial Calculator Program." << endl
        << "This program simulates a polynomial calculator that works on a\n"
        << "stack and a list of operations. The model is of a reverse Polish\n"
        << "calculator where operands are entered before the operators. An\n"
        << "example to add two polynomials and print the answer is ?P?Q+= .\n"
        << "P and Q are the operands to be entered, + is add, and = is\n"
        << "print result. The result is put onto the calculator's stack.\n\n";
}

void instructions() {
  cout << "\nEnter a string of instructions in reverse Polish form.\n"
       << "The allowable instructions are:\n\n"
       << "?:Read       +:Add           =:Print      -:Subtract\n"
       << "*:Multiply   q:Quit          /:Divide        h:Help\n\n";
}


bool do_command(char command, LinkedStack<Polynomial> &stored_polynomials) {
  Polynomial p, q, r;
  switch (command) {
    case '?':
      p.read();
      if (stored_polynomials.push(p) == OverFlow)
        cout << "Warning: Stack full, lost polynomial" << endl;
        break;
    case '=':
      if (stored_polynomials.empty())
        cout << "Stack empty" << endl;
      else {
        stored_polynomials.top(p);
        p.print();
      }
      break;
    case '+':
      if (stored_polynomials.empty())
        cout << "Stack empty" << endl;
      else {
        stored_polynomials.top(p);
        stored_polynomials.pop();
        if (stored_polynomials.empty()) {
          cout << "Stack has just one polynomial" << endl;
          stored_polynomials.push(p);
        }
        else {
          stored_polynomials.top(q);
          stored_polynomials.pop();
          r.equals_sum(q, p);
          if (stored_polynomials.push(r) == OverFlow)
            cout << "Warning: Stack full, lost polynomial" << endl;
        }
      }
      break;
    case 'h':
      instructions();
      break;
    // Add options for further user commands
    case 'q':
      cout << "Calculation finished." << endl;
      return false;
  }
  return true;
}


char get_command()
/* PRE:  None.
   POST: A legal command is read from the user and returned.  */
{
   char command, d;
   cout << "Select command and press <Enter>:";
   while (1) {
      do {
         cin.get(command);
      } while (command == '\n');
      do {
         cin.get(d);
      } while (d != '\n');
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' || 
          command == '-' || command == 'h' || command == '*' || 
          command == '/' || command == 'q' || command == 'p' || 
          command == 'h') {
         return (command);
      }
      cout << "Please enter a valid command:" << endl;
      instructions();
   }
}

int main() {
  LinkedStack<Polynomial> stored_polynomials;
  introduction();
  instructions();
  while (do_command(get_command(), stored_polynomials));
  return 0;
}
