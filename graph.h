/*
 * Graph class header file.
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "linkedlist.h"

enum Color {WHITE, GRAY, BLACK};

class Graph {
	LinkedList *adjList;
	int *distArray;
	Color *colorArray;
	int *parentArray;
	int size;
	int source;
public:
	Graph(int n);
	/* Accessor functions */

	/* Manipulation functions */
	void addEdge(int u, int v);
	void addArc(int u, int v);
	void clearGraph();
	void freeGraph();

	/* Other functions */
	void printGraph();
	void BFS(int s);
	void printSortedGraph();
};

#endif