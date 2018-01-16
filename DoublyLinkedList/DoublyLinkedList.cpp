#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

template <class List_entry>
DoublyLinkedList<List_entry>::DoublyLinkedList() {
  count = 0;
  first = last = NULL;
  current_position = -1;
}

template <class List_entry>
DoublyLinkedList<List_entry>::~DoublyLinkedList() {
  clear();
}

template <class List_entry>
DoublyLinkedList<List_entry>::DoublyLinkedList(const DoublyLinkedList<List_entry> &copy) {
  count = copy.count;
  Node<List_entry> *new_node, *old_node = copy.current;
  if (old_node == NULL)
    current = NULL;
  else {
    new_node = current = new Node<List_entry>(old_node->entry);
    while (old_node->next != NULL) {
      old_node = old_node->next;
      new_node->next = new Node<List_entry>(old_node->entry, new_node);
      new_node = new_node->next;
    }
    old_node = copy.current;
    new_node = current;
    while (old_node->back != NULL) {
      old_node = old_node->back;
      new_node->back = new Node<List_entry>(old_node->entry, NULL, new_node);
      new_node = new_node->back;
    }
  }
}

template <class List_entry>
void DoublyLinkedList<List_entry>::operator=(const DoublyLinkedList<List_entry> &copy) {
  DoublyLinkedList new_copy(copy);
  clear();
  count = new_copy.count;
  current_position = new_copy.current_position;
  current = new_copy.current;
  new_copy.count = 0;
  new_copy.current_position = 0;
  new_copy.current = NULL;
}

template <class List_entry>
int DoublyLinkedList<List_entry>::size() const { return count; }

template <class List_entry>
bool DoublyLinkedList<List_entry>::full() const { return false; }
template <class List_entry>
bool DoublyLinkedList<List_entry>::empty() const { return count == 0; }

template <class List_entry>
void DoublyLinkedList<List_entry>::clear() {
  Node<List_entry> *p, *q;
  if (current == NULL)
    return;
  for (p = current->back; p; p = q) {
    q = p->back;
    delete p;
  }
  for (p = current; p; p = q) {
    q = p->next;
    delete p;
  }
  count = 0;
  first = last = current = NULL;
  current_position = -1;
}

template <class List_entry>
void DoublyLinkedList<List_entry>::traverse(void (*visit)(List_entry &)) {
  /*for (int i = 0; i < count; i++) {
    set_position(i);
    
    (*visit)(current->entry);
    if (current->next != NULL) {
      current = current->next;
      current_position = i + 1;
    }
  }*/
  Node<List_entry> *to_visit = first;
  for (; to_visit; to_visit = to_visit->next) {
    (*visit)(to_visit->entry);
  }
}

template <class List_entry>
Error_code DoublyLinkedList<List_entry>::retrieve(int position, List_entry &x) const {
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;

  set_position(position);
  x = current->entry;
  return Success;
}

template <class List_entry>
Error_code DoublyLinkedList<List_entry>::replace(int position, const List_entry &x) {
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;

  set_position(position);
  current->entry = x;
  return Success;
}

template <class List_entry>
Error_code DoublyLinkedList<List_entry>::remove(int position, List_entry &x) {
  Node<List_entry> *old_node, *neighbor;
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;

  set_position(position);
  old_node = current;
  if (neighbor = current->back)
    neighbor->next = current->next;
  if (neighbor = current->next) {
    neighbor->back = current->back;
    current = neighbor;
  }
  else {
    last = current = current->back;
    current_position--;
  }
  x= old_node->entry;
  delete old_node;
  count--;
  if (position == 0)
    first = current;
  return Success;
  /*
  x = current->entry;
  //cout << "hello" << endl;
  if (position == 0) {
    if (count == 1) {
      delete current;
      current = NULL;
      current_position = -1;
      //cout << "finish" << endl;
    }
    else {
      //cout << "two" << endl;
      current->next->back = NULL;
      Node<List_entry> *p = current;
      current = current->next;
      p->next = NULL;
      delete p;
      p = NULL;
      current_position = 0;
    }
   
  }
  else if (position == count - 1) {
    Node<List_entry> *p = current;
    current->back->next = NULL;
    current = current->back;
    delete p;
    current_position = position;
  }
  else {
    //cout << "much" << endl;
    Node<List_entry> *following, *preceding;
    following = current->next;
    preceding = current->back;
    preceding->next = following;
    following->back = preceding;
    Node<List_entry> *p = current;
    current = current->back;
    delete p;
    current_position = position - 1;
  }
  count--;
  return Success;
  */
}

template <class List_entry>
Error_code DoublyLinkedList<List_entry>::insert(int position, const List_entry &x) {
  /*
  Node<List_entry> *new_node, *following, *preceding;
  // position is out of range
  if (position < 0 || position > count) {
    return Range_over;
  }
  // insert an element on the head
  if (position == 0) {
    if (count == 0) {
      following = NULL;
    }
    else {
      set_position(0);
      following = current;
    }
    preceding = NULL;
  }
  // insert an element on the middle of the list
  else {
    // set current pointer to locate the preceding position
    set_position(position - 1);
    preceding = current;
    following = preceding->next;
  }

  // allocate space to the new element
  new_node = new Node<List_entry>(x, preceding, following);
  if (new_node == NULL)
    return OverFlow;
  if (preceding != NULL)
    preceding->next = new_node;
  if (following != NULL)
    following->back = new_node;

  current = new_node;
  current_position = position;
  count++;
  return Success;
  */
  Node<List_entry> *new_node, *following, *preceding;
  if (position < 0 || position > count)
    return Range_over;
  if (position == 0) {
    cout << "1" << endl;
    if (count == 0)
      following = NULL;
    else {
      set_position(0);
      following = current;
      }
      preceding = NULL;
  }
  else {
    set_position(position - 1);
    preceding = current;
    following = preceding->next;
  }
  cout << "2" << endl;
  new_node = new Node<List_entry>(x, preceding, following);
  if (new_node == NULL)
    return OverFlow;
  if (preceding != NULL)
    preceding->next = new_node;
  if (following != NULL)
    following->back = new_node;
  current = new_node;
  current_position = position;
  if (position == 0)
    first = current;
  if (position == count)
    last = current;
  count++;
  cout << "count = " << count << endl;
  return Success;
}
// The auxiliary function to locate list positions follows
template <class List_entry>
void DoublyLinkedList<List_entry>::set_position(int position) const {
  if (current_position == position)
    return;
  else if (current_position < position) {
    for (; current_position != position; current_position++) {
      current = current->next;
    }
  }
  else {
    for (; current_position != position; current_position--) {
      current = current->back;
    }
  }
}