#ifndef SORTABLELIST_H
#define SORTABLELIST_H
#include "../DoublyLinkedList/DoublyLinkedList.hpp"
#include "../DoublyLinkedList/DoublyLinkedList.cpp"
#include "../LinkedQueue/LinkedQueue.hpp"
#include "../LinkedQueue/LinkedQueue.cpp"
#include "Key.hpp"


const int max_chars = 28;

template <class Record>
class SortableList:public DoublyLinkedList<Record> {
public:
	SortableList();
	// Add prototypes for sorting methods here
  void insertion_sort();
  void selection_sort();
  void quick_sort();
  void heap_sort();
  void radix_sort(int key_size);
private:
  // Add prototypes for auxiliary functions here
  void swap(int low, int high);
  int max_key(int low, int high);
  void recursive_quick_sort(int low, int high);
  int partition(int low, int high);
  void insert_heap(const Record &current, int low, int high);
  void build_heap();
  void rethread(LinkedQueue<Record> queues[]);
  int alphabetic_order(char c);
};
#endif