/*
 * Test file for double node class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "doubleNode.h"

using namespace std;

const int minVal    = -10000;
const int maxVal    = 10000;
const int firstVal  = 10;
const int secondVal = 20;
const string ERROR  = "Error found in Node data structure, function: ";

/* Test Node Data Structure. */
int main()
{
  DoubleNode firstNode;
  DoubleNode secondNode;

  DoubleNode* nodePointer;

  /* Verify set value and get value work. */
  for (int i = minVal; i <= maxVal; i++) {
  	firstNode.setValue(i);

  	if (firstNode.getValue() != i) {
  		cout << ERROR << "Set/Get value" << endl;
  	}
  }

  /* Verify pointer */
  if (firstNode.hasPrev()) {
  	cout << ERROR << "hasPrev" << endl;
  }
  if (secondNode.hasPrev()) {
  	cout << ERROR << "hasPrev" << endl;
  }
  /* Set nodes to point to eachother. */
  firstNode.setPrev(&secondNode);
  secondNode.setPrev(&firstNode);
  nodePointer = &firstNode;

  /* Set data for assertion. */
  firstNode.setValue(firstVal);
  secondNode.setValue(secondVal);

  /* Iterate through and verify values are expected. */
  for (int i = 0; i <= maxVal; i++) {
  	int assertVal;
  	/* Even numbers we expect to be at first node */
  	if (i % 2 == 0) {
  		assertVal = firstVal;
  	} else {
  		assertVal = secondVal;
  	}

  	if (nodePointer->getValue() != assertVal) {
  		cout << ERROR << "getPrev" << endl;
      break;
  	}
  	nodePointer = nodePointer->getPrev();
  }

  /* Verify set Next to zero. */
  firstNode.setPrev(NULL);
  secondNode.setPrev(NULL);


  if (firstNode.hasPrev()) {
  	cout << ERROR << "hasPrev" << endl;
  }
  if (secondNode.hasPrev()) {
  	cout << ERROR << "hasPrev" << endl;
  }

    /* Set data for assertion. */
  firstNode.setNext(&secondNode);
  secondNode.setNext(&firstNode);
  nodePointer = &firstNode;

  /* Iterate through and verify values are expected. */
  for (int i = 0; i <= maxVal; i++) {
    int assertVal;
    /* Even numbers we expect to be at first node */
    if (i % 2 == 0) {
      assertVal = firstVal;
    } else {
      assertVal = secondVal;
    }

    if (nodePointer->getValue() != assertVal) {
      cout << ERROR << "getNext" << endl;
      break;
    }
    nodePointer = nodePointer->getNext();
  }

  /* Verify set Next to zero. */
  firstNode.setNext(NULL);
  secondNode.setNext(NULL);


  if (firstNode.hasNext()) {
    cout << ERROR << "hasNext" << endl;
  }
  if (secondNode.hasNext()) {
    cout << ERROR << "hasNext" << endl;
  }

  return 0;
}
