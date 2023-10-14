#include<bits/stdc++.h>
using namespace std;


int main(){
  int x,n,q;

  for(int i=1; scanf("%d %d", &n, &q); i++){
    if(n==0 and q==0) break;
    if(i>=65) break;
    printf("CASE# %d:\n", i);
    int ans, temp;
    vector<int> numbers;
    for(int j=0; j<n; j++){
      scanf("%d", &temp);
      numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());
    for(int j=0; j<q; j++){
      scanf("%d", &x);
      ans = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
      if(numbers[ans] != x) ans = -1;
      if(ans!=-1) printf("%d found at %d\n", x, ans+1);
      else printf("%d not found\n", x);
    }
  }

  return 0;
}
