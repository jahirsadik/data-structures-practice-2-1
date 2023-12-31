// Explanation Link: https://www.youtube.com/watch?v=lyw4FaxrwHg
// gfg link: https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

// Remember -INT_MAX use e jhamela hoi so nije #define oshim disi


#include<bits/stdc++.h>
using namespace std;

#define OSHIM 99999

struct Edge{
  int src, dest, weight;
};

struct Graph{
  int V, E;
  struct Edge *edge;
};

struct Graph* createGraph(int V, int E){
  struct Graph *graph = new Graph();
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

void printArr(int dist[], int n){
  printf("Vertex Distance From Source: \n\t");
  for(int i=0; i<n; i++){
    printf("%d \t %d\n\t", i, dist[i]);
  }
  printf("\n");
}

void BellmanFord(Graph *graph, int src){
  int V = graph->V;
  int E = graph->E;
  int dist[V];
  for(int i=0; i<V; i++) dist[i] = OSHIM;
  dist[src] = 0;

  for(int i=1; i<=V-1; i++){
    for(int j=0; j<E; j++){
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if((dist[u]!=OSHIM)&&(dist[u]+weight < dist[v])){
        dist[v] = dist[u]+weight;
      }
    }
  }

  for(int i=1; i<=V-1; i++){
    for(int j=0; j<E; j++){
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if((dist[u]!=OSHIM)&&(dist[u]+weight < dist[v])){
        dist[v] = -OSHIM;
      }
    }
  }

  printArr(dist, V);
  return;
}

int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);
    cout << endl;

    int V1 = 4, E1 = 4;
    Graph *graph1 = createGraph(V1, E1);
    graph1->edge[0].src = 1;
    graph1->edge[0].dest = 2;
    graph1->edge[0].weight = 1;

    graph1->edge[1].src = 2;
    graph1->edge[1].dest = 3;
    graph1->edge[1].weight = 3;

    graph1->edge[2].src = 2;
    graph1->edge[2].dest = 0;
    graph1->edge[2].weight = 2;

    graph1->edge[3].src = 0;
    graph1->edge[3].dest = 1;
    graph1->edge[3].weight = -5;


    BellmanFord(graph1, 1);

    return 0;
}
