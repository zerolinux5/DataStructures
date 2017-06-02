/*
 * Test file for Linked List class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "graph.h"

using namespace std;

const int SIZE = 10;
const string ERROR  = "Error found in Linked List data structure, function: ";

int main()
{
	Graph graph1(SIZE);

	/* Add values to 1. */
	for (int i = 0; i < SIZE; i++) {
		graph1.addArc(1, i);
	}

	/* Print graph values. */
	graph1.printGraph();
	/* Clear adjacency list. */
	graph1.clearGraph();

	/* Add values to graph. */
	for (int i = 0; i < SIZE; i++) {
		graph1.addEdge(1, i);
	}

	/* Expect another graph with more values. */
	graph1.printGraph();

	graph1.freeGraph();
	/* Expect no print out. */
	graph1.printGraph();

	return 0;
}