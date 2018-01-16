#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "../ErrorCode/ErrorCode.hpp"

template <class Node_entry>
struct Node {
  // data numbers
  Node_entry entry;
  Node<Node_entry> *next;
  Node<Node_entry> *back;
  // constructors
  Node() {
    next = back = NULL;
  }
  Node(Node_entry new_entry, Node<Node_entry> *link_back = NULL, Node<Node_entry> *link_next = NULL) {
    entry = new_entry;
    next = link_next;
    back = link_back;
  }
};

template <class List_entry>
class DoublyLinkedList {
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  DoublyLinkedList(const DoublyLinkedList<List_entry> &copy);
  void operator=(const DoublyLinkedList<List_entry> &copy);

  int size() const;
  bool full() const;
  bool empty() const;
  void clear();
  void traverse(void (*visit)(List_entry &));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);


private:
  int count;
  mutable int current_position;
  mutable Node<List_entry> *current;
  Node<List_entry> *first, *last;
  // The auxiliary function to locate list positions follows
  void set_position(int position) const;
};

#endif