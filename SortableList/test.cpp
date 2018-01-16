#include <iostream>
#include "SortableList.hpp"
#include "SortableList.cpp"
#include "../Random/Random.hpp"
#include "../Random/Random.cpp"
using namespace std;
const int key_size = 8;
/*
template <class Record>
void print(const SortableList<Record> list) {
  cout << "The list is: ";
  for (int i = 0; i < list.size(); i++) {
    Record x;
    list.retrieve(i, x);
    cout << x << " ";
  }
  cout << endl;
}*/

/*Test for radix_sort*/

void write_entry(Record &c) {
  for (int i = 0; i < 8; i++) {
    cout << c.key_letter(i);
    cout << " ";
  }
  cout << "\n";
}

int main() {
  int list_size = 10;
  Random dice;
  char word[9];
  word[8] = '\0';
  SortableList<Record> the_list;
  int i;
  for (i = 0; i < list_size; i++) {
    for (int j = 0; j < 8; j++) {
      word[j] = dice.random_integer(0, 26) + 'a';
    }
    Key target_name = word;
    Record target = target_name;
    if (the_list.insert(i, target) != Success) {
      cout << "Overflow in filling list." << endl;
    }
  }

  cout << "Program to demonostrate radix sort" << endl;
  cout << "Unsorted list\n";
  the_list.traverse(write_entry);
  cout << "\n";
  the_list.radix_sort(key_size);
  cout << "\nSorted list \n";
  the_list.traverse(write_entry);
  cout << "\n";
  /*
  list.insert(0, 26);
  list.insert(0, 77);
  list.insert(1, 83);
  list.insert(2, 1);
  list.insert(3, 89);
  list.insert(4, 32);
  list.insert(5, 45);
  list.insert(6, 29);
  list.insert(7, 17);
  list.insert(8, 19);
  list.insert(9, 100);
  list.insertion_sort();
  print(list);
  list.selection_sort();
  list.quick_sort();
  */
  return 0;
}