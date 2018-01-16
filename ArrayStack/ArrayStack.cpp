#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

template <class Stack_Ele>
ArrayStack<Stack_Ele>::ArrayStack() {
  stack = new Stack_Ele[10];
  size = -1;
}

template <class Stack_Ele>
Error_code ArrayStack<Stack_Ele>::pop() {
  if (size == -1) {
    cout << "Stack is empty." << endl;
    return UnderFlow;
  }
  else {
    size--;
    return Success;
  }
}

template <class Stack_Ele>
Stack_Ele ArrayStack<Stack_Ele>::top() {
  if (size == -1) {
    cout << "Stack is empty." << endl;
    return -1;
  }
  else {
    return stack[size];
  }
}

template <class Stack_Ele>
Error_code ArrayStack<Stack_Ele>::push(Stack_Ele ele) {
  if (size == 9) {
    cout << "Stack is full." << endl;
    return OverFlow;
  }
  else {
    size++;
    stack[size] = ele;
  }
}

template <class Stack_Ele>
bool ArrayStack<Stack_Ele>::empty() { return size == -1; }

template <class Stack_Ele>
bool ArrayStack<Stack_Ele>::full() { return size == 9; }
