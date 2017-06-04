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
	int *discoveredArray;
	int *foundArray;
	Color *colorArray;
	int *parentArray;
	int size;
	int source;
	int time;
	void DFSVisit(int node);
public:
	Graph(int n);
	/* Accessor functions */

	/* Manipulation functions */
	void addEdge(int u, int v);
	void addArc(int u, int v);
	void removeArc(int u, int v);
	void removeEdge(int u, int v);
	void clearGraph();
	void freeGraph();

	/* Other functions */
	void printGraph();
	void BFS(int s);
	void DFS();
	void DFSSource(int s);
	void printSortedBFSGraph();
	void printSortedDFSGraph();
};

#endif