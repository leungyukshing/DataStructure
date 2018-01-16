#include <iostream>
#include "Key.cpp"
#include "../OrderedList/OrderedList.hpp"
#include "../OrderedList/OrderedList.cpp"
using namespace std;

Error_code binary_search(const OrderedList &the_list,
                          const Key &target, int &position) {
  Record data;
  int bottom = 0, top = the_list.size() - 1;
  while (bottom < top) {
    int mid = (bottom + top) / 2;
    the_list.retrieve(mid, data);
    if (data < target)
      bottom = mid + 1;
    else
      top = mid;
  }
  if (top < bottom)
    return not_present;
  else {
    position = bottom;
    the_list.retrieve(bottom, data);
    if (data == target)
      return Success;
    else
      return not_present;
  }
}

int main() {
  int target = 14;
  int pos;

  OrderedList list;
  list.insert(1);
  list.insert(4);
  list.insert(6);
  list.insert(8);
  list.insert(12);
  list.insert(14);
  list.insert(20);
  list.insert(26);
  list.insert(28);

  if (binary_search(list, target, pos) == Success) {
    cout << "Find the target " << target << " in " << pos << endl;
  }
  else
    cout << "Fail to find the target." << endl;

  return 0;
}