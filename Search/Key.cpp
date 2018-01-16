#include "Key.hpp"
int Key::comparisons = 0;
Key::Key(int x) { key = x; }
int Key::the_key() const { return key; }

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
}