#include<bits/stdc++.h>
using namespace std;

int query(int arr[], int block[], int n, int l, int r){
  int minimumVal = INT_MAX;
  int block_size = (int)(ceil(sqrt(n)));
  while((l<r)&&(l!=0)&&(l%block_size!=0)){
    if(arr[l] < minimumVal) minimumVal = arr[l++];
  }
  while(l+block_size <= r){
    if(minimumVal > block[l/block_size])
            minimumVal = block[l/block_size];
    l += block_size;
  }
  while(l<=r){
    if(arr[l] < minimumVal) minimumVal = arr[l++];
  }
  return minimumVal;
}

void preprocess(int arr[], int block[], int n){
  int block_index = -1;
  int block_size = (int)(ceil(sqrt(n)));
  for(int i=0; i<n; i++){
    if(i%block_size == 0) {
      block_index++;
      block[block_index] = arr[i];
    }
    if(arr[i] < block[block_index]) block[block_index] = arr[i];
  }
}



int main(){
  int t, n, q;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    scanf("\n%d %d", &n, &q);
    int l, r, arr[n];
    int block_size = (int)ceil(sqrt(n));
    int block[block_size];
    memset(block, 0, sizeof(block));
    for(int j=0; j<n; j++) scanf("%d", &arr[j]);
    preprocess(arr, block, n);
    printf("Case %d:\n",i);
    for(int j=0; j<q; j++){
      scanf("%d %d", &l, &r);
      printf("%d\n", query(arr, block, n, --l, --r));
    }
  }
  return 0;
}
