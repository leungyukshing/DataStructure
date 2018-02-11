#ifndef EXTENDEDQUEUE_H
#define EXTENDEDQUEUE_H
#include "../ErrorCode/ErrorCode.hpp"

#define MAXQUEUE 10

template <class Queue_entry>
class ExtendedQueue{
public:
  ExtendedQueue();
  bool empty() const;
  Error_code serve();
  Error_code append(const Queue_entry &item);
  Error_code retrieve(Queue_entry &item) const;
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
protected:
  int count;
  int front, rear;
  Queue_entry entry[MAXQUEUE];
};

#endif
