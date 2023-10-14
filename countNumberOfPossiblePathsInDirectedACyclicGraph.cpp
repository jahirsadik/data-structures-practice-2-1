/*
LINK: https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
Approach:
The problem can be solved using backtracking, that says
take a path and start walking on it and check if it leads
us to the destination vertex then count the path and backtrack
to take another path. If the path doesn’t lead to the destination
vertex, discard the path. This type of graph traversal is called
Backtracking.

Algorithm:

Create a recursive function that takes index of node of a graph
and the destination index. Keep a global or a static variable count
 to store the count.
If the current nodes is the destination increase the count.
Else for all the adjacent nodes, i.e. nodes that are accessible from
the current node, call the recursive function with the index of adjacent
node and the destination.
Print the Count.

Complexity Analysis:

Time Complexity: O(N!).
If the graph is complete then there can be around N! recursive calls,
so the time Complexity is O(N!)
Space Complexity: O(1).
Since no extra space is required.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adjList;
  void countPathsUtil(int, int, int&);
public:
  Graph(int V);
  void addDirectedEdge(int src, int dest);
  void printGraph();
  int countPaths(int s, int v);

};

Graph::Graph(int V){
  this->V = V;
  adjList = new unordered_set<int>[V];
}


void Graph::addDirectedEdge(int v, int w){
    adjList[v].insert(w);
}

void Graph::printGraph(){
  for(int i = 0; i < V; i++){
    unordered_set<int> uS = adjList[i];
    cout << endl << "Adjacency list of vertex "
          << i << endl;
    for(auto itr: uS) cout << itr << " ";
    cout << endl;
  }
}

void Graph::countPathsUtil(int u, int d, int& pathCount){
  if(u==d) pathCount++;
  else{
    for(auto itr: adjList[u]){
      countPathsUtil(itr, d, pathCount);
    }
  }
}


int Graph::countPaths(int s, int d){
  int pathCount = 0;
  countPathsUtil(s, d, pathCount);
  return pathCount;
}

int main()
{

    Graph g(5);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(0, 3);
    g.addDirectedEdge(1, 3);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(1, 4);
    g.addDirectedEdge(2, 4);

    int s = 0, d = 3;
    cout << g.countPaths(s, d);

    return 0;
}
