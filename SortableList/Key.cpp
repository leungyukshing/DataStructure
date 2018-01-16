#include "Key.hpp"
#include <cstring>

void Key::make_blank() {
  if (this->entries != NULL)
    delete []entries;
  length = 0;
  entries = new char[length + 1];
  strcpy(entries, "");
}

Key::~Key() {}

Key::Key() {
  make_blank();
}

char Key::key_letter(int position) const {
  if (position >= 0 && position < length)
    return entries[position];
  else
    return ' ';
}

Key::Key(const char *copy):String(copy) {}
/*
// Declare overloaded comparisons operators for keys
bool operator == (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() == y.the_key();
}
bool operator > (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() > y.the_key();
}
bool operator < (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() < y.the_key();
}
bool operator >= (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() >= y.the_key();
}
bool operator <= (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() <= y.the_key();
}
bool operator != (const Key &x, const Key &y) {
  Key::comparisons++;
  return x.the_key() != y.the_key();
}*/

Record::Record():name() {}

char Record::key_letter(int position) const {
  return name.key_letter(position);
}
Record::operator Key() const {
  return name;
}
Record::Record(const Key &a_name) {
  name = a_name;
}