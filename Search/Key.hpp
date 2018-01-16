#ifndef KEY_H
#define KEY_H
typedef int Record;
class Key {
public:
  static int comparisons;
  Key (int x = 0);
  int the_key() const;
private:
  int key;
};

// Declare overloaded comparison operators for keys
bool operator == (const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >= (const Key &x, const Key &y);
bool operator <= (const Key &x, const Key &y);
bool operator != (const Key &x, const Key &y);
/*
class Record {
public:
  operator Key() { return Key(record); }
private:
  int record;
};*/
#endif