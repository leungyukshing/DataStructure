#ifndef KEY_H
#define KEY_H
#include "../String/String.hpp"
#include "../String/String.cpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Key:public String {
public:
  char key_letter(int position) const;
  void make_blank();
  Key(const char* copy);
  Key();
  ~Key();
};

// Declare overloaded comparison operators for keys
/*bool operator == (const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >= (const Key &x, const Key &y);
bool operator <= (const Key &x, const Key &y);
bool operator != (const Key &x, const Key &y);
*/
class Record {
public:
  char key_letter(int position)const;
  Record(); // default constructor
  operator Key() const; // cast to Key
  Record(const Key &a_name); // conversion to Record
private:
  Key name;
};

#endif