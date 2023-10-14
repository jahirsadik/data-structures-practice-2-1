#include <bits/stdc++.h>
using namespace std;

#define DisjSet DisjointSet
class DisjointSet
{
  int *rank, *parent, size, numberOfSets;

  void makeSet()
  {
    for (int i = 0; i < size; i++)
    {
      parent[i] = i;
      rank[i] = 0;
    }
  }

public:
  DisjointSet(unsigned _size)
  {
    rank = new int[_size];
    parent = new int[_size];
    this->size = _size;
    numberOfSets = _size;
    makeSet();
  }

  int find(int data)
  {
    if (parent[data] == data)
      return data;

    int result = find(parent[data]); // for path compression
    parent[data] = result;
    return result;
  }

  void Union(int x, int y)
  {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset)
      return;
    numberOfSets--;
    if (rank[xset] < rank[yset])
      parent[xset] = yset;
    else if (rank[yset] < rank[xset])
      parent[yset] = xset;
    else
    {
      parent[yset] = xset;
      rank[xset]++;
    }
  }

  int getNumberOfSets()
  {
    return numberOfSets;
  }

  void printArrays()
  {
    for (int i = 0; i < size; i++)
    {
      cout << parent[i] << " " << rank[i] << "\t\t";
    }
    cout << endl;
  }
};

int main()
{
  DisjSet obj(5);
  obj.Union(0, 2);
  obj.Union(4, 2);

  obj.Union(1, 0);
  cout << obj.getNumberOfSets() << endl;
  obj.printArrays();
  return 0;
}
