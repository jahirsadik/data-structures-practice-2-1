// Link: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

//  Algorithm
/*
Below are the steps for finding MST using Kruskal’s algorithm

1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning
tree formed so far. If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

Time Complexity: O(ElogE) or O(ElogV). Sorting of edges
takes O(ELogE) time. After sorting, we iterate through all
edges and apply find-union algorithm. The find and union
operations can take atmost O(LogV) time. So overall
complexity is O(ELogE + ELogV) time. The value of E can
be atmost O(V2), so O(LogV) are O(LogE) same. Therefore,
overall time complexity is O(ElogE) or O(ElogV)
*/


#include<bits/stdc++.h>
using namespace std;

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

class Edge{
public:
  int src, dest, weight;
};

class Graph{
  int V, E;
public:
  Edge *edge;
  Graph(int V, int E);
  void KruskalMST();
};

Graph::Graph(int V, int E){
    this->V = V;
    this->E = E;
    edge = new Edge[E];
};

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void Graph::KruskalMST(){
  int e = 0;
  int i = 0;
  Edge result[V];
  qsort(edge, E, sizeof(edge[0]), myComp);
  DisjointSet ds(V);
  while((e < V-1) && i < E){
    Edge next_edge = edge[i++];
    int x = ds.find(next_edge.src);
    int y = ds.find(next_edge.dest);
    if(x!=y){
      result[e++] = next_edge;
      ds.Union(x , y);
    }
  }

  for(i = 0; i < e; ++i){
        cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
    }
}

int main()
{
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph graph(V,E);


    // add edge 0-1
    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;
    graph.edge[0].weight = 10;

    // add edge 0-2
    graph.edge[1].src = 0;
    graph.edge[1].dest = 2;
    graph.edge[1].weight = 6;

    // add edge 0-3
    graph.edge[2].src = 0;
    graph.edge[2].dest = 3;
    graph.edge[2].weight = 5;

    // add edge 1-3
    graph.edge[3].src = 1;
    graph.edge[3].dest = 3;
    graph.edge[3].weight = 15;

    // add edge 2-3
    graph.edge[4].src = 2;
    graph.edge[4].dest = 3;
    graph.edge[4].weight = 4;

    graph.KruskalMST();

    return 0;
}
