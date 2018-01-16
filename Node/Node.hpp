#ifndef NODE_H
#define NODE_H

template <class Node_entry>
struct Node {
  //data members
  Node_entry entry;
  Node<Node_entry> *next;
  // constructors
  Node() {
    entry = 0;
    next = NULL;
  }
  Node(Node_entry _entry, Node<Node_entry> *link = NULL) {
    entry = _entry;
    next = link;
  }
};

#endif