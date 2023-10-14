#include<bits/stdc++.h>
using namespace std;

int main(){
  int testCases;
  scanf("%d", &testCases);
  for(int i=1; i<=testCases; i++){
    int n;
    vector<int> vec;
    scanf("%d",&n);
    for(int j=0; j<n; j++){
      int temp;
      scanf("%d",&temp);
      vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    int count = 0;

    for(int j=n-1; j>1; j--){
      int l=0, r=j-1;
      while(l<r){
        if((vec[l]+vec[r])>vec[j]){
          count += r-l;
          r--;
        }
        else l++;
      }
    }
    printf("Case %d: %d\n", i, count);
  }
  return 0;
}
