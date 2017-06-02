/*
 * Graph class implementation.
 */

#include <iostream>
#include <climits>
#include "graph.h"
#include "queue.h"

using namespace std;

const int INF = INT_MAX;
const int NIL = -1;

/* Default constructor. Malloc  */
Graph::Graph(int n){
	int newN = n + 1;
	size = newN;
	source = -1;
	adjList     = (LinkedList *)malloc(sizeof(LinkedList) * newN);
	colorArray  = (Color *)malloc(sizeof(Color) * newN);
	distArray   = (int *)malloc(sizeof(int) * newN);
	parentArray = (int *)malloc(sizeof(int) * newN);
	for (int i = 1; i < size; i++) {
		adjList[i].clear();
	}
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
	for (int i = 1; i <= size; i++) {
		adjList->clear();
	}
}

/* Get size of list. */
void Graph::freeGraph(){
	clearGraph();
	free(adjList);
	free(distArray);
	free(parentArray);
	free(colorArray);
	size = 0;
}

/* Get value of current pointer. */
void Graph::printGraph(){
	for (int i = 1; i <= size; i++) {
		cout << i << ": ";
		adjList[i].printList();
	}
}

void Graph::printSortedGraph(){
	bool found = true;
	int depth = 0;
	cout << "With source at: " << source << endl;
	while (found) {
		cout << "Distance of " << depth << ": ";
		found = false;
		for (int i = 1; i < size; i++) {
			if (distArray[i] == depth) {
				cout << i << " ";
				found = true;
			}
		}
		cout << endl;
		depth++;
	}
	cout << "----------" << endl;
}

/* Execute breath first search on the given graph. */
void Graph::BFS(int s) {
	Queue traversalQueue;
	source = s;
	/* Set defaults*/
	for (int i = 1; i < size; i++) {
		colorArray[i]  = WHITE;
		distArray[i]   = INF;
		parentArray[i] = NIL;
	}
	/* Set source to found and 0 dist. */
	colorArray[source] = GRAY;
	distArray[source]  = 0;

	traversalQueue.push(source);
	while (!traversalQueue.isEmpty()) {
		/* Current node on queue. */
		int parent = traversalQueue.getFront();
		traversalQueue.pop();

		/* Iterate through adj list. */
		adjList[parent].moveFront();
		while (adjList[parent].getCurrent() != -1) {
			int newNode = adjList[parent].getCurrent();
			/* Only work with new nodes. */
			if (colorArray[newNode] == WHITE) {
				colorArray[newNode] = GRAY;
				distArray[newNode] = distArray[parent] + 1;
				parentArray[newNode] = parent;
				traversalQueue.push(newNode);
			}
			adjList[parent].moveNext();
		}
		colorArray[parent] = BLACK;
	}
}

