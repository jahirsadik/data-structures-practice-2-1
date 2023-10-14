#include<bits/stdc++.h>
using namespace std;

#define SIZE 100005
#define mx 10
#define my 3
int arr[SIZE];


void update(int arr[], int block[], int l, int r, int block_size){
  while((l!=0)&&(l%block_size!=0)&&(l<r)){
    if(arr[l]!=0) arr[l] = 0;
    else arr[l] = 1;
    l++;
  }
  while(l+block_size <= r){
    if(block[l/block_size]) block[l/block_size] = 0;
    else block[l/block_size] = 1;
    l += block_size;
  }
  while(l<=r){
    if(arr[l]!=0) arr[l] = 0;
    else arr[l] = 1;
    l++;
  }
}

int query(int arr[], int block[], int index, int block_size){
  int block_number = index/block_size;
  int ans = arr[index];
  if(block[block_number] == 1){
    if(ans) ans = 0;
    else ans = 1;
  }
  return ans;
}


int main(){
  int t,q;

  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    printf("Case %d:\n", i);
    memset(arr, 0, sizeof(arr));
    char str[SIZE];
    scanf("%s", str);
    int len = strlen(str);
    for(int j=0; j<len; j++) arr[j] = str[j] - '0';

    int block_size = (int)(ceil(sqrt(len)));
    int block[block_size] = {0};

    scanf("%d", &q);

    for(int j=0; j<q; j++){
      char que[2];
      getchar();
      scanf("%s", que);
      if(que[0] == 'I'){
        int l, r;
        scanf("%d %d", &l, &r);
        update(arr, block, --l, --r, block_size);
      }
      else{
        int index;
        scanf("%d", &index);
        printf("%d\n", query(arr, block, --index, block_size));
      }
    }
  }

  return  0;
}
