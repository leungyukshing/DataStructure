#include "HashTable.hpp"
void Key::make_blank() {
  if (entries != NULL)
    delete []entries;
  length = 0;
  entries = new char[length + 1];
  strcpy(entries, "");
}

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

char Record::key_letter(int position) const {
  return name.key_letter(position);
}

Record::Record():name() {}

Record::operator Key() const {
  return name;
}

void Record::initialize(const Key &a_name) {
  name = a_name;
}

double Record::get_weight() {
  return weight;
}

void Record::set_weight(double w) {
  weight = w;
}

int alphabetic_order(char c) {
  if (c == ' ')
    return 0;
  if ('a' <= c && c <= 'z')
    return c - 'a' + 1;
  if ('A' <= c && c <= 'Z')
    return c - 'A' + 1;

  return 27;
}

int hash(const Key &target) {
  int value = 0;
  for (int position = 0; position < 8; position++) {
    value = 4 * value + target.key_letter(position);
  }
  value %= hash_size;
  if (value < 0) {
    value += hash_size;
  }
  return value;
}

HashTable::HashTable() {}

void HashTable::clear() {
  Key null;
  null.make_blank();
  for (int i = 0; i < hash_size; i++) {
    table[i].initialize(null);
  }
}

Error_code HashTable::insert(const Record &new_entry) {
  Error_code result = Success;
  int probe_count, // Counter to be sure that table is not full
      increment, // Increment used for quadratic probing
      probe; // Position currently probed in the hash table
  Key null; // null key for comparison purpose
  null.make_blank();
  probe = hash(new_entry);
  probe_count = 0;
  increment = 1;
  while (table[probe] != null  // Is the location empty?
          && table[probe] != new_entry // Dubplicate key?
          && probe_count < (hash_size + 1) / 2) { // Has overflow occurred?
    probe_count++;
    probe = (probe + increment) % hash_size;
    increment += 2; // prepare increment for next iteration
  }
  if (table[probe] == null)
    table[probe] = new_entry; // Insert new entry
  else if (table[probe] == new_entry)
    result = duplicate_error;
  else
    result = Overflow;

  return result;
}

Error_code HashTable::retrieve(const Key &target, Record &found) const {
  int probe_count, // counter to be sure that table is not full
      increment, // increment used for quadratic probing
      probe; // position currently probed in the hash table
  Key null; // null key for comparison purposes
  null.make_blank();
  probe = hash(target);
  probe_count = 0;
  increment = 1;
  while ((Key)table[probe] != null // Is the location empty?
          && (Key)table[probe] != target // Search Successful?
          && probe_count < (hash_size + 1) / 2) { // Full table?
  probe_count++;
  probe = (probe + increment) % hash_size;
  increment += 2;
  }
  if ((Key)table[probe] == target) {
    found = table[probe];
    return Success;
  }
  else
    return not_present;
}
