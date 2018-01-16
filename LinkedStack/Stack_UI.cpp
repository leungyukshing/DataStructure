#include "LinkedStack.hpp"
#include "LinkedStack.cpp"
#include <iostream>
using namespace std;

char get_command() {
  char cmd;
  bool waiting = true;
  
  while (waiting) {
    cout << "-----------------------------------" << endl;
    cout << "[1] push" << endl;
    cout << "[2] pop" << endl;
    cout << "[3] get the top element" << endl;
    cout << "[4] check whether the stack is empty" << endl;
    //cout << "[5] check whether the stack is full" << endl;
    cout << "[q] quit the program" << endl;
    cout << "Select command and press <Enter>:";
    cin >> cmd;
    cmd = tolower(cmd);
    if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == 'q') {
      waiting = false;
    }
  }
  return cmd;
}

template <class Stack_entry>
bool do_command(char command, LinkedStack<Stack_entry> &st) {
  switch (command) {
    case '1': 
      cout << "Enter the element you want to push in:";
      Stack_entry ele0;
      cin >> ele0;
      if (st.push(ele0) == OverFlow) {
        cout << "Warning: Stack full, lost number£¡" << endl;
      }
      else {
        cout << "Push succeed!" << endl;
      }
      break;
    case '2':
      if (st.pop() == UnderFlow) {
        cout << "Warning: Stack empty!" << endl; 
        break;
      }
      cout << "Pop succeed!" << endl;
      break;
    case '3':
      Stack_entry ele2;
      if (st.top(ele2) == Success) {
        cout << "Top element is " << ele2 << endl;
      }
      else {
        cout << "Stack is empty" << endl;
      }
      break;
    case '4':
      if (st.empty()) {
        cout << "Stack is empty" << endl;
      }
      else {
        cout << "Stack is not empty" << endl;
      }
      break;
    case 'q':
      cout << "Thank you for using!Bye!" << endl;
      return false;
  }
  return true;
}

int main() {
  LinkedStack<double> st;
  cout << "Welcome to use LinkedStack!(double version)" << endl;
  while (do_command(get_command(), st));
  return 0;
}