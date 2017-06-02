/*
 * Graph class implementation.
 */

#include <iostream>
#include "graph.h"

using namespace std;

/* Default constructor. Malloc  */
Graph::Graph(int n){
	size = n;
	adjList = (LinkedList *)malloc(sizeof(LinkedList) * n);
}

/* Check if list is empty. */
void Graph::addEdge(int u, int v){
	addArc(u, v);
	addArc(v, u);
}

/* Get size of list. */
void Graph::addArc(int u, int v){
	if (!adjList[u].findVal(v)) {
		adjList[u].append(v);
	}
}

/* Get size of list. */
void Graph::clearGraph(){
	for (int i = 0; i < size; i++) {
		adjList->clear();
	}
}

/* Get size of list. */
void Graph::freeGraph(){
	clearGraph();
	free(adjList);
	size = 0;
}

/* Get value of current pointer. */
void Graph::printGraph(){
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		adjList[i].printList();
	}
}

