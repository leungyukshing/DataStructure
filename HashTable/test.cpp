#include <cstring>
#include "HashTable.hpp"

int main() {
  HashTable table;
  Record target;
  target.initialize("abc");
  cout << table.insert(target) << endl;
  target.initialize("happy");
  table.insert(target);

  Record tmp;
  Record t;
  t.initialize("joine");
  cout << table.retrieve(t, tmp) << endl;;
  return 0;
}