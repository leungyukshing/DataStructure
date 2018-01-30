#ifndef STACK_H
#define STACK_H
#include "../ErrorCode/ErrorCode.hpp"

const int maxstack = 10;

template <class Stack_entry>
class Stack {
public:
  Stack();
  bool empty() const;
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  Error_code push(const Stack_entry &item);
private:
  int count;
  Stack_entry entry[maxstack];
};
#endif