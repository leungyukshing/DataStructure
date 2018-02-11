#include "SortableList.hpp"
#include <iostream>
using namespace std;

template <class Record>
SortableList<Record>::SortableList():List<Record>() {}

template <class Record>
void SortableList<Record>::insertion_sort() {
  cout << this->count << endl;
  int first_unsorted; // position of the first unsorted entry
  int position; // searches sorted part of list
  Record current; // holds the entry temporarily removed from list
  for (first_unsorted = 1; first_unsorted < this->count; first_unsorted++) {
    if (this->entry[first_unsorted] < this->entry[first_unsorted - 1]) {
      position = first_unsorted;
      current = this->entry[first_unsorted];
      do {
        this->entry[position] = this->entry[position - 1];
        position--;
      } while (position > 0 && this->entry[position - 1] > current);
      this->entry[position] = current;
    }
  }
}

template <class Record>
void SortableList<Record>::selection_sort() {
  for (int position = this->count - 1; position > 0; position--) {
    int max = max_key(0, position);
    swap(max, position);
  }
}

template <class Record>
int SortableList<Record>::max_key(int low, int high) {
  int largest, current;
  largest = low;
  for (current = low + 1; current <= high; current++) {
    if (this->entry[largest] < this->entry[current]) {
      largest = current;
    }
  }
  return largest;
}

template <class Record>
void SortableList<Record>::swap(int low, int high) {
  Record temp;
  temp = this->entry[low];
  this->entry[low] = this->entry[high];
  this->entry[high] = temp;
}

template <class Record>
void SortableList<Record>::quick_sort() {
  recursive_quick_sort(0, this->count - 1);
}

template <class Record>
void SortableList<Record>::recursive_quick_sort(int low, int high) {
  int pivot_position;
  if (low < high) {
    pivot_position = partition(low, high);
    recursive_quick_sort(low, pivot_position - 1);
    recursive_quick_sort(pivot_position + 1, high);
  }
}

template <class Record>
int SortableList<Record>::partition(int low, int high) {
  Record pivot;
  int i, last_small; // last_small is the last key less than pivot
  swap(low, (low + high) / 2);
  pivot = this->entry[low]; // First entry now is pivot
  last_small = low;
  for (i = low + 1; i <= high; i++) {
    if (this->entry[i] < pivot) {
      last_small++;
      swap(last_small, i); // move large entry to right and small to left
    }
  }
  swap(low, last_small); // put the pivot into its proper position
  return last_small;
}

template <class Record>
void SortableList<Record>::heap_sort() {
  Record current;
  int last_unsorted;
  build_heap();
  for (last_unsorted = this->count - 1; last_unsorted > 0; last_unsorted--) {
    current = this->entry[last_unsorted];
    this->entry[last_unsorted] = this->entry[0];
    insert_heap(current, 0, last_unsorted - 1);
  }
}

template <class Record>
void SortableList<Record>::insert_heap(const Record &current, int low, int high) {
  int large; // position of child of entry[low] with the larger key
  large = 2 * low + 1; // large is now the left child of low
  while (large <= high) {
    if (large < high && this->entry[large] < this->entry[large + 1]) {   // 有右节点且左节点<右节点
      large++;
    }
    if (current >= this->entry[large])  // current belongs in position low
      break;
    else {
      this->entry[low] = this->entry[large];
      low = large;
      large = 2 * low + 1;
    }
  }
  this->entry[low] = current;
}

template <class Record>
void SortableList<Record>::build_heap() {
  int low;
  for (low = this->count / 2 - 1; low >= 0; low--) {
    Record current = this->entry[low];
    insert_heap(current, low, this->count - 1);
  }
}
template <class Record>
int SortableList<Record>::alphabetic_order(char c) {
  if (c == ' ')
    return 0;
  if ('a' <= c && c <= 'z')
    return c - 'a' + 1;
  if ('A' <= c && c <= 'Z')
    return c - 'A' + 1;

  return 27; // junk queue
}

template <class Record>
void SortableList<Record>::radix_sort(int key_size) {
  Record data;
  LinkedQueue<Record> queues[max_chars];
  for (int position = key_size - 1; position >= 0; position--) {
    // Loop from the least to the most significant position
    while (this->remove(0, data) == Success) {
      int queue_number = alphabetic_order(data.key_letter(position));
      queues[queue_number].append(data); // Queue operation
    }
    rethread(queues); // Reassemble the list
  }
}
/*
template <class Record>
int SortableList<Record>::getKeySize() const {
  int key_size = 0;
  for (int i = 0; i < this->size(); i++) {
    if (this->entry[i].length() > key_size) {
      key_size = this->entry[i].length();
    }
  }
  return key_size;
}*/

template <class Record>
void SortableList<Record>::rethread(LinkedQueue<Record> queues[]) {
  Record data;
  for (int i = 0; i < max_chars; i++) {
    // 对每一个桶抽取出所有元素出来并清空
    while (!queues[i].empty()) {
      queues[i].retrieve(data);
      this->insert(this->size(), data);
      queues[i].serve();
    }
  }
}