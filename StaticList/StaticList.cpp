#include "StaticList.hpp"

template <class List_entry>
StaticList<List_entry>::StaticList() {
  head = -1;
  count = 0;
  available = -1;
  last_used = -1;
}

template <class List_entry>
int StaticList<List_entry>::size() const {
  return count;
}

template <class List_entry>
bool StaticList<List_entry>::full() const {
  return count == max_list;
}

template <class List_entry>
bool StaticList<List_entry>::empty() const {
  return count == 0;
}

template <class List_entry>
void StaticList<List_entry>::clear() {
  index p, q;
  for (p = head; p != -1; p = q) {
    q = workplace[p].next;
    delete_node(p);
  }
  count = 0;
  head = -1;
}

template <class List_entry>
index StaticList<List_entry>::new_node() {
  index new_index;
  if (available != -1) {
    new_index = available;
    available = workplace[available].next;
  }
  else if (last_used < max_list - 1) {
    new_index = ++last_used;
  }
  else {
    return -1;
  }
  workplace[new_index].next = -1;
  return new_index;
}

template <class List_entry>
void StaticList<List_entry>::delete_node(index old_index) {
  index previous;
  if (old_index == head)
    head = workplace[old_index].next;
  else {
    previous = set_position(current_position(old_index) - 1);
    workplace[previous].next = workplace[old_index].next;
  }
  workplace[old_index].next = available;
  available = old_index;
}

template <class List_entry>
index StaticList<List_entry>::set_position(int position) const {
  index n = head;
  for (int i = 0; i < position; i++, n = workplace[n].next);
    return n;
}

template <class List_entry>
int StaticList<List_entry>::current_position(index n) const {
  int i = 0;
  for (index m = head; m != -1; m = workplace[m].next, i++) {
    if (m == n)
      return i;
  }
  return -1;
}

template <class List_entry>
void StaticList<List_entry>::traverse(void (*visit)(List_entry &)) {
  for (index n = head; n != -1; n = workplace[n].next)
    (*visit)(workplace[n].entry);
}

template <class List_entry>
Error_code StaticList<List_entry>::retrieve(int position, List_entry &x) const {
  index current;
  if (position < 0 || position >= count)
    return Range_over;
  current = set_position(position);
  x = workplace[current].entry;
  return Success;
}

template <class List_entry>
Error_code StaticList<List_entry>::replace(int position, const List_entry &x) {
  index current;
  if (position < 0 || position >= count)
    return Range_over;
  current = set_position(position);
  workplace[current].entry = x;
  return Success;
}

template <class List_entry>
Error_code StaticList<List_entry>::remove(int position, List_entry &x) {
  index prior, current;
  if (count == 0)
    return UnderFlow;
  if (position  < 0 || position >= count)
    return Range_over;
  if (position > 0) {
    prior = set_position(position - 1);
    current = workplace[prior].next;
    workplace[prior].next = workplace[current].next;
  }
  else {
    current = head;
    head = workplace[head].next;
  }
  x = workplace[current].entry;
  delete_node(current);
  count--;
  return Success;
}

template <class List_entry>
Error_code StaticList<List_entry>::insert(int position, const List_entry &x) {
  index new_index, previous, following;
  if (position < 0 || position > count)
    return Range_over;
  if (position > 0) {
    previous = set_position(position - 1);
    following = workplace[position].next;
  }
  else {  // insert the entry in the head
    following = head;
  }
  if ((new_index = new_node()) == -1) // Fail to allocate new space
    return OverFlow;
  workplace[new_index].entry = x;
  workplace[new_index].next = following;
  if (position == 0)
    head = new_index;
  else
    workplace[previous].next = new_index;
  count++;
  return Success;
}