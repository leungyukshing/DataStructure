#include "List.hpp"
template <class List_entry>
List<List_entry>::List() {
  count = 0;
  entry = new List_entry[100];
  for (int i = 0; i < 100; i++) {
    entry[i] = 0;
  }
}

template <class List_entry>
List<List_entry>::~List() {
  delete []entry;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy) {
  count = copy.count;
  this->entry = new List_entry[100];
  for (int i = 0; i < 100; i++) {
    this->entry[i] = copy.entry[i];
  }
}

template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy) {
  count = copy.count;
  for (int i = 0; i < count; i++) {
    this->entry[i] = copy.entry[i];
  }
}

template <class List_entry>
void List<List_entry>::clear() {
  count = 0;
}

template <class List_entry>
bool List<List_entry>::empty() const { return count == 0; }

template <class List_entry>
int List<List_entry>::size() const { return count; }

//operations
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
  if (position < 0 || position > count)
    return Range_over;
  for (int i = count -1; i>= position; i--) {
    entry[i + 1] = entry[i];
  }
  entry[position] = x;
  count++;
  return Success;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;
  x = entry[position];
  for (int i = position; i < count; i++)
  {
    entry[i] = entry[i + 1];
  }
  count--;
  return Success;
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;
  x = entry[position];
  return Success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
  if (empty())
    return UnderFlow;
  if (position < 0 || position >= count)
    return Range_over;
  entry[position] = x;
  return Success;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
  for (int i = 0; i < count; i++)
    (*visit)(entry[i]);
}
