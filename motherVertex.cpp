

//  Implementation for weighted graphs

#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  vector<pair<int, int>> *adjList;
  bool isDirected, isWeighted;

public:
  Graph(int V){
    this->V = V;
    adjList = new vector<pair<int, int>>[V];
    isDirected = false;
    isWeighted = false;
  }

  Graph(int V, bool _isDirected){
    this->V = V;
    adjList = new vector<pair<int, int>>[V];
    isDirected = _isDirected;
    isWeighted = false;
  }

  Graph(int V, bool _isDirected, bool _isWeighted){
    this->V = V;
    adjList = new vector<pair<int, int>>[V];
    isDirected = _isDirected;
    isWeighted = _isWeighted;
  }

  void addEdge(int u, int v){
    if(!isDirected){
      adjList[u].push_back(make_pair(v,1));
      adjList[v].push_back(make_pair(u,1));
    }
    else{
      printf("Can't add undirected edge to directed graph\n");
    }
  }

  void addDirectedEdge(int u, int v){
    if(!isDirected){
      printf("Can't add directed edge to undirected graph\n");
    }
    else{
      adjList[u].push_back(make_pair(v,1));
    }
  }

  void addWeightedEdge(int u, int v, int w){
    if(!isWeighted){
      printf("Can't add weighted edge in an unweighted graph!\n");
    } else{
      if(!isDirected){
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
      }
      else{
        printf("Can't add undirected edge to directed graph\n");
      }
    }
  }

  void addDirectedWeightedEdge(int u, int v, int w){
    if(!isWeighted){
        printf("Can't add weighted edge in an unweighted graph!\n");
    } else{
      if(!isDirected){
        printf("Can't add directed edge to undirected graph\n");
      }
      else{
        adjList[u].push_back(make_pair(v,w));
      }
    }
  }

  void printGraph(){
    if(!isWeighted && !isDirected) printf("\n\t\tUnweighted, Undirected graph:\n");
    else if(!isWeighted && isDirected) printf("\n\t\tUnweighted, Directed graph:\n");
    else if(isWeighted && isDirected) printf("\n\t\tWeighted, Directed graph:\n");

    if(!isWeighted){
      for(int i=0; i<V; i++){
        vector<pair<int, int>> uS = adjList[i];
        cout << endl << "Adjacency list of vertex: " << i << endl;
        for(auto itr: uS) cout << itr.first << " ";
        cout << endl;
      }
    } else{
        for(int i=0; i<V; i++){
          vector<pair<int, int>> uS = adjList[i];
          cout << endl << "Adjacency list of vertex: " << i << endl;
          for(auto itr: uS) cout << "(" <<itr.first << "," << itr.second << ")" << " ";
          cout << endl;
        }
    }
  }

  void DFSUtil(int s, bool* visited){
    visited[s] = true;
    for(auto itr: adjList[s]){
      if(!visited[itr.first]){
        DFSUtil(itr.first, visited);
      }
    }
  }

  int motherVertex(){
    bool *visited = new bool[V];
    for(int j=0; j<V; j++) visited[j] = false;
    int ans = 0;
    for(int i=0; i<V; i++){
      if(!visited[i]){
        DFSUtil(i, visited);
        ans = i;
      }
    }
    for(int j=0; j<V; j++) visited[j] = false;
    printf("ans : %d\n", ans);
    DFSUtil(ans, visited);
    for(int i=0; i<V; i++){
      if(!visited[i]) return -1;
    }
    return ans;
  }


};

int main()
{
    Graph g(7, true);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(2, 4);
    g.addDirectedEdge(4, 5);
    g.addDirectedEdge(4, 6);
    g.addDirectedEdge(0, 3);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(3, 2);
    g.addDirectedEdge(3, 4);
    g.printGraph();

    printf("mother : %d\n", g.motherVertex());
    return 0;
}
