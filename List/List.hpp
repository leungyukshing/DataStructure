#ifndef LIST_H
#define LIST_H
#include "../ErrorCode/ErrorCode.hpp"

template <class List_entry>
class List {
public:
  List();
  ~List();
  List(const List<List_entry> &copy);
  void operator=(const List<List_entry> &copy);
  void clear();
  bool empty() const;
  int size() const;
  //operations
  Error_code insert(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  void traverse(void (*visit)(List_entry &));
protected:
  int count;
  List_entry* entry;
};
#endif
