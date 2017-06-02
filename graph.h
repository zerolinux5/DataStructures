/*
 * Graph class header file.
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "linkedlist.h"

class Graph {
	LinkedList *adjList;
	int size;
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
};

#endif