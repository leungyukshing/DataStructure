#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../String/String.hpp"


const int hash_size = 997; // a prime number of appropriate size
enum Error_code {Success, Overflow, duplicate_error, not_present};

class Key: public String {
public:
  char key_letter(int position) const;
  void make_blank();
  Key(const char *copy);
  Key();
};

class Record {
public:
  double get_weight();
  void set_weight(double w);
  char key_letter(int position) const;
  Record(); // default constructor
  operator Key() const; // cast to Key
  void initialize(const Key &a_name); // conversion to Record
private:
  Key name;
  double weight;
};

class HashTable {
public:
  HashTable();
  void clear();
  Error_code insert(const Record &new_entry);
  Error_code retrieve(const Key &target, Record &found) const;
private:
  Record table[hash_size];
};
#endif