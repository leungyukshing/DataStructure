#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <iostream>
#include "../Node/Node.hpp"
#include "../ErrorCode/ErrorCode.hpp"

template <class Queue_entry>
class LinkedQueue {
public:
  LinkedQueue();
  bool empty() const;
  Error_code append(const Queue_entry &item);
  Error_code serve();
  Error_code retrieve(Queue_entry &item) const;
  
  // safety feartures for linked structures
  ~LinkedQueue();
  LinkedQueue(const LinkedQueue<Queue_entry> &original);
  void operator = (const LinkedQueue<Queue_entry> &original);
  bool operator == (const LinkedQueue<Queue_entry> &original);
  void clear();
  
  // Extended methods
  int size() const;
  Error_code serve_and_retrieve(Queue_entry &item);
private:
  Node<Queue_entry> *front, *rear;
};

#endif
