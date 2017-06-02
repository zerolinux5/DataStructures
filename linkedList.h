/*
 * Linked List class header file.
 */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "doubleNode.h"

class LinkedList {
	DoubleNode *current;
	DoubleNode *back;
	DoubleNode *front;
	int size;
public:
	LinkedList();
	/* Accessor functions */
	bool isEmpty();
	bool findVal(int val);
	int getSize();
	int getCurrent();
	void moveFront();
	void moveBack();
	void moveNext();
	void movePrev();

	/* Manipulation functions */
	void clear();
	void deleteCurrent();
	void deleteBack();
	void deleteFront();
	void append(int val);
	void prepend(int val);
	void insertAfter(int val);
	void insertBefore(int val);

	/* Other functions */
	void printList();
};

#endif