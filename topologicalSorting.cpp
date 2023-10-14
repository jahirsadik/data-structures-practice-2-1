#include <bits/stdc++.h>
using namespace std;

#define addEdge addDirectedEdge

class Graph
{
  int V;
  unordered_set<int> *adjList;
  int numberOfEdges;
  void topologicalSortUtil(int v, bool *visited, stack<int> &stck);

public:
  Graph(int V);
  void addEdge(int src, int dest)
  {
    adjList[src].insert(dest);
    numberOfEdges++;
  };
  void topologicalSort();
};

Graph::Graph(int V)
{
  this->V = V;
  adjList = new unordered_set<int>[V];
  numberOfEdges = 0;
}

void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &stck)
{
  visited[v] = true;
  for (auto itr : adjList[v])
  {
    if (!visited[itr])
    {
      topologicalSortUtil(itr, visited, stck);
    }
  }
  stck.push(v);
}

void Graph::topologicalSort()
{
  stack<int> stck;
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
      topologicalSortUtil(i, visited, stck);
  }

  while (!stck.empty())
  {
    cout << stck.top() << " ";
    stck.pop();
  }
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

  cout << "Following is a Topological Sort of the given graph \n";
  g.topologicalSort();

  return 0;
}
