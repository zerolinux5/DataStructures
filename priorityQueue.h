/*
 * Priority Queue class header file.
 */

#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "node.h"

class PriorityQueue {
	Node *top;
	int size;
public:
	PriorityQueue();
	int getTop();
	void pop();
	void push(int newValue);
	bool isEmpty();
	int  getSize();
};

#endif