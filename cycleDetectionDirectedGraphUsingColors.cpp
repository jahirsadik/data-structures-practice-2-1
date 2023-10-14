// Link: https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/

#include<bits/stdc++.h>
using namespace std;

enum Color{WHITE, GRAY, BLACK};

class Graph{
  int V;
  unordered_set<int> *adjList;
  bool isCyclicUtil(int i, int color[]);
public:
  Graph(int V);
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

bool Graph::isCyclicUtil(int u, int color[]){
  color[u] = GRAY;
  for(auto itr: adjList[u]){
    if(color[itr]==GRAY) return true;
    if(color[itr] == WHITE){
      if(isCyclicUtil(itr, color))
        return true;
    }
  }
  color[u] = BLACK;
  return false;
}

bool Graph::isCyclic(){
  int *color = new int[V];
  for(int i=0; i<V; i++) color[i] = WHITE;

  for(int i=0; i<V; i++){
    if(color[i]==WHITE){
      if(isCyclicUtil(i, color))
        return true;
    }
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
