// Link: https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adjList;
  bool isCyclicUtil(int v, bool *visited, int parent);
public:
  Graph(int V);
  Graph(int V, bool b);
  void addEdge(int v, int w);
  void printGraph();
  bool isCyclic();
};

Graph::Graph(int V){
  this->V = V;
  adjList = new unordered_set<int>[V];
}

void Graph::addEdge(int v, int w){
    adjList[v].insert(w);
    adjList[w].insert(v);
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

bool Graph::isCyclicUtil(int v, bool *visited, int parent){
  visited[v] = true;
  for(auto itr: adjList[v]){
    if(!visited[itr]){
      if(isCyclicUtil(itr, visited, v)){
        return true;
      }
    }
    else if(itr != parent) return true;
  }
  return false;
}

bool Graph::isCyclic(){
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
      visited[i] = false;

  for(int i=0; i<V; i++){
    if(!visited[i]){
        if(isCyclicUtil(i, visited, -1))
          return true;
    }
  }

  return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    return 0;
}
