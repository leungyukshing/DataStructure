#ifndef STATICLIST_H
#define STATICLIST_H
#include "../ErrorCode/ErrorCode.hpp"

typedef int index;
const int max_list = 7; // small value for testing purposes

template <class List_entry>
class Node {
public:
  List_entry entry;
  index next;
};

template <class List_entry>
class StaticList {
public:
  StaticList();
  int size() const;
  bool full() const;
  bool empty() const;
  void clear();
  void traverse(void (*visit)(List_entry &));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);
protected:
  // Data members
  Node<List_entry> workplace[max_list];
  index available, last_used, head;
  int count;

  // Auxiliary member funtions
  index new_node();
  void delete_node(index n);
  int current_position(index n) const;
  index set_position(int position) const;
};
#endif