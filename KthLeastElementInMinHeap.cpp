#include<bits/stdc++.h>
using namespace std;

struct Heap{
  std::vector<int> v;
  int n; // size of my heap
  Heap(int i = 0)
      : n(i)
  {
    v = vector<int>(n);
  }
};

inline int left(int i){
  return 2*i + 1;
}

inline int right(int i){
  return 2*i + 2;
}

int findKthSmallest(Heap &h, int k){
  priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > p;
  p.push(make_pair(h.v[0], 0));
  for(int i=0 ; i < k-1; ++i){
    int j = p.top().second;
    p.pop();
    int l = left(j), r = right(j);
    if(l < h.n) p.push(make_pair(h.v[l], l));
    if(r < h.n) p.push(make_pair(h.v[r], r));
  }
  return p.top().first;
}


int main()
{
    Heap h(7);
    h.v = vector<int>{ 10, 50, 40, 75, 60, 65, 45 };
    int k = 4;
    cout << findKthSmallest(h, k) << endl;
    return 0;
}
