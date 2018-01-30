#include <iostream>
#include "Stack.hpp"
#include "Stack.cpp"
using namespace std;

int main() {
  Stack<int> stack;
  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  while (!stack.empty()) {
    int temp;
    stack.top(temp);
    cout << temp << " ";
    stack.pop();
  }
  cout << endl;
  return 0;
}