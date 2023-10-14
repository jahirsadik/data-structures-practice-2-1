#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void update(ll arr[], ll block[], ll block2[], int block_size, int l, int r, int val){
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    arr[l] += val;
    block[l/block_size] += val;
    l++;
  }
  while(l+block_size <= r){
    block[l/block_size] += val*block_size;
    block2[l/block_size] += val;
    l += block_size;
  }
  while(l<=r){
    arr[l] += val;
    block[l++/block_size] += val;
  }
}

ll query(ll arr[], ll block[], ll block2[], int block_size, int l, int r){
  ll sum = 0;
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    sum += arr[l];
    sum += block2[l/block_size];
    l++;
  }

  while(l+block_size <= r){
    sum += block[l/block_size];
    l += block_size;
  }

  while(l<=r){
    sum += arr[l];
    sum += block2[l/block_size];
    l++;
  }
  return sum;
}

int main(){
  int t, n, q;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    scanf("%d %d", &n, &q);
    int l, r, w;
    ll arr[n];
    int block_size = (int)(ceil(sqrt(n)));
    ll block[block_size];
    ll block2[block_size];
    memset(arr, 0, sizeof(arr));
    memset(block, 0, sizeof(block));
    memset(block2, 0, sizeof(block2));
    printf("Case %d:\n", i);
    for(int j=0; j<q; j++){
      scanf("%d ", &w);
      if(w){
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(arr, block, block2, block_size, l, r));
      }
      else{
        int val;
        scanf("%d %d %d",&l, &r, &val);
        update(arr, block, block2, block_size, l, r, val);
      }
    }
  }
  return 0;
}
