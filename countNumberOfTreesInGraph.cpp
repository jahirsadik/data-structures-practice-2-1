// Counts the number of separate trees in the graph
// Link: https://www.geeksforgeeks.org/count-number-trees-forest/
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adjList;
  bool isDirected;
  void DFSUtil(int s, vector<bool> &visited);
public:
  Graph(int V);
  Graph(int V, bool b);
  void addEdge(int v, int w);
  void addDirectedEdge(int src, int dest);
  void printGraph();
  int numberOfSeparateTrees();
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

void Graph::printGraph(){
  for(int i = 0; i < V; i++){
    unordered_set<int> uS = adjList[i];
    cout << endl << "Adjacency list of vertex "
          << i << endl;
    for(auto itr: uS) cout << itr << " ";
    cout << endl;
  }
}

void Graph::DFSUtil(int s, vector<bool> &visited){
  visited[s] = true;
  for(auto itr: adjList[s]){
    if(!visited[itr]) DFSUtil(itr, visited);
  }
}

int Graph::numberOfSeparateTrees(){
  vector<bool> visited(V, false);
  int res = 0;
  for(int i = 0; i<V; i++){
    if(!visited[i]){
      DFSUtil(i, visited);
      res++;
    }
  }
  return res;
}

int main()
{
	int V = 5;
  Graph g(V);
	g.addEdge( 0, 1);
	g.addEdge( 0, 2);
	g.addEdge( 3, 4);
	cout << g.numberOfSeparateTrees();
	return 0;
}
