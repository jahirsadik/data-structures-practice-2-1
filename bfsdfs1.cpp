

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
        cout << endl << "Adjacency list of vertex -> " << i << " : ";
        for(auto itr: uS) cout << itr.first << " ";
        cout << endl;
      }
    } else{
        for(int i=0; i<V; i++){
          vector<pair<int, int>> uS = adjList[i];
          cout << endl << "Adjacency list of vertex -> " << i << " : ";
          for(auto itr: uS) cout << "(" <<itr.first << "," << itr.second << ")" << " ";
          cout << endl;
        }
    }
  }

  void BFSUtil(int s){
    printf("BFS starting from vertex: %d -> ", s);
    bool *visited = new bool[this->V];
    queue<int> q;
    for(int i=0; i<V; i++) visited[i] = false;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
      s = q.front();
      cout << s << " ";
      q.pop();
      for(auto itr : adjList[s]){
        if(!visited[itr.first]){
          visited[itr.first] =true;
          q.push(itr.first);
        }
      }
    }
    cout << endl;
  }

  void BFS(){
    BFSUtil(rand()%V);
  }

  void DFSUtil(int s, bool *visited){
    visited[s] = true;
    cout << s << " ";
    for(auto itr: adjList[s]){
      if(!visited[itr.first]){
        DFSUtil(itr.first, visited);
      }
    }
  }

  void DFS(){
    int s = rand()%V;
    printf("Starting DFS from vertex: %d -> ", s);
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) visited[i] = false;
    DFSUtil(s, visited);
    cout << endl;
  }

  void DFSUsingStack(int s){
    printf("Starting DFS from vertex: %d -> ", s);
    bool *visited = new bool[V];
    stack<int> stck;
    for(int i=0; i<V; i++) visited[i] = false;
    stck.push(s);
    visited[s] = true;
    while(!stck.empty()){
      s = stck.top();
      cout << s << " ";
      stck.pop();
      for(auto itr : adjList[s]){
        if(!visited[itr.first]){
          visited[itr.first] =true;
          stck.push(itr.first);
        }
      }
    }
    cout << endl;
  }



// finding mother vertex

  void DFSUtilWithoutPrint(int s, bool* visited){
    visited[s] = true;
    for(auto itr: adjList[s]){
      if(!visited[itr.first]){
        DFSUtilWithoutPrint(itr.first, visited);
      }
    }
  }

  int findMotherVertex(){
    bool *visited = new bool[V];
    for(int j=0; j<V; j++) visited[j] = false;
    int ans = 0;
    for(int i=0; i<V; i++){
      if(!visited[i]){
        DFSUtilWithoutPrint(i, visited);
        ans = i;
      }
    }
    for(int j=0; j<V; j++) visited[j] = false;
    DFSUtilWithoutPrint(ans, visited);
    for(int i=0; i<V; i++){
      if(!visited[i]) return -1;
    }
    return ans;
  }


// Transitive closure print
  void DFSTransitiveClosure(int s, int v, bool tc[][7]){
    tc[s][v] = true;
    for(auto itr: adjList[v]){
      if(!tc[s][itr.first]) DFSTransitiveClosure(s, itr.first, tc);
    }
  }

  void transitiveClosure(){
    bool tc[7][7]; // can't figure how to do this without constant values
    for(int i=0; i<V; i++){
      for(int j=0; j<V; j++){
        tc[i][j] = false;
      }
    }
    for(int i=0; i<V; i++) DFSTransitiveClosure(i, i, tc);
    for (int i=0; i<V; i++){
      for (int j=0; j<V; j++) cout << tc[i][j] << " ";
      cout << endl;
    }

  }


// level finder using bfs
  void printLevels(int s){
    std::vector<int> levels(V, 0);
    bool *visited = new bool[this->V];
    queue<int> q;
    for(int i=0; i<V; i++) visited[i] = false;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
      s = q.front();
      q.pop();
      for(auto itr : adjList[s]){
        if(!visited[itr.first]){
          visited[itr.first] =true;
          levels[itr.first] = levels[s] + 1;
          q.push(itr.first);
        }
      }
    }
    printf("Levels starting from vertex: %d -> ", s);
    for(int i=0; i<V; i++) cout << "("<< i << ", " << levels[i] << ") " ;
    cout << endl;
  }

// finding k-core graph
  bool kCoreUtil(int v, vector<bool> &visited, vector<int> &vDegree, int k){
    visited[v] = true;
    for(auto itr: adjList[v]){
      if(vDegree[v] < k) vDegree[itr.first]--;
      if(!visited[itr.first]){
        if(kCoreUtil(itr.first, visited, vDegree, k)) vDegree[v]--;
      }
    }
    return (vDegree[v]<k);
  }

  void printKCores(int k){
    if(this->isDirected){
      printf("Directed graph k-core not found!\n");
      return;
    }
    vector<bool> visited(V, false);
    vector<int> vDegree(V, 0);
    int minDeg = INT_MAX, startVertex;
    for(int i=0; i<V; i++){
      vDegree[i] = adjList[i].size();
      if(vDegree[i] < minDeg){
        minDeg = vDegree[i];
        startVertex = i;
      }
    }

    kCoreUtil(startVertex, visited, vDegree, k);
    cout << "\n\t\tK-Cores: \n";
    for(int i=0; i<V; i++){
      if(vDegree[i] >=k){
        cout << "\n[" << i << "]";
        for(auto itr: adjList[i]){
          if(vDegree[itr.first] >= k) cout << " -> " << itr.first;
        }
      }
    }
    cout << endl;
  }





};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    g.printGraph();
    printf("Mother vertex: %d\n", g.findMotherVertex());
    g.transitiveClosure();
    g.printLevels(0);

    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(3);
    return 0;
}
