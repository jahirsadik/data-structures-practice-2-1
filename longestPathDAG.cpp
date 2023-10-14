// Link: https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

/*        Algorithm
Following is complete algorithm for finding longest distances.
1) Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite.
2) Create a toplogical order of all vertices.
3) Do following for every vertex u in topological order.
………..Do following for every adjacent vertex v of u
………………if (dist[v] < dist[u] + weight(u, v))
………………………dist[v] = dist[u] + weight(u, v)
*/

#include<bits/stdc++.h>
using namespace std;

#define NOSHIM -99999

class AdjListNode{
  int dest, weight;
public:
  AdjListNode(int dest, int weight){
    this->dest = dest;
    this->weight = weight;
  }
  int getV(){return dest;}
  int getWeight(){ return weight;}
};

class Graph{
  int V;
  list<AdjListNode> *adj;
  void topologicalSortUtil(int v,
              bool visited[], stack<int> &stck);
public:
  Graph(int V);
  ~Graph();
  void addEdge(int u, int v, int weight);
  void longestPath(int start);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<AdjListNode>[V];
}

Graph::~Graph(){
  delete [] adj;
}

void Graph::addEdge(int u, int v, int weight){
  AdjListNode node(v, weight);
  adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& stck)
{
    visited[v] = true;
    for (auto i: adj[v]) {
        AdjListNode node = i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, stck);
    }
    stck.push(v);
}

void Graph::longestPath(int start){
  stack<int> stck;
  int dist[V];
  bool *visited = new bool[V];
  for(int i=0; i<V; i++){
    visited[i] = false;
    dist[i] = NOSHIM;
  }
  dist[start] = 0;
  for(int i=0; i<V; i++){
    if(!visited[i]) topologicalSortUtil(i, visited, stck);
  }

  while(!stck.empty()){
    int u = stck.top();
    stck.pop();
    if(dist[u]!= NOSHIM){
      for(auto i: adj[u]){
        if(dist[i.getV()] < dist[u] + i.getWeight())
              dist[i.getV()] = dist[u] + i.getWeight();
      }
    }
  }

  for(int i=0; i<V; i++){
    (dist[i] == NOSHIM) ? cout << "INF " : cout << dist[i] << " ";
  }
  cout << endl;
  delete [] visited;
}

int main()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPath(s);

    return 0;
}
