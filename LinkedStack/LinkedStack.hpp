#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "../Node/Node.hpp"
#include "../ErrorCode/ErrorCode.hpp"
using namespace std;

template <class Stack_entry>
class LinkedStack {
public:
  // Standard Stack methods
  LinkedStack();
  bool empty() const;
  Error_code push(const Stack_entry &item);
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  // Safety features for linked structures
  ~LinkedStack();
  LinkedStack(const LinkedStack &orgiginal);
  void operator=(const LinkedStack &original);
private:
  Node<Stack_entry>* top_node; 
};
#endif
