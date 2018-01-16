#include "CircularQueue.hpp"

template <class Queue_entry>
CircularQueue<Queue_entry>::CircularQueue() {
  //The queue is initialized to be empty
  count = 0;
  rear = MAXQUEUE - 1;
  front = 0;
}

template <class Queue_entry>
bool CircularQueue<Queue_entry>::empty() const { return count == 0; }

template <class Queue_entry>
Error_code CircularQueue<Queue_entry>::serve() {
  //The front of the queue is removed.
  if (count <= 0) {
    return UnderFlow;
  }
  
  count--;
  front = ((front + 1) == MAXQUEUE) ? 0 : (front + 1);
  return Success;
}

template <class Queue_entry>
Error_code CircularQueue<Queue_entry>::append(const Queue_entry &item) {
  //item is added to the rear of the queue
  if (count >= MAXQUEUE) {
    return OverFlow;
  }
  count++;
  rear = ((rear + 1) == MAXQUEUE) ? 0 : (rear + 1);
  entry[rear] = item;
  return Success;
}

template <class Queue_entry>
Error_code CircularQueue<Queue_entry>::retrieve(Queue_entry &item) const {
  //The front of the queue retrieved to the output patameter item
  if (count <= 0) {
    item = -1;
    return UnderFlow;
  }
  item = entry[front];
  return Success;
}
