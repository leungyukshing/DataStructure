#include "LinkedQueue.hpp"

template <class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue() {
  front = rear = NULL;
}

template <class Queue_entry>
bool LinkedQueue<Queue_entry>::empty() const {
  return this->front == NULL;
}

template <class Queue_entry>
Error_code LinkedQueue<Queue_entry>::append(const Queue_entry &item) {
  Node<Queue_entry>* new_rear = new Node<Queue_entry>(item);
  //System's memory is exhausted
  if (new_rear == NULL) {
    return OverFlow;
  }
  if (rear == NULL) {
    front = rear = new_rear;
  }
  else {
    rear->next = new_rear;
    rear = new_rear;
  }
  return Success;
}

template <class Queue_entry>
Error_code LinkedQueue<Queue_entry>::serve() {
  if (front == NULL) {
    return UnderFlow;
  }
  Node<Queue_entry> *old_front = front;
  front = old_front->next;
  if (front == NULL) {
    rear = NULL;
  }
  delete old_front;
  return Success;
}

template <class Queue_entry>
Error_code LinkedQueue<Queue_entry>::retrieve(Queue_entry &item) const {
  if (front != NULL) {
    item = front->entry;
    return Success;
  }
  else {
    return UnderFlow;
  }
}

template <class Queue_entry>
void LinkedQueue<Queue_entry>::clear() {
  Node<Queue_entry>* p1 = this->front;
  while (p1 != NULL) {
    Node<Queue_entry>* p2 = p1;
    p1 = p1->next;
    delete p2;
  }
  this->front = this->rear = NULL;
}

template <class Queue_entry>
LinkedQueue<Queue_entry>::~LinkedQueue() {
  clear();
}

template <class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue(const LinkedQueue<Queue_entry> &original) {
  if (original.empty()) {
    this->front = NULL;
    this->rear = NULL;
  }
  else if (original.front == original.rear) {
    this->front = this->rear = new Node<Queue_entry>(original.front->entry);
  }
  else {
    Node<Queue_entry>* p1 = original.front;
    this->front = new Node<Queue_entry>(p1->entry);
    Node<Queue_entry>* p2 = this->front;
    while (p1 != original.rear) {
      p1 = p1->next;
      p2->next = new Node<Queue_entry>(p1->entry);
      p2 = p2->next;
    }
    this->rear = p2;
  }
}

template <class Queue_entry>
bool LinkedQueue<Queue_entry>::operator == (const LinkedQueue<Queue_entry> &original) {
  Node<Queue_entry>* p1 = this->front;
  Node<Queue_entry>* p2 = original.front;
  
  while (p1 != NULL) {
    if (p2 != NULL && p1->entry == p2->entry) {
      p1 = p1->next;
      p2 = p2->next;
      continue;
    }
    else {
      return false;
    }
  }
  if (p2 != NULL) {
    return false;
  }
  return true;
}

template <class Queue_entry>
void LinkedQueue<Queue_entry>::operator=(const LinkedQueue<Queue_entry> &original) {
  if (*this == original) {
    return;
  }
  clear();
  if (original.empty()) {
    this->front = NULL;
    this->rear = NULL;
  }
  else if (original.front == original.rear) {
    this->front = this->rear = new Node<Queue_entry>(original.front->entry);
  }
  else {
    Node<Queue_entry>* p1 = original.front;
    this->front = new Node<Queue_entry>(p1->entry);
    Node<Queue_entry>* p2 = this->front;
    while (p1 != original.rear) {
      p1 = p1->next;
      p2->next = new Node<Queue_entry>(p1->entry);
      p2 = p2->next;
    }
    this->rear = p2;
  }
}

template <class Queue_entry>
int LinkedQueue<Queue_entry>::size() const {
  int size = 0;
  Node<Queue_entry> *p1 = this->front;
  while (p1 != NULL) {
    p1 = p1->next;
    size++;
  }
  return size;
}

template <class Queue_entry>
Error_code LinkedQueue<Queue_entry>::serve_and_retrieve(Queue_entry &item) {
  if (front == NULL) {
    return UnderFlow;
  }
  Node<Queue_entry> *old_front = front;
  front = old_front->next;
  if (front == NULL) {
    rear = NULL;
  }
  item = old_front->entry;
  delete old_front;
  return Success;
}
