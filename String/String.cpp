#include <cstring>
#include "String.hpp"
using namespace std;

String::String() {
  length = 0;
  entries = NULL;
}
String::~String() {
  clear();
}
// copy constructor
String::String (const String &copy) {
  this->length = copy.length;
  this->entries = new char[this->length + 1];
  strcpy(this->entries, copy.entries);
  this->entries[this->length] = '\0';
}
// conversion from C-string
String::String (const char *copy) {
  length = strlen(copy);
  entries = new char[length + 1];
  strcpy(entries, copy);
  entries[length] = '\0';
}
// conversion from List
String::String (list<char> &copy) {
  length = copy.size();
  entries = new char[length + 1];
  list<char>::iterator it = copy.begin();
  for (int i = 0; i < length; i++) {
    entries[i] = (*it);
    it++;
  }
  entries[length] = '\0';
}

void String::clear() {
  if (entries == NULL)
    return;

  length = 0;
  delete []entries;
  entries = NULL;
}
int  String::getLength() const { return length; }
void String::setLength(int l) { length = l; }
void String::operator=(const String &copy) {
  if (*this == copy)
    return;

  delete []this->entries;
  this->length = copy.length;
  this->entries = new char[this->length + 1];
  strcpy(this->entries, copy.entries);
  this->entries[this->length] = '\0';
}
// conversion to C-style string
const char *String::c_str() const {
  return (const char*) entries;
}

bool operator==(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) == 0;
}
bool operator>(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) > 0;
}
bool operator<(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) < 0;
}
bool operator>=(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) >= 0;
}
bool operator<=(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) <= 0;
}
bool operator!=(const String &first, const String &second) {
  return strcmp(first.c_str(), second.c_str()) != 0;
}

void strcat(String &add_to, const String &add_on) {
  const char *cfirst = add_to.c_str();
  const char *csecond = add_on.c_str();
  char *copy = new char[strlen(cfirst) + strlen(csecond) + 1];
  strcpy(copy, cfirst);
  strcat(copy, csecond);
  add_to = copy;
  delete []copy;
}
void strcpy(String &copy, const String &original) {
  if (copy == original)
    return;

  const char *coriginal = original.c_str();
  char *temp = new char[strlen(coriginal) + 1];
  strcpy(temp, coriginal);
  copy = temp;
  delete []temp;
}
void strncpy(String &copy, const String &original, int n) {
  const char *coriginal = original.c_str();
  char *temp = new char[n + 1];
  strncpy(temp, coriginal, n);
  temp[n] = '\0';
  copy = temp;
  delete []temp;
}
int strstr(const String &text, const String &target) {
  const char *ctext = text.c_str();
  const char *ctarget = target.c_str();
  char *pos = strstr(ctext, ctarget);
  int index = pos-ctext;
  
  return index;
}
String read_in(istream &input) {
  list<char> temp;
  int size = 0;
  char c;
  while ((c = input.peek()) != EOF && (c = input.get()) != '\n') {
    list<char>::iterator it = temp.begin();
    for (int i = 0; i < size; i++) {
      it++;
    }
    temp.insert(it, c);
    size++;
    
  }
  String answer(temp);
  return answer;
}
String read_in(int &terminator, istream &input) {
  list<char> temp;
  int size = 0;
  while ((terminator = input.peek()) != EOF && (terminator = input.get()) != '\n') {
    list<char>::iterator it = temp.begin();
    for (int i = 0; i < size; i++) {
      it++;
    }
    temp.insert(it, terminator);
    size++;
    
  }
  String answer(temp);
  return answer;
}
void write(String &s) {
  cout << s.c_str() << endl;
}