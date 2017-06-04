/*
 * Double Node class implementation.
 */

#include <iostream>
#include <cstddef>
#include "doubleNode.h"

/* Default constructor. Set data to 0 and next to NULL. */
DoubleNode::DoubleNode(){
	data = 0;
	next = prev = NULL;
}

/* Check if node points to another Node. */
bool DoubleNode::hasPrev(){
	return (prev == NULL) ? false : true;
}

/* Check if node points to another Node. */
bool DoubleNode::hasNext(){
	return (next == NULL) ? false : true;
}

/* Return previous node. */
DoubleNode *DoubleNode::getPrev(){
	return prev;
}

/* Return next node. */
DoubleNode *DoubleNode::getNext(){
	return next;
}

/* Set previous node. */
void DoubleNode::setPrev(DoubleNode *nextNode) {
	prev = nextNode;
}


/* Set next node. */
void DoubleNode::setNext(DoubleNode *nextNode) {
	next = nextNode;
}

/* Get value of data. */
int DoubleNode::getValue(){
	return data;
}

/* Set data value. */
void DoubleNode::setValue(int newData){
	data = newData;
}