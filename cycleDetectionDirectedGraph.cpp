// Link: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adjList;
  bool isCyclicUtil(int i, bool* visited, bool *recStack);
public:
  Graph(int V);
  Graph(int V, bool b);
  void addDirectedEdge(int src, int dest);
  void printGraph();
  bool isCyclic();
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

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack){
  if(!visited[v]){
    visited[v] = true;
    recStack[v] = true;
    for(auto itr: adjList[v]){
      if(!visited[itr]){
        if(isCyclicUtil(itr, visited, recStack)){
          return true;
        }
      }
      else if(recStack[itr])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool Graph::isCyclic(){
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  for(int i=0; i<V; i++){
    visited[i] = false;
    recStack[i] = false;
  }
  for(int i = 0; i<V; i++){
    if(isCyclicUtil(i, visited, recStack))
      return true;
  }
  return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(2, 0);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3,3);

    if(g.isCyclic())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
