/*
 * Queue class header file.
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "node.h"

class Queue {
	Node *front;
	Node *back;
	int size;
public:
	Queue();
	int getFront();
	void pop();
	void push(int newValue);
	bool isEmpty();
	int  getSize();
};

#endif