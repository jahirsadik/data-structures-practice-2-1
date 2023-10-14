//      https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
//      read the link for description and algorithm explanations



#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adjList;
  bool isDirected;

public:
  Graph(int V);
  Graph(int V, bool b);
  void addEdge(int v, int w);
  void addDirectedEdge(int src, int dest);
  void DFSTraverse(int v, bool *visited);
  int findMotherVertex();
};

Graph::Graph(int V){
  this->V = V;
  adjList = new unordered_set<int>[V];
  isDirected = false;
}

Graph::Graph(int V, bool b){
  isDirected = b;
  this->V = V;
  adjList = new unordered_set<int>[V];
}

void Graph::addEdge(int v, int w){
  if(!isDirected){
    adjList[v].insert(w);
    adjList[w].insert(v);
  }
  else{
    printf("Can't add undirected edge to directed graph\n");
  }
}

void Graph::addDirectedEdge(int v, int w){
  if(!isDirected){
    printf("Can't add directed edge to undirected graph\n");
  }
  else{
    adjList[v].insert(w);
  }
}



void Graph::DFSTraverse(int v, bool *visited){
  visited[v] = true;
  for(auto itr = adjList[v].begin(); itr!=adjList[v].end(); ++itr){
    if(!visited[*itr]) DFSTraverse(*itr, visited);
  }
}

int Graph::findMotherVertex(){
  bool *visited = new bool[V];
  for(int i = 0; i<V; i++) visited[i] = false;
  int v = 0;
  for(int i=0; i<V; i++){
    if(!visited[i]){
      DFSTraverse(i, visited);
      v = i;
    }
  }

  for(int i = 0; i<V; i++) visited[i] = false;
  DFSTraverse(v, visited);
  for(int i=0; i<V; i++){
    if(!visited[i]) return -1;
  }
  return v;
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(7, true);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 3);
    g.addDirectedEdge(4, 1);
    g.addDirectedEdge(6, 4);
    g.addDirectedEdge(5, 6);
    g.addDirectedEdge(5, 2);
    g.addDirectedEdge(6, 0);


    cout << "A mother vertex is " << g.findMotherVertex() << endl;

    return 0;

}
