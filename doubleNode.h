/*
 * Double node class header file.
 */

#ifndef __DOUBLE_NODE_H__
#define __DOUBLE_NODE_H__

class DoubleNode {
	DoubleNode *prev;
	DoubleNode *next;
	int data;
public:
	DoubleNode();
	bool hasPrev();
	DoubleNode *getPrev();
	DoubleNode *getNext();
	void setPrev(DoubleNode *nextNode);
	void setNext(DoubleNode *nextNode);
	int getValue();
	void setValue(int newData);
};

#endif