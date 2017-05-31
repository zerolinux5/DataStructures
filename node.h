/*
 * Node class header file.
 */

#ifndef __NODE_H__
#define __NODE_H__

class Node {
protected:
	int data;
	Node *next;
public:
	Node();
	bool hasNext();
	Node *getNext();
	void setNext(Node *nextNode);
	int getValue();
	void setValue(int newData);
};

#endif