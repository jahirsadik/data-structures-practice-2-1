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
  int levelNodeCount(int start, int level);
  void printGraph();
  void printLevelsOfVertices(int s);
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

int Graph::levelNodeCount(int start, int l){
  bool *visited = new bool[V];
  int level[V];
  for(int i=0; i<V; i++){
    visited[i] = 0;
    level[i] = INT_MAX;
  }
  queue<int> q;
  q.push(start);
  level[start] = 0;
  visited[start] = true;
  while(!q.empty()){
    start = q.front();
    q.pop();
    for(auto itr: adjList[start]){
      if(!visited[itr]){
        level[itr] = level[start] + 1;
        visited[itr] = true;
        q.push(itr);
      }
    }
  }
  int count = 0;
  for(int i=0; i<V; i++){
    if(level[i] == l) count++;
  }
  return count;
}

void Graph::printLevelsOfVertices(int start){
  bool *visited = new bool[V];
  pair<int, int> level[V];
  for(int i=0; i<V; i++){
    visited[i] = 0;
    level[i] = make_pair(INT_MAX, i);
  }
  queue<int> q;
  q.push(start);
  level[start] = make_pair(0, start);
  visited[start] = true;
  while(!q.empty()){
    start = q.front();
    q.pop();
    for(auto itr: adjList[start]){
      if(!visited[itr]){
        level[itr] = make_pair(level[start].first+1, itr);
        visited[itr] = true;
        q.push(itr);
      }
    }
  }

  sort(level, level+V);

  for(auto i: level) cout << "Element: " << i.second << " level: "
                    << i.first << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    int level = 2;
    //cout << g.levelNodeCount(0, level);
    g.printLevelsOfVertices(3);
    return 0;
}
