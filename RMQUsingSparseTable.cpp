#include<bits/stdc++.h>
using namespace std;

void preprocess(int arr[], int lookup[][25], int n){
  for(int i=0; i<n; i++) lookup[i][0] = i;
  for(int j=1; (1<<j)<=n; j++){
    for(int i=0; i+(1<<j)-1 < n; i++){
      if(arr[lookup[i][j-1]]< arr[lookup[i+(1<<(j-1))][j-1]]){
        lookup[i][j] = lookup[i][j-1];
      }
      else
        lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
    }
  }
}

int main(){
  int t, n, q;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    scanf("\n%d %d", &n, &q);
    int arr[n], lookup[n][25], l, r;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    preprocess(arr, lookup, n);
    printf("Case %d:\n",i);
    for(int i=0; i<q; i++){
      scanf("%d %d", &l, &r);
      l--;
      r--;
      int d = (int)log2(r-l+1);
      printf("%d\n", min(arr[lookup[l][d]],
                         arr[lookup[r - (1<<d) + 1][d]]));
    }
  }
  return 0;
}
