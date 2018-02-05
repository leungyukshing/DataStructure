#ifndef STRING_H
#define STRING_H
#include <list>
#include <iostream>
using namespace std;

class String {
public:
  String();
  ~String();
  // copy constructor
  String (const String &copy);
  // conversion from C-string
  String (const char *copy);
  // conversion from List
  String (list<char> &copy);
  void clear();
  void setLength(int l);
  int getLength() const;
  void operator=(const String &copy);
  // conversion to C-style string
  const char *c_str() const;
protected:
  char *entries;
  int length;
};

// comparison operators
bool operator==(const String &first, const String &second);
bool operator>(const String &first, const String &second);
bool operator<(const String &first, const String &second);
bool operator>=(const String &first, const String &second);
bool operator<=(const String &first, const String &second);
bool operator!=(const String &first, const String &second);

void strcat(String &add_to, const String &add_on);
void strcpy(String &copy, const String &original);
void strncpy(String &copy, const String &original, int n);
int strstr(const String &text, const String &target);
String read_in(istream &input = cin);
String read_in(int &terminator, istream &input = cin);
void write(String &s);
#endif