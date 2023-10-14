#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void update(ll arr[], ll block[], ll divisible[], ll divisible1[], ll divisible2[], int block_size, int l, int r){
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    if((block[l/block_size] + arr[l]) % 3 == 0) divisible[l/block_size]--;
    if((block[l/block_size] + arr[l]) % 3 == 1) divisible1[l/block_size]--;
    if((block[l/block_size] + arr[l]) % 3 == 2) divisible2[l/block_size]--;
    arr[l]++;
    if((block[l/block_size] + arr[l]) % 3 == 0) divisible[l/block_size]++;
    if((block[l/block_size] + arr[l]) % 3 == 1) divisible1[l/block_size]++;
    if((block[l/block_size] + arr[l]) % 3 == 2) divisible2[l/block_size]++;
    l++;
  }

  while((l + block_size) <= r+1){
    block[l/block_size]++;
    int one = divisible1[l/block_size], two = divisible2[l/block_size], three = divisible[l/block_size];
    divisible[l/block_size] = two;
    divisible1[l/block_size] = three;
    divisible2[l/block_size] = one;
    l += block_size;
  }

  while(l<=r){
    if((block[l/block_size] + arr[l]) % 3 == 0) divisible[l/block_size]--;
    if((block[l/block_size] + arr[l]) % 3 == 1) divisible1[l/block_size]--;
    if((block[l/block_size] + arr[l]) % 3 == 2) divisible2[l/block_size]--;
    arr[l]++;
    if((block[l/block_size] + arr[l]) % 3 == 0) divisible[l/block_size]++;
    if((block[l/block_size] + arr[l]) % 3 == 1) divisible1[l/block_size]++;
    if((block[l/block_size] + arr[l]) % 3 == 2) divisible2[l/block_size]++;
    l++;
  }
}

ll query(ll arr[], ll block[], ll divisible[], int block_size, int l, int r){
  ll sum = 0;
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    if((arr[l]+block[l/block_size]) % 3 == 0) sum++;
    l++;
  }

  while(l+block_size <= r){
    sum += divisible[l/block_size];
    l += block_size;
  }

  while(l<=r){
    if((arr[l]+block[l/block_size]) % 3 == 0) sum++;
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
    ll divisible[block_size];
    ll divisible1[block_size];
    ll divisible2[block_size];
    memset(arr, 0, sizeof(arr));
    memset(block, 0, sizeof(block));
    for(int k=0; k < block_size - 1; k++){
       divisible[k] = block_size;
       divisible1[k] = 0;
       divisible2[k] = 0;
    }
    int count = 0;
    count = n  - ((n/block_size))*(block_size);
    divisible[n/block_size] = count;
    divisible1[n/block_size] = 0;
    divisible2[n/block_size] = 0;
    printf("Case %d:\n", i);
    for(int j=0; j<q; j++){
      scanf("%d ", &w);
      if(w){
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(arr, block, divisible, block_size, l, r));
      }
      else{
        scanf("%d %d",&l, &r);
        update(arr, block, divisible, divisible1, divisible2, block_size, l, r);
      }
    }
  }
  return 0;
}
