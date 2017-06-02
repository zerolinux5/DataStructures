/*
 * Test file for stack class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "stack.h"

using namespace std;

const int minVal    = -10000;
const int maxVal    = 10000;
const string ERROR  = "Error found in Node data structure, function: ";

int main()
{
	Stack firstStack;
	Stack secondStack;

	/* Verify both queues are set to size 0. */
	if (firstStack.getSize() != 0) {
		cout << ERROR << "constructor" << endl;
	}
	if (secondStack.getSize() != 0) {
		cout << ERROR << "constructor" << endl;
	}

	/* Verify adding to stack 1. */
	for (int i = minVal; i < maxVal; i++) {
		firstStack.push(i);
	}

	if (firstStack.getSize() != (abs(minVal) + maxVal)) {
		cout << ERROR << "getSize" << endl;
	}

	/* Get value from first stack and assign to second stack.
	 * Pop first stack.*/
	for (int i = maxVal - 1; i >= minVal; i--) {
		int temp = firstStack.peek();
		firstStack.pop();
		if (temp != i) {
			cout << ERROR << "pop" << endl;
		}
		secondStack.push(temp);
	}

	/* Pop second stack. */
	for (int i = minVal; i < maxVal; i++) {
		int temp = secondStack.peek();
		secondStack.pop();
		if (temp != i) {
			cout << ERROR << "pop" << endl;
		}
	}

	/* Verify second stack is empty now. */
	if (secondStack.getSize() != 0 && !secondStack.isEmpty()) {
		cout << ERROR << "getSize" << endl;
	}

	return 0;
}