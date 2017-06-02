/*
 * Stack class header file.
 */

#ifndef __STACK_H_
#define __STACK_H_

#include "node.h"

class Stack {
	Node *pointer;
	int size;
public:
	Stack();
	int peek();
	void pop();
	void push(int newValue);
	bool isEmpty();
	int  getSize();
};

#endif