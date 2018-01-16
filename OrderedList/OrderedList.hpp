#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include "../List/List.hpp"
#include "../List/List.cpp"
#include "../Search/Key.hpp"

class OrderedList: public List<Record> {
public:
  OrderedList();
  Error_code insert(const Record &data);
  Error_code insert(int position, const Record &data);
  Error_code replace(int position, const Record &data);
};
#endif