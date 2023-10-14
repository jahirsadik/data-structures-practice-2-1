// Link: https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

//                   Algorithm
/*
1) Create a graph g with number of vertices equal to the size of
alphabet in the given alien language. For example, if the alphabet
size is 5, then there can be 5 characters in words. Initially there
are no edges in graph.
2) Do following for every pair of adjacent words in given sorted array.
…..a) Let the current pair of words be word1 and word2. One by one compare
characters of both words and find the first mismatching characters.
…..b) Create an edge in g from mismatching character of word1 to that of word2.
3) Print topological sorting of the above created graph.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  unordered_set<int> *adj;
  void topologicalSortUtil(int v, bool visited[],
                                  stack<int> &stck);
public:
  Graph(int V);
  void addEdge(int v, int w);
  void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new unordered_set<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].insert(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stck) {
    visited[v] = true;
    for (auto i: adj[v])
        if (!visited[i])
            topologicalSortUtil(i, visited, stck);
    stck.push(v);
}


void Graph::topologicalSort(){
    stack<int> stck;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, stck);
    while (!stck.empty()) {
        cout << (char) ('a' + stck.top()) << " ";
        stck.pop();
    }
}

int min(int x, int y)
{
    return (x < y)? x : y;
}

void printOrder(string words[], int n, int alpha){
  Graph g(alpha);
  for(int i=0; i<n-1; i++){
    string word1 = words[i];
    string word2 = words[i+1];
    for(int j=0; j< min(word1.length(), word2.length()); j++){
      if(word1[j]!=word2[j]){
        g.addEdge(word1[j]-'a', word2[j]-'a');
        break;
      }
    }
  }
  g.topologicalSort();
}

int main()
{
    string words[] = {"caa", "aaa", "aab"};
    printOrder(words, 3, 3);
    return 0;
}
