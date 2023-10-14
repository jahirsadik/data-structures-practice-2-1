// Link: https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/

#include<bits/stdc++.h>
#include<string>
using namespace std;

class graph{
  int V;
  unordered_set<int> *adjList;

public:
  graph(int V){
    this->V = V;
    adjList = new unordered_set<int>[V];
  }
  void addEdge(int s, int d){
    adjList[s].insert(d);
    adjList[d].insert(s);
  }
  int bfs(int in1, int in2);
};

void sieveOfEratosthenes(vector<int> &v){
  int n = 9999;
  bool prime[n+1];
  memset(prime, true, sizeof(prime));
  for(int p=2; p*p <=n; p++){
    printf("running\n");
    if(prime[p] == true){
      for(int i=p*p; i<=n; i+=p){
        prime[i] = false;
      }
    }
  }
  for(int p = 1000; p<=n; p++){ // because minimum input is four digit
    if(prime[p]) v.push_back(p);
  }
}


bool compareNumbers(int a, int b){
  string s1 = to_string(a);
  string s2 = to_string(b);
  int count = 0;
  if(s1[0]!=s2[0]) count++;
  if(s1[1]!=s2[1]) count++;
  if(s1[2]!=s2[2]) count++;
  if(s1[3]!=s2[3]) count++;
  return (count == 1);
}

int graph::bfs(int in1, int in2){
  int visited[V];
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  visited[in1] = 1;
  q.push(in1);
  while(!q.empty()){
    int p = q.front();
    q.pop();
    for(auto itr: adjList[p]){
      if(!visited[itr]){
        visited[itr] = visited[p]+1;
        q.push(itr);
      }
      if(itr == in2) return (visited[itr] - 1);
    }
  }
  return -1;
}

int shortestPathBetweenPrimes(int num1, int num2){
  vector<int> primes;
  sieveOfEratosthenes(primes);
  graph g(primes.size());
  for(int i=0; i< primes.size(); i++){
    for(int j=i+1; j<primes.size(); j++){
      if(compareNumbers(primes[i], primes[j])) g.addEdge(i, j);
    }
  }

  int in1, in2;
  for(int a =0; a < primes.size(); a++){
    if(primes[a] == num1){
      in1 = a;
      break;
    }
  }
  for(int b =0; b < primes.size(); b++){
    if(primes[b] == num2){
      in2 = b;
      break;
    }
  }
  return g.bfs(in1, in2);
}


int main(){
  int num1 = 1033, num2 = 8179;
  cout << shortestPathBetweenPrimes(num1, num2) << endl;

  return 0;
}
