//Link: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
/*
Algorithm:
Steps involved in finding the topological ordering of a DAG:

Step-1: Compute in-degree (number of incoming edges) for each
of the vertex present in the DAG and initialize the count of
visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them
into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then.
Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it
to the queue.
Step 5: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of
nodes in the graph then the topological sort is not possible for
the given graph.
*/



#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adj;
public:
  Graph(int V){
    this->V = V;
    adj = new unordered_set<int>[V];
  };
  void addEdge(int src, int dest){
    adj[src].insert(dest);
  };
  void topologicalSort();
};

void Graph::topologicalSort(){
  queue<int> q;
  vector<int> in_degree(V,0);
  for(int i=0; i<V; i++){
    for(auto itr: adj[i]) in_degree[itr]++;
  }

  for(int i=0; i<V; i++) if(!in_degree[i]) q.push(i);
  int countOfElements = 0;
  vector<int> topSortedOrder;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    topSortedOrder.push_back(u);
    for(auto itr: adj[u]){
      if(--in_degree[itr] == 0) q.push(itr);
    }
    countOfElements++;
  }
  if(countOfElements!=V){
    printf("Topological order not found\n");
    return;
  }
  for(auto itr: topSortedOrder) cout << itr << " ";
  cout << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();

    return 0;
}
