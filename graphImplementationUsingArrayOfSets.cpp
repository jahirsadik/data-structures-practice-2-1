/*
                  Implementation using adjacency lists
A set is different from a vector in two ways: it stores
elements in a sorted way, and duplicate elements are not allowed.
Therefore, this approach cannot be used for graphs containing parallel
edges. Since sets are internally implemented as binary search trees,
an edge between two vertices can be searched in O(logV) time, where
V is the number of vertices in the graph.

Pros: Queries like whether there is an edge from vertex u to vertex
v can be done in O(log V).

Cons:

Adding an edge takes O(log V), as opposed to O(1) in vector implementation.
Graphs containing parallel edge(s) cannot be implemented through this method.

*/

/*
#include<bits/stdc++.h>
using namespace std;

struct Graph{
  int V;
  set<int, greater<int>> *adjList;
};

Graph* createGraph(int V){
  Graph* graph = new Graph();
  graph->V = V;
  graph->adjList = new set<int , greater<int>>[V]; // create an array of sets
                                                   // sorted in decending order
  return graph;
}

void addEdge(Graph* graph, int src, int dest){
  graph->adjList[src].insert(dest);
  graph->adjList[dest].insert(src);
}

void printGraph(Graph* graph){
  for(int i=0; i<graph->V; ++i){
    set<int, greater<int>> lst = graph->adjList[i];
    cout << endl << "Adjacency list of vertex "
               << i << endl;
    for(auto k: lst) cout << k << " ";
    cout << endl;
  }
}

void searchEdge(Graph* graph, int src, int dest){
  auto itr = graph->adjList[src].find(dest);
  if (itr == graph->adjList[src].end())
      cout << endl << "Edge from " << src
           << " to " << dest << " not found."
           << endl;
  else
      cout << endl << "Edge from " << src
           << " to " << dest << " found."
           << endl;
}

int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
    return 0;
}
*/

/*

Further Optimization of Edge Search Operation using
unordered_set (or hashing):
The edge search operation can be further optimized to
O(1) using unordered_set which uses hashing internally


Pros:
Queries like whether there is an edge from vertex u to vertex
v can be done in O(1).
Adding an edge takes O(1).

Cons:
Graphs containing parallel edge(s) cannot be implemented through this method.
Edges are not stored in any order.

*/


#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int V;
	unordered_set<int>* adjList;
};

Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->adjList = new unordered_set<int>[V];

	return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
	graph->adjList[src].insert(dest);
	graph->adjList[dest].insert(src);
}

void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->V; ++i) {
		unordered_set<int> lst = graph->adjList[i];
		cout << endl << "Adjacency list of vertex "
			<< i << endl;

		for (auto itr = lst.begin(); itr != lst.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}
}

void searchEdge(Graph* graph, int src, int dest)
{
	auto itr = graph->adjList[src].find(dest);
	if (itr == graph->adjList[src].end())
		cout << endl << "Edge from " << src
			<< " to " << dest << " not found."
			<< endl;
	else
		cout << endl << "Edge from " << src
			<< " to " << dest << " found."
			<< endl;
}

int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	printGraph(graph);
	searchEdge(graph, 2, 1);
	searchEdge(graph, 0, 3);

	return 0;
}
