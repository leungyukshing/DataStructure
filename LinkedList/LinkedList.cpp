#include "LinkedList.hpp"
#include <iostream>
using namespace std;

template <class List_entry>
LinkedList<List_entry>::LinkedList() {
  count = 0;
  head = NULL;
}

template <class List_entry>
int LinkedList<List_entry>::size() const { return count; }


template <class List_entry>
bool LinkedList<List_entry>::empty() const { return count == 0; }

template <class List_entry>
void LinkedList<List_entry>::clear() {
  Node<List_entry>* p1 = head;
  while (p1 != NULL)
  {
    Node<List_entry>* temp = p1;
    p1 = p1->next;
    delete temp;
  }
  head = NULL;
  count = 0;
}

template <class List_entry>
void LinkedList<List_entry>::traverse(void (*visit)(List_entry&)) {
  Node<List_entry>* p1 = head;

  for (int i = 0; i < count; i++) {
    (*visit)(p1->entry);
    p1 = p1->next;
  }
}

template <class List_entry>
Error_code LinkedList<List_entry>::retrieve(int position, List_entry &x) const {
  if (empty()) {
    return UnderFlow;
  }
  if (position < 0 || position >= count) {
    return Range_over;
  }
  Node<List_entry>* p = set_position(position);
  x = p->entry;
  return Success;
}

template <class List_entry>
Error_code LinkedList<List_entry>::replace(int position, const List_entry &x) {
  if (empty()) {
    return UnderFlow;
  }
  if (position < 0 || position >= count) {
    return Range_over;
  }
  Node<List_entry>* p = set_position(position);
  p->entry = x;
  return Success;
}

template <class List_entry>
Error_code LinkedList<List_entry>::remove(int position, List_entry &x) {
  if (empty()) {
    return UnderFlow;
  }
  if (position < 0 || position >= count) {
    return Range_over;
  }
  if (count == 1) {
    delete head;
    head = NULL;
    count = 0;
    return Success;
  }
  Node<List_entry>* pre = set_position(position - 1);
  Node<List_entry>* p = set_position(position);
  pre->next = p->next;
  x = p->entry;
  delete p;
  count--;
  return Success;
}

template <class List_entry>
Error_code LinkedList<List_entry>::insert(int position, const List_entry &x) {
  if (position < 0 || position > count) {
    //cout << "hello" << endl;
    return Range_over;
  }
  if (position == 0) {
    Node<List_entry>* p = new Node<List_entry>(x);
    p->next = head;
    head = p;
    count++;
    return Success;
  }
  else {
    Node<List_entry>* p = new Node<List_entry>(x);
    Node<List_entry>* pre = set_position(position - 1);
    p->next = pre->next;
    pre->next = p;
    count++;
    return Success;
  }
}

template <class List_entry>
LinkedList<List_entry>::~LinkedList() {
  count = 0;
  clear();
}

template <class List_entry>
LinkedList<List_entry>::LinkedList(const LinkedList<List_entry> &copy) {
  if (copy.head == NULL) {
    this->head = NULL;
    this->count = 0;
  }
  else {
    Node<List_entry>* p2 = copy.head;
    this.head = new Node<List_entry>(p2->entry);
    p2 = p2->next;
    Node<List_entry>* p1 = this.head;
    this.count = copy.count;

    while (p2 != NULL) {
      p1->next = new Node<List_entry>(p2->entry);
      p1 = p1->next;
      p2 = p2->next;
    }
  }
}

template <class List_entry>
void LinkedList<List_entry>::operator=(const LinkedList<List_entry> &copy) {
  if (*this == copy) {
    return;
  }
  clear();
  if (copy.head == NULL) {
    this->head = NULL;
    this->count = 0;
  }
  else {
    Node<List_entry>* p2 = copy.head;
    this.head = new Node<List_entry>(p2->entry);
    p2 = p2->next;
    Node<List_entry>* p1 = this.head;
    this.count = copy.count;

    while (p2 != NULL) {
      p1->next = new Node<List_entry>(p2->entry);
      p1 = p1->next;
      p2 = p2->next;
    }
  }
}

//auxiliary function used to locate list positions
template <class List_entry>
Node<List_entry> *LinkedList<List_entry>::set_position(int position) const {
  Node<List_entry>* p1 = head;
  if (position < 0 || position >= count) {
    return NULL;
  }

  while (position--) {
    p1 = p1->next;
  }
  return p1;
}