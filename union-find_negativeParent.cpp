#include<bits/stdc++.h>
using namespace std;

#define DisjSet DisjointSet
class DisjointSet{
  int *rank, *parent, size, numberOfSets;

public:
  DisjointSet(unsigned _size){
    rank = new int[_size];
    parent = new int[_size];
    this->size = _size;
    numberOfSets = _size;
    makeSet();
  }

  void makeSet(){
    for(int i=0; i<size; i++){
      parent[i] = -1;
      rank[i] = 0;
    }
  }

  int find(int data){
    if(parent[data] < 0) return data;

    int result = find(parent[data]); // for path compression
    parent[data] = result;
    return result;
  }

  void Union(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if(xset == yset) return;
    numberOfSets--;

    if(rank[xset] < rank[yset]){
      parent[yset]+=parent[xset];
      parent[xset] = yset;
    }
    else if(rank[yset] < rank[xset]) {
      parent[xset]+= parent[yset];
      parent[yset] = xset;
    }
    else{
      parent[xset]+= parent[yset];
      parent[yset] = xset;
      rank[xset]++;
    }
  }

  int getNumberOfSets(){
    return numberOfSets;
  }

  void printArrays(){
    for(int i=0; i<size ; i++){
      cout << "i:" << i << "   parent:" << parent[i] << " " << "   rank:" << rank[i] << endl;
    }
    cout << endl;
  }

  void setElementNumber(int _data){
    int x = find(_data);
    printf("%d\n",-parent[x]);
  }

};

int main()
{
    DisjSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3,1);
    obj.printArrays();
    return 0;
}
