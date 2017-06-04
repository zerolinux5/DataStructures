/*
 * Priority Queue class implementation.
 */

#include <iostream>
#include <cstddef>
#include "priorityQueue.h"

/* Default constructor. Set front and back to NULL and size to 0. */
PriorityQueue::PriorityQueue(){
	top = NULL;
	size = 0;
}

/* Return top value. */
int PriorityQueue::getTop(){
	return (top == NULL) ? -1 : top->getValue();
}

/* Delete top node. */
void PriorityQueue::pop(){
	if (!isEmpty()) {
		Node *temp = top;
		top = top->getNext();
		size--;
		free(temp);
	}
}

/* Set next node. */
void PriorityQueue::push(int newValue) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->setValue(newValue);
	newNode->setNext(NULL);
	if (isEmpty()) {
		top = newNode;
	} else {
		Node *tempNode = top;
		while (tempNode != NULL) {
			Node *nextNode = tempNode->getNext();
			/* Middle case. */
			if (nextNode != NULL) {
				bool lessCurrent = (newValue > tempNode->getValue());
				bool greaterNext = (newValue <= nextNode->getValue());
				if (lessCurrent && greaterNext) {
					newNode->setNext(nextNode);
					tempNode->setNext(newNode);
					break;
				}
			} else {
				/* Start of queue. */
				if (newValue <= tempNode->getValue()) {
					newNode->setNext(tempNode);
					top = newNode;
					break;
				/* End of queue. */
				} else {
					tempNode->setNext(newNode);
					break;
				}
			}
			tempNode = tempNode->getNext();
		}
	}
	size++;
}

/* Return true if empty else false. */
bool PriorityQueue::isEmpty(){
	return (size == 0) ? true : false;
}

/* Return size. */
int PriorityQueue::getSize(){
	return size;
}