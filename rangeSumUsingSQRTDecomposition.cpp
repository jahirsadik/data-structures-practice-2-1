#include<bits/stdc++.h>
using namespace std;

void update(int arr[], int block[], int idx, int val, int block_size){
  int block_number = idx/block_size;
  block[block_number] += (val-arr[idx]);
  arrp[idx] = val;
}

void query(int arr[], int block[], int block_size, int l, int r){
  printf("%d to %d:\n", l, r);
  int sum = 0;
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    sum += arr[l];
    l++;
  }
  while(l+block_size <= r){
    sum += block[l/block_size];
    l += block_size;
  }
  while(l<=r){
    sum += arr[l];
    l++;
  }
  printf("sum: %d\n", sum);
}

void preprocess(int arr[], int block[], int n){
  int blk_inx = -1;
  int block_size = (int)(ceil(sqrt(n)));
  for(int i=0; i<n; i++){
    if(i%block_size == 0){
      blk_inx++;
    }
    block[blk_inx] += arr[i];
  }
}

int main(){
  int t, n, q;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    scanf("\n%d %d", &n, &q);
    int l, r, arr[n];
    int block_size = (int)ceil(sqrt(n));
    int block[block_size] = {0};
    for(int j=0; j<n; j++) scanf("%d", &arr[j]);
    preprocess(arr, block, n);
    printf("Case %d:\n",i);
    for(int j=0; j<q; j++){
      scanf("%d %d", &l, &r);
      printf("%d to %d sum: ", l, r);
      query(arr, block, block_size, l, r);
    }
  }
  return 0;
}
