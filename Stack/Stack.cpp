#include "Stack.hpp"

template <class Stack_entry>
Stack<Stack_entry>::Stack() { count = 0; }

template <class Stack_entry>
bool Stack<Stack_entry>::empty() const {
  return count == 0;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::pop() {
  if (count == 0)
    return UnderFlow;
  count--;
  return Success;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item) const{
  if (count == 0)
    return UnderFlow;
  item = entry[count - 1];
  return Success;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item) {
  if (count >= maxstack)
    return OverFlow;
  entry[count++] = item;
  return Success;
}