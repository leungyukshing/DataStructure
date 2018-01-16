#include <iostream>
#include "OrderedList.hpp"
using namespace std;

OrderedList::OrderedList():List<Record>() {}
Error_code OrderedList::insert(const Record &data) {
  int s = size();
  int position;
  for (position = s - 1; position >= 0; position--) {
    Record list_data;
    retrieve(position, list_data);
    if (data >= list_data)
      break;
  }
  return List<Record>::insert(position + 1, data);
}
Error_code OrderedList::insert(int position, const Record &data) {
  Record list_data;
  // 检查插入位置的前后元素与data的大小关系
  if (position > 0) {
    retrieve(position - 1, list_data);
    if (data < list_data) {
      return fail;
    }
  }
  if (position < size()) {
    retrieve(position, list_data);
    if(data > list_data)
      return fail;
  }
  //cout << "hello" << endl;
  return List<Record>::insert(position, data);
}
Error_code OrderedList::replace(int position, const Record &data) {
  Record list_data;

  if (position > 0) {
    retrieve(position - 1, list_data);
    if (data < list_data)
      return fail;
  }
  if (position < size() - 1) {
    retrieve(position + 1, list_data);
    if(data > list_data)
      return fail;
  }
  return List<Record>::replace(position, data);
}

/*test function for orderedlist*/
/*
void print(const OrderedList list) {
  cout << "The list is :";
  for (int i = 0; i < list.size(); i++) {
    Record x;
    list.retrieve(i, x);
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  OrderedList list;

  for (int i = 0; i < 10; i++) {
    list.insert(i, i);
  }
  print(list);

  list.insert(-100);
  list.replace(3,4);
  print(list);
  return 0;
}*/