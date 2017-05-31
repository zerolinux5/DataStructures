/*
 * Double node class header file.
 */

#ifndef __DOUBLE_NODE_H__
#define __DOUBLE_NODE_H__

#include "node.h"

class DoubleNode: public Node {
	DoubleNode *prev;
	DoubleNode *next;
public:
	DoubleNode();
	bool hasPrev();
	DoubleNode *getPrev();
	DoubleNode *getNext();
	void setPrev(DoubleNode *nextNode);
	void setNext(DoubleNode *nextNode);
};

#endif