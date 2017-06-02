/*
 * Stack class implementation.
 */

#include <iostream>
#include <cstddef>
#include "stack.h"

/* Default constructor. Set front and back to NULL and size to 0. */
Stack::Stack(){
	pointer = NULL;
	size = 0;
}

/* Return top value. */
int Stack::peek(){
	return pointer->getValue();
}

/* Delete next node. */
void Stack::pop(){
	if (!isEmpty()) {
		Node *temp = pointer;
		pointer = pointer->getNext();
		size--;
		free(temp);
	}
}

/* Set next node. */
void Stack::push(int newValue) {
	Node *nextNode = (Node *)malloc(sizeof(Node));
	nextNode->setValue(newValue);
	nextNode->setNext(pointer);
	pointer = nextNode;
	size++;
}

/* Return true if empty else false. */
bool Stack::isEmpty(){
	return (size == 0) ? true : false;
}

/* Return size. */
int Stack::getSize(){
	return size;
}