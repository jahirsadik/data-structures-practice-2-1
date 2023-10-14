//
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
  void BFS(int s);
  void DFS();
  void DFS(int v);
  void DFSUtil(int v, bool *visited);
  void printGraph();

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

void Graph::BFS(int v){
  bool *visited = new bool[V];
  for(auto i = 0; i<V; i++) visited[i] = false;

  queue<int> q;
  visited[v] = true;
  q.push(v);

  while(!q.empty()){
    v = q.front();
    cout << v << " ";
    q.pop();
    for(auto itr = adjList[v].begin(); itr!=adjList[v].end(); ++itr){
      if(!visited[*itr]){
        visited[*itr] = true;
        q.push(*itr);
      }
    }
  }
}

void Graph::DFSUtil(int v, bool *visited){
  visited[v] = true;
  cout << v << " ";
  for(auto itr = adjList[v].begin(); itr!=adjList[v].end(); ++itr){
    if(!visited[*itr]) DFSUtil(*itr, visited);
  }
}

void Graph::DFS(){
  bool *visited = new bool[V];
  for(int i=0; i<V; i++) visited[i] = false;
  for(int i=0; i<V; i++){    // loop to make use dfs works on disconnected graphs
    if(!visited[i]) DFSUtil(i, visited);
  }
}


// function for DFS on a specific element of the graph
// implemented using stack
// have to put in a loop in case of disconnected graph

void Graph::DFS(int v){
  bool *visited = new bool[V];
  for(int i=0; i<V; i++) visited[i] = false;
  stack<int> stck;
  stck.push(v);
  while(!stck.empty()){
    v = stck.top();
    stck.pop();
    if(!visited[v]){
      cout << v << " ";
      visited[v] = true;
    }
    for(auto itr: adjList[v]){
      if(!visited[itr]){
        stck.push(itr);
      }
    }
  }
}

int main()
{
    int xjhg;
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(3,4);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;
    g.BFS(0);
    cout << endl;
    g.BFS(1);
    cout << endl;
    g.BFS(3);
    cout << endl;
    cout << "Following is Depth First Traversal: ";
    g.DFS(3);
    return 0;
}
