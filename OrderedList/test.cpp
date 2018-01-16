#include <iostream>
#include "OrderedList.hpp"
using namespace std;

void print(const OrderedList list) {
	cout << "The list is :";
	for (int i = 0; i < list.size(); i++) {
		Record x;
		list.retrieve(i, x);
		cout << x << " ";
	}
	cout << endl;
}
int main() {
	OrderedList list;

	for (int i = 0; i < 10; i++) {
		list.insert(i, i);
	}
	print(list);

	list.insert(3, 100);
	list.replace(2, 8);
	print(list);
	return 0;
}