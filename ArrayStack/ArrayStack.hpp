#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H 
#include "../ErrorCode/ErrorCode.hpp"
using namespace std;

template <class Stack_Ele>
class ArrayStack {
public:
	ArrayStack();
	Error_code pop();
	Stack_Ele top();
	Error_code push(Stack_Ele ele);
	bool empty();
	bool full();
private:
	Stack_Ele* stack ;
	int size;
};

#endif
