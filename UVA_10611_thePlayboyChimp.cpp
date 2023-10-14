#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, q, x, temp1, temp2;
  vector<int> heights;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    int etaKenLage;
    scanf("%d", &etaKenLage);
    heights.push_back(etaKenLage);
  }
  scanf("%d", &q);
  for(int i=0; i<q; i++){
    scanf("%d",&x);
    int ans;
    ans = lower_bound(heights.begin(), heights.end(), x) - heights.begin();
    if(!ans) printf("X ");
    else printf("%d ",heights[ans-1]);
    ans = upper_bound(heights.begin(), heights.end(), x) - heights.begin();
    if(ans>n-1) printf("X\n");
    else if(ans == n-1 && x == heights[ans]) printf("X\n");
    else printf("%d\n", heights[ans]);
  }

  return 0;
}
