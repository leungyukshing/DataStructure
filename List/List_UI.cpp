#include "List.hpp"
#include "List.cpp"
#include <iostream>
using namespace std;

char get_command() {
	char cmd;
	bool waiting = true;
	
	while (waiting) {
		cout << "-----------------------------------" << endl;
		cout << "[1] Insert an element" << endl;
		cout << "[2] Retrieve an element" << endl;
		cout << "[3] Remove an element" << endl;
		cout << "[4] Replace an element" << endl;
		cout << "[5] check whether the list is empty" << endl;
		cout << "[6] Get the size of the list" << endl;
		cout << "[c] Clear the list" << endl;
		cout << "[q] quit the program" << endl;
		cout << "Select command and press <Enter>:";
		cin >> cmd;
		cmd = tolower(cmd);
		if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || cmd == '6' ||
		 		cmd == 'c' || cmd == 'q') {
			waiting = false;
		}
	}
	return cmd;
}

template <class List_entry>
bool do_command(char command, List<List_entry> &list) {
	int list_size = list.size();
	switch (command) {
		case '1': 
			{//Prompt the user to input an element
			cout << "Enter the element you want to insert:";
			List_entry ele0;
			cin >> ele0;
			//Prompt the user to input the position
			cout << "Enter the position you want to put the element in [0, " << list_size << "]: ";
			int pos0;
			cin >> pos0;
			//handle operation
			Error_code state0 = list.insert(pos0, ele0);
			if (state0 == OverFlow) {
				cout << "Warning: List full, lost number!" << endl;
			}
			else if (state0 == Range_over) {
				cout << "The position you input is out of range!" << endl;
			}
			else {
				cout << "Insert succeed!" << endl;
			}
			break;
			}
		case '2':
			{//Prompt the user to input the position
			cout << "Enter the position you want to get the element out [0, " << list_size - 1 << "]: ";
			int pos1;
			cin >> pos1;

			List_entry ele1;
			Error_code state1 = list.retrieve(pos1, ele1);
			if (state1 == UnderFlow) {
				cout << "Warning: List empty!" << endl;
			}
			else if (state1 == Range_over) {
				cout << "The position you input is out of range!" << endl;
			}
			else {
				cout << "Retrieve succeed! The element is " << ele1 << endl;
			}
			break;
			}
		case '3':
			{//Prompt the user to input the position
			cout << "Enter the position you want to remove the element [0, " << list_size - 1 << "]: ";
			int pos2;
			cin >> pos2;

			List_entry ele2;
			Error_code state3 = list.remove(pos2, ele2);
			if (state3 == UnderFlow) {
				cout << "Warning: List empty!" << endl;
			}
			else if (state3 == Range_over) {
				cout << "The position you input is out of range!" << endl;
			}
			else {
				cout << "Remove succeed! The element just removed is " << ele2 << endl;
			}
			break;
			}
		case '4':
			{//Prompt the user to input the position
			cout << "Enter the position you want to replace [0, " << list_size - 1 << "]: ";
			int pos3;
			cin >> pos3;
			cout << "Enter the element you want to replace with: ";
			List_entry ele3;
			cin >> ele3;
			Error_code state4 = list.replace(pos3, ele3);
			if (state4 == UnderFlow) {
				cout << "Warning: List empty!" << endl;
			}
			else if (state4 == Range_over) {
				cout << "The position you input is out of range!" << endl;
			}
			else {
				cout << "Remove succeed!" << ele3 << endl;
			}
			break;
			}
		case '5':
			if (list.empty()) {
				cout << "List is empty" << endl;
			}
			else {
				cout << "List is not empty" << endl;
			}
			break;
		case '6':
			cout << "The present list size is " << list_size << endl;
			break;
		case 'c':
			//Prompt the user to confirm the clear operation
			cout << "Are you sure to clear the list? Y for Yes and N for No.  ";
			char ch;
			cin >> ch;
			if (ch == 'Y') {
				list.clear();
				cout << "Clear succeed!" << endl;
			}
			break;
		case 'q':
			cout << "Thank you for using!Bye!" << endl;
			return false;
		default:
			return false;
	}
	return true;
}

int main() {
	cout << "Welcome to use List!" << endl;
	List<double> list;
	while (do_command(get_command(), list));
	return 0;
}
