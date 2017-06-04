/*
 * Test file for queue class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "priorityQueue.h"

using namespace std;

const int minVal    = -10000;
const int maxVal    = 10000;
const string ERROR  = "Error found in Priority Queue data structure, function: ";

int main()
{
	PriorityQueue firstQueue;
	PriorityQueue secondQueue;

	/* Verify both queues are set to size 0. */
	if (firstQueue.getSize() != 0) {
		cout << ERROR << "constructor" << endl;
	}
	if (secondQueue.getSize() != 0) {
		cout << ERROR << "constructor" << endl;
	}

	/* Verify adding to queue 1. */
	for (int i = minVal; i < maxVal; i++) {
		firstQueue.push(i);
	}

	if (firstQueue.getSize() != (abs(minVal) + maxVal)) {
		cout << ERROR << "getSize" << endl;
	}

	/* Get value from first queue and assign to second queue.
	 * Pop first queue.*/
	for (int i = minVal; i < maxVal; i++) {
		int temp = firstQueue.getTop();
		firstQueue.pop();
		if (temp != i) {
			cout << ERROR << "pop" << endl;
		}
		secondQueue.push(temp);
	}

	/* Pop second queue. */
	for (int i = minVal; i < maxVal; i++) {
		int temp = secondQueue.getTop();
		secondQueue.pop();
		if (temp != i) {
			cout << ERROR << "pop" << endl;
		}
	}

	/* Verify second queue is empty now. */
	if (secondQueue.getSize() != 0 && !secondQueue.isEmpty()) {
		cout << ERROR << "getSize" << endl;
	}

	return 0;
}