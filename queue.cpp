/*
 * Queue class implementation.
 */

#include <iostream>
#include <cstddef>
#include "queue.h"

/* Default constructor. Set front and back to NULL and size to 0. */
Queue::Queue(){
	front = back = NULL;
	size = 0;
}

/* Return front value. */
int Queue::getFront(){
	return front->getValue();
}

/* Return next node. */
void Queue::pop(){
	if (!isEmpty()) {
		Node *temp = front;
		front = front->getNext();
		size--;
		free(temp);
	}
}

/* Set next node. */
void Queue::push(int newValue) {
	Node *nextNode = (Node *)malloc(sizeof(Node *));
	nextNode->setValue(newValue);
	nextNode->setNext(NULL);
	if (isEmpty()) {
		front = back = nextNode;
	} else {
		back->setNext(nextNode);
		back = nextNode;
	}
	size++;
}

/* Return true if empty else false. */
bool Queue::isEmpty(){
	return (size == 0) ? true : false;
}

/* Return size. */
int Queue::getSize(){
	return size;
}