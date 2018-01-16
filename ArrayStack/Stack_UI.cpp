#include "ArrayStack.hpp"
#include "ArrayStack.cpp"
#include <iostream>
using namespace std;

char get_command() {
	char cmd;
	bool waiting = true;
	
	while (waiting) {
		cout << "-----------------------------------" << endl;
		cout << "[1] push" << endl;
		cout << "[2] pop" << endl;
		cout << "[3] get the top element" << endl;
		cout << "[4] check whether the stack is empty" << endl;
		cout << "[5] check whether the stack is full" << endl;
		cout << "[q] quit the program" << endl;
		cout << "Select command and press <Enter>:";
		cin >> cmd;
		cmd = tolower(cmd);
		if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || cmd == 'q') {
			waiting = false;
		}
	}
	return cmd;
}

template <class Stack_Ele>
bool do_command(char command, ArrayStack<Stack_Ele> &st) {
	switch (command) {
		case '1': 
			cout << "Enter the element you want to push in:";
			Stack_Ele ele0;
			cin >> ele0;
			if (st.push(ele0) == OverFlow) {
				cout << "Warning: Stack full, lost number!" << endl;
			}
			else {
				cout << "Push succeed!" << endl;
			}
			break;
		case '2':
			if (st.pop() == UnderFlow) {
				cout << "Warning: Stack empty!" << endl; 
				break;
			}
			cout << "Pop succeed!" << endl;
			break;
		case '3':
			Stack_Ele ele2;
			ele2 = st.top();
			cout << "Top element is " << ele2 << endl;
			break;
		case '4':
			if (st.empty()) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Stack is not empty" << endl;
			}
			break;
		case '5':
			if ( st.full()) {
				cout << "Stack is full" << endl;
			}
			else {
				cout << "Stack is not full" << endl;
			}
			break;
		case 'q':
			cout << "Thank you for using!Bye!" << endl;
			return false;
		default:
			cout << "Please enter the right command again!" << endl;
			break;
	}
	return true;
}

int main() {
	ArrayStack<int> st;
	cout << "Welcome to use ArrayStack!(int version)" << endl;
	while (do_command(get_command(), st));
	return 0;
}
