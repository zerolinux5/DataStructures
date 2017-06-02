/*
 * Linked List class implementation.
 */

#include <iostream>
#include <cstddef>
#include "linkedList.h"

using namespace std;

/* Default constructor. Set pointers to NULL, and size to 0. */
LinkedList::LinkedList(){
	size = 0;
	current = front = back = NULL;
}

/* Check if list is empty. */
bool LinkedList::isEmpty(){
	return (size == 0) ? true : false;
}

/* Get size of list. */
int LinkedList::getSize(){
	return size;
}

/* Get value of current pointer. */
int LinkedList::getCurrent(){
	int result = -1;
	if (current != NULL) {
		result = current->getValue();
	}
	return result;
}

/* Move pointer to start of list. */
void LinkedList::moveFront(){
	current = front;
}

/* Move pointer to end of list. */
void LinkedList::moveBack(){
	current = back;
}

/* Move pointer to next node. If next would be NULL current 
 * is set to NULL. */
void LinkedList::moveNext(){
	current = current->getNext();
}

/* Move pointer to previous node. If previous would be NULL
 * current is set to NULL. */
void LinkedList::movePrev(){
	current = current->getPrev();
}

/* Delete all nodes. */
void LinkedList::clear(){
	while (!isEmpty()) {
		deleteBack();
	}
}

/* Delete current Node. Special case where list is of size 1 is
 * covered. Set nodes around current to target each other and
 * free current node. */
void LinkedList::deleteCurrent(){
	if (current != NULL) {
		DoubleNode *tempf = current->getPrev();
		DoubleNode *tempb = current->getNext();
		if (getSize() == 1) {
			front = back = NULL;
		} else {
			/* At front so need front to move to second node. */
			if (tempf == NULL) {
				front = tempb;
			} else {
				tempf->setNext(tempb);
			}
			/* At back so need back to move to second to last node. */
			if (tempb == NULL) {
				back = tempf;
			} else {
				tempb->setPrev(tempf);
			}
		}
		free(current);
		current = NULL;
		size--;
	}
}

/* Delete back of list. If we only have 1 node set all pointers
 * to NULL. */
void LinkedList::deleteBack(){
	DoubleNode *temp = back;

	/* When only have a list of 1.
	 * set everything to NULL. */
	if (getSize() == 1) {
		back = front = current = NULL;
	}
	/* Default case set back to previous.
	 * new back points to NULL. */
	else {
		back = back->getPrev();
		back->setNext(NULL);
	}
	free(temp);
	size--;
}

/* Delete front of list. If we only have 1 node set all pointers
 * to NULL. */
void LinkedList::deleteFront(){
	DoubleNode *temp = front;

	/* When only have a list of 1.
	 * set everything to NULL. */
	if (getSize() == 1) {
		back = front = current = NULL;
	}
	/* Default case set back to previous.
	 * new back points to NULL. */
	else {
		front = front->getNext();
		front->setPrev(NULL);
	}
	free(temp);
	size--;
}

void LinkedList::append(int val){
	DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
	newNode->setValue(val);
	newNode->setNext(NULL);
	newNode->setPrev(back);
	if (isEmpty()) {
		front = back = newNode;
	} else {
		back->setNext(newNode);
		back = newNode;
	}
	size++;
}

void LinkedList::prepend(int val){
	DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
	newNode->setValue(val);
	newNode->setNext(front);
	newNode->setPrev(NULL);
	if (isEmpty()) {
		front = back = newNode;
	} else {
		front->setPrev(newNode);
		front = newNode;
	}
	size++;
}

void LinkedList::insertAfter(int val){
	if (current != NULL) {
		DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
		DoubleNode* temp = current->getNext();
		newNode->setValue(val);
		newNode->setNext(current->getNext());
		newNode->setPrev(current);
		current->setNext(newNode);
		/* Watch for case where current points to back. */
		if (temp != NULL) {
			temp->setPrev(newNode);
		} else {
			back = newNode;
		}
		size++;
	}
}

void LinkedList::insertBefore(int val){
	if (current != NULL) {
		DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
		DoubleNode* temp = current->getPrev();
		newNode->setValue(val);
		newNode->setNext(current);
		newNode->setPrev(current->getPrev());
		current->setPrev(newNode);
		/* Watch for case where current points to front. */
		if (temp != NULL) {
			temp->setNext(newNode);
		} else {
			front = newNode;
		}
		size++;
	}
}

void LinkedList::printList(){
	DoubleNode *temp = front;
	while (temp != NULL) {
		cout << temp->getValue() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

