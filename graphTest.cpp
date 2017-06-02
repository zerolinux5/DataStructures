/*
 * Test file for Linked List class.
 * test all functions. Verify works as expected.
 */

#include <iostream>
#include "graph.h"

using namespace std;

const int SIZE = 10;
const int SIZE2 = 6;
const string ERROR  = "Error found in Linked List data structure, function: ";

int main()
{
	Graph graph1(SIZE);
	Graph graph2(SIZE2);

	/* Add values to 1. */
	for (int i = 1; i <= SIZE; i++) {
		graph1.addArc(1, i);
	}

	/* Print graph values. */
	graph1.printGraph();
	/* Clear adjacency list. */
	graph1.clearGraph();

	/* Add values to graph. */
	graph2.addEdge(1, 2);
	graph2.addEdge(1, 3);
	graph2.addEdge(2, 4);
	graph2.addEdge(2, 5);
	graph2.addEdge(2, 6);
	graph2.addEdge(3, 4);
	graph2.addEdge(4, 5);
	graph2.addEdge(5, 6);

	/* Execute BFS on multiple sources to verify algorithm works. */
	graph2.BFS(1);
	graph2.printSortedGraph();

	graph2.BFS(5);
	graph2.printSortedGraph();

	graph2.BFS(6);
	graph2.printSortedGraph();

	/* Delete Edges and Arcs and execute BFS again. */
	graph2.removeEdge(2, 6);
	graph2.removeEdge(5, 2);

	graph2.BFS(6);
	graph2.printSortedGraph();

	graph1.freeGraph();
	graph2.freeGraph();
	/* Expect no print out. */
	graph1.printGraph();
	graph2.printGraph();

	return 0;
}