/*
 * Node class implementation.
 */

#include <iostream>
#include <cstddef>
#include "node.h"

/* Default constructor. Set data to 0 and next to NULL. */
Node::Node(){
	data = 0;
	next = NULL;
}

/* Check if node points to another Node. */
bool Node::hasNext(){
	return (next == NULL) ? false : true;
}

/* Return next node. */
Node *Node::getNext(){
	return next;
}

/* Set next node. */
void Node::setNext(Node *nextNode) {
	next = nextNode;
}

/* Get value of data. */
int Node::getValue(){
	return data;
}

/* Set data value. */
void Node::setValue(int newData){
	data = newData;
}
