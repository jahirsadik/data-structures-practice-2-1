/*                    Implementation using adjacency lists

Adjacency List:
An array of lists is used. Size of the array is equal to the number of vertices.
Let the array be array[]. An entry array[i] represents the list of vertices
adjacent to the ith vertex. This representation can also be used to represent a
weighted graph. The weights of edges can be represented as lists of pairs. Following
is adjacency list representation of the above graph.

Pros: Saves space O(|V|+|E|) .
In the worst case, there can be C(V, 2) number of edges in a graph thus consuming
 O(V^2) space. Adding a vertex is easier.

Cons: Queries like whether there is an edge from vertex u to vertex v are not
efficient and can be done O(V).

*/



#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(std::vector<int> adj[], int size){
  for(int i=0; i<size; i++){
    cout << "\n Adjacency list of vertex "
              << i << "\n head ";
    for(auto j: adj[i]) cout << "-> " << j;
    cout << endl;
  }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
