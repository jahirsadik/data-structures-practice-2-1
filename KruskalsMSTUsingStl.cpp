// Link: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/

/*                  Algorithm
Below are the steps for finding MST using Kruskal’s algorithm

Sort all the edges in non-decreasing order of their weight.
Pick the smallest edge. Check if it forms a cycle with the
spanning tree formed so far. If cycle is not formed, include this
edge. Else, discard it.
Repeat step#2 until there are (V-1) edges in the spanning tree.
Here are some key points which will be useful for us in implementing
the Kruskal’s algorithm using STL.

Use a vector of edges which consist of all the edges in the graph
and each item of a vector will contain 3 parameters: source, destination
and the cost of an edge between the source and destination.
		vector<pair<int, pair<int, int> > > edges;
Here in the outer pair (i.e pair<int,pair<int,int> > ) the first
element corresponds to the cost of a edge while the second element is
itself a pair, and it contains two vertices of edge.

Use the inbuilt std::sort to sort the edges in the non-decreasing order;
by default the sort function sort in non-decreasing order.
We use the Union Find Algorithm to check if it the current edge forms
a cycle if it is added in the current MST. If yes discard it, else include it (union).

*/


#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> iPair;

class Graph{
  int V, E;
  vector< pair<int, iPair>> edges;
public:
  Graph(int V, int E){
    this->V = V;
    this->E = E;
  }
  void addEdge(int u, int v, int w){
    edges.push_back({w,{u,v}});
  }
  int KruskalMST();
};

class DisjointSet{
  int *rank, *parent, size, numberOfSets;

  void makeSet(){
    for(int i=0; i<size; i++){
      parent[i] = i;
      rank[i] = 0;
    }
  }

public:
  DisjointSet(unsigned _size){
    rank = new int[_size];
    parent = new int[_size];
    this->size = _size;
    numberOfSets = _size;
    makeSet();
  }

  int find(int data){
    if(parent[data] == data) return data;

    int result = find(parent[data]); // for path compression
    parent[data] = result;
    return result;
  }

  void Union(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if(xset == yset) return;
    numberOfSets--;
    if(rank[xset] < rank[yset]) parent[xset] = yset;
    else if(rank[yset] < rank[xset]) parent[yset] = xset;
    else{
      parent[yset] = xset;
      rank[xset]++;
    }
  }

  int getNumberOfSets(){
    return numberOfSets;
  }

  void printArrays(){
    for(int i=0; i<size ; i++){
      cout << parent[i] << " " << rank[i] << "\t\t";
    }
    cout << endl;
  }

};

int Graph::KruskalMST(){
  int mstWeight = 0;
  sort(edges.begin(), edges.end());
  DisjointSet ds(V);
  for(auto it: edges){
    int u = it.second.first;
    int v = it.second.second;
    int set_u = ds.find(u);
    int set_v = ds.find(v);
    if(set_u != set_v){
      cout << u << " - " << v << endl;
      mstWeight+= it.first;
      ds.Union(set_u, set_v);
    }
  }

  return mstWeight;
}

int main()
{
    /* Let us create above shown weighted
       and unidrected graph */
    int V = 9, E = 14;
    Graph g(V, E);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "Edges of MST are \n";
    int mst_wt = g.KruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
}
