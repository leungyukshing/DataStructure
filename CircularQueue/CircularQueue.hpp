#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include "../ErrorCode/ErrorCode.hpp"

#define MAXQUEUE 10
//typedef double Queue_entry;
template <class Queue_entry>
class CircularQueue {
public:
	CircularQueue();
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;
protected:
	int count;
	int front, rear;
	Queue_entry entry[MAXQUEUE];
};
#endif
