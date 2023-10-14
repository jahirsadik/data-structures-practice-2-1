// Link: https://www.geeksforgeeks.org/maximum-edges-can-added-dag-remains-dag/

#include<bits/stdc++.h>
using namespace std;

#define addEdge addDirectedEdge

class Graph{
  int V;
  unordered_set<int> *adjList;
  int numberOfEdges;
  void topologicalSortUtil(int v, bool *visited, stack<int> &stck);
public:
  Graph(int V);
  void addEdge(int src, int dest){
    adjList[src].insert(dest);
    numberOfEdges++;
  };
  vector<int> topologicalSort();
  void maximumEdgeAddition();
};

Graph::Graph(int V){
  this->V = V;
  adjList = new unordered_set<int>[V];
  numberOfEdges = 0;
}

void Graph::topologicalSortUtil(int v, bool*visited, stack<int> &stck){
  visited[v] = true;
  for(auto itr: adjList[v]){
    if(!visited[itr]) topologicalSortUtil(itr, visited, stck);
  }
  stck.push(v);
}

vector<int> Graph::topologicalSort(){
  stack<int> stck;
  bool *visited = new bool[V];
  for(int i=0; i<V; i++) visited[i] = false;

  for(int i=0; i<V; i++){
    if(!visited[i])
      topologicalSortUtil(i, visited, stck);
  }
  vector<int> topologicalSorted;
  while(!stck.empty()){
    int k = stck.top();
    topologicalSorted.push_back(k);
    stck.pop();
  }
  return topologicalSorted;
}

void Graph::maximumEdgeAddition(){
  bool* visited = new bool[V];
  vector<int> topo = topologicalSort();
  int total = 0;

  for (int i = 0; i < (int)topo.size(); i++) printf("%d ", topo[i]);
printf("\n\n");

  for(int i=0; i<(int)topo.size(); i++){
    int t = topo[i];

    for(auto itr: adjList[t]){
      visited[itr] = true;
    }

    for(int j=i+1; j< (int)topo.size(); j++){
      if(!visited[topo[j]]){
          cout << t << "-" << topo[j] << ". ";
          total++;
      }
      visited[topo[j]] = false;
    }
  }

  cout << "\n\t Total Swaps: " << total << endl;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.maximumEdgeAddition();
    return 0;
}
