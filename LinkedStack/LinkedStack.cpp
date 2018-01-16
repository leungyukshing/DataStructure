#include "LinkedStack.hpp"
#include <iostream>
using namespace std;

template <class Stack_entry>
LinkedStack<Stack_entry>::LinkedStack() {
	top_node = NULL;
}

template <class Stack_entry>
bool LinkedStack<Stack_entry>::empty() const {
	return top_node == NULL;
}

template <class Stack_entry>
Error_code LinkedStack<Stack_entry>::push(const Stack_entry &item) {
	if (top_node == NULL) {
		top_node = new Node<Stack_entry>(item);
	}
	else {
		Node<Stack_entry>* p = top_node;
		while (p->next != NULL) {
			p = p->next;
		}
		Node<Stack_entry>* temp = new Node<Stack_entry>(item);
		p->next = temp;
	}
	return Success;
}

template <class Stack_entry>
Error_code LinkedStack<Stack_entry>::pop() {
	if (top_node == NULL) {
		return UnderFlow;
	}
	else if (top_node->next == NULL) {
		delete top_node;
		top_node = NULL;
	}
	else {
		Node<Stack_entry>* p1 = top_node;
		Node<Stack_entry>* p2;
		while (p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		p2->next = NULL;
		delete p1;
		return Success;
	}
}

template <class Stack_entry>
Error_code LinkedStack<Stack_entry>::top(Stack_entry &item) const {
	if (top_node == NULL) {
		item = -1;
		return UnderFlow;
	}
	else if (top_node->next == NULL) {
		item = top_node->entry;
		return Success;
	}
	else {
		Node<Stack_entry>* p1 = top_node;
		Node<Stack_entry>* p2;
		while (p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		//p2->next = NULL;
		item = p1->entry;
		//delete p1;
		return Success;
	}
}

template <class Stack_entry>
LinkedStack<Stack_entry>::~LinkedStack() {
	// clear teh stack
	while (!empty()) {
		pop();
	}
}