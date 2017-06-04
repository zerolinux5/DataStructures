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

/* Default constructor.  */
Graph::Graph(int n){
	int newN = n + 1;
	size = newN;
	source = -1;
	adjList         = (LinkedList *)malloc(sizeof(LinkedList) * newN);
	colorArray      = (Color *)malloc(sizeof(Color) * newN);
	distArray       = (int *)malloc(sizeof(int) * newN);
	discoveredArray = (int *)malloc(sizeof(int) * newN);
	foundArray      = (int *)malloc(sizeof(int) * newN);
	parentArray     = (int *)malloc(sizeof(int) * newN);
	for (int i = 1; i < size; i++) {
		adjList[i].clear();
	}
}

/* Add edge to both u and v adjacency list */
void Graph::addEdge(int u, int v){
	addArc(u, v);
	addArc(v, u);
}

/* Add arc to u adjacency list */
void Graph::addArc(int u, int v){
	if (!adjList[u].findVal(v)) {
		adjList[u].append(v);
	}
}

/* Remove edge from both u and v adjacency list */
void Graph::removeEdge(int u, int v){
	removeArc(u, v);
	removeArc(v, u);
}

/* Remove arc from u adjacency list */
void Graph::removeArc(int u, int v){
	adjList[u].deleteVal(v);
}

/* Clear adjacency list of graph. */
void Graph::clearGraph(){
	for (int i = 1; i <= size; i++) {
		adjList->clear();
	}
}

/* Free all mallocs. */
void Graph::freeGraph(){
	clearGraph();
	free(adjList);
	free(distArray);
	free(discoveredArray);
	free(foundArray);
	free(parentArray);
	free(colorArray);
	size = 0;
}

/* Print graph adjacency list. */
void Graph::printGraph(){
	for (int i = 1; i <= size; i++) {
		cout << i << ": ";
		adjList[i].printList();
	}
}

/* Print nodes based on distance to source. */
void Graph::printSortedBFSGraph(){
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

/* Print nodes based on found time. */
void Graph::printSortedDFSGraph(){
	LinkedList printList;
	for (int i = 1; i < size; i++) {
		printList.append(i);
	}
	while (!printList.isEmpty()) {
		printList.moveFront();
		int sourceNode = printList.getCurrent();
		if (sourceNode == -1) {
			break;
		}
		Queue traversalQueue;
		cout << "Start of tree" << endl;
		traversalQueue.push(sourceNode);
		while (!traversalQueue.isEmpty()) {
			int newNode = traversalQueue.getFront();
			printList.deleteVal(newNode);
			cout << newNode << " ";
			traversalQueue.pop();
			for (int i = 1; i < size; i++) {
				if (parentArray[i] == newNode) {
					traversalQueue.push(i);
				}
			}
		}
		cout << endl << "End of tree" << endl;
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

/* Execute depth first search on the given graph. */
void Graph::DFS() {
	time = 0;
	/* Set defaults*/
	for (int i = 1; i < size; i++) {
		colorArray[i]  = WHITE;
		parentArray[i] = NIL;
	}
	/* Set source to found and 0 dist. */
	for (int i = 1; i < size; i++) {
		if (colorArray[i] == WHITE) {
			DFSVisit(i);
		}
	}
}

/* Execute depth first search on the given graph using only the
 * source node. */
void Graph::DFSSource(int s) {
	time = 0;
	/* Set defaults*/
	for (int i = 1; i < size; i++) {
		colorArray[i]  = WHITE;
		parentArray[i] = NIL;
	}
	/* Set source to found and 0 dist. */
	DFSVisit(s);
}

/* Recursive logic for each node in DFS. */
void Graph::DFSVisit(int node) {
	time++;
	discoveredArray[node] = time;
	colorArray[node] = GRAY;
	adjList[node].moveFront();
	while (adjList[node].getCurrent() != -1) {
		int newNode = adjList[node].getCurrent();
		if (colorArray[newNode] == WHITE) {
			parentArray[newNode] = node;
			DFSVisit(newNode);
		}
		adjList[node].moveNext();
	}
	colorArray[node] = BLACK;
	time++;
	foundArray[node] = time;
}

