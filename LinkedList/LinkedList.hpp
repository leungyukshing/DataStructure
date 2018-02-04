#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "../Node/Node.hpp"
#include "../ErrorCode/ErrorCode.hpp"

template <class List_entry>
class LinkedList {
public:
  LinkedList();
  int size() const;
  //bool full() const;
  bool empty() const;
  void clear();
  void traverse(void (*visit)(List_entry&));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);
  ~LinkedList();
  LinkedList(const LinkedList<List_entry> &copy);
  void operator=(const LinkedList<List_entry> &copy);
private:
  int count;
  Node<List_entry> *head;

  //auxiliary function used to locate list positions
  Node<List_entry> *set_position(int position) const;
};
#endif