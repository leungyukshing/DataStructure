#include <iostream>
#include "StaticList.hpp"
#include "StaticList.cpp"
using namespace std;

int main() {
  StaticList<int> list;
  list.insert(0, 100);
  list.insert(1, 200);
  list.insert(2, 300);
  list.insert(3, 400);
  list.insert(4, 500);
  cout << "The size is: " << list.size() << endl;
  cout << "Is empty ?" << list.empty() << endl;
  cout << "Is full ?" << list.full() << endl;
  int x;
  list.retrieve(3, x);
  cout << x << endl;

  return 0; 
}