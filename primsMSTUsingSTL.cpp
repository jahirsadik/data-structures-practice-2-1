// Link: https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

//          algorithm
/*
1) Initialize keys of all vertices as infinite and
   parent of every vertex as -1.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.

3) Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Ptim's implementation differs from Dijkstra.
   In Dijkstr's algorithm, we didn't need this array as
   distances always increase. We require this array here
   because key value of a processed vertex may decrease
   if not checked.

4) Insert source vertex into pq and make its key as 0.

5) While either pq doesn't become empty
    a) Extract minimum key vertex from pq.
       Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do
       following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)

               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the pq
               (iv) parent[v] = u

6) Print MST edges using parent array.

*/

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph
{
  int V;
  list<iPair> *adj;

public:
  Graph(int V);
  void addEdge(int u, int v, int w);
  void primMST();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  int src = 0;
  vector<int> key(V, INF);
  vector<int> parent(V, -1);
  vector<bool> inMST(V, false);
  pq.push(make_pair(0, src));
  key[src] = 0;
  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    inMST[u] = true;
    for (auto i : adj[u])
    {
      int v = i.first;
      int weight = i.second;
      if ((!inMST[v]) && key[v] > weight)
      {
        key[v] = weight;
        pq.push(make_pair(key[v], v));
        parent[v] = u;
      }
    }
  }

  for (int i = 0; i < V; ++i)
    printf("%d - %d\n", parent[i], i);
}

int main()
{
  // create the graph given in above fugure
  int V = 7;
  Graph g(V);

  //  making above shown graph
  g.addEdge(0, 1, 7);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 3, 9);
  g.addEdge(1, 4, 7);
  g.addEdge(2, 4, 5);
  g.addEdge(3, 4, 15);
  g.addEdge(3, 5, 6);
  g.addEdge(4, 5, 8);
  g.addEdge(4, 6, 9);
  g.addEdge(5, 6, 11);

  g.primMST();

  return 0;
}
