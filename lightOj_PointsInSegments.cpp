#include<bits/stdc++.h>
using namespace std;

int main(){
  int testCases, n, q;
  vector<int>:: iterator it1,it2;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    scanf("%d %d", &n, &q);
    vector<int> numbers;
    for(int j=0; j<n; j++){
      int dhuru;
      scanf("%d",&dhuru);
      numbers.push_back(dhuru);
    }
    printf("Case %d:\n",i);
    for(int j=0; j<q; j++){
      scanf("%d %d", &left, &right);
      it1 = lower_bound(numbers.begin(), numbers.end(), left);
      it2 = upper_bound(numbers.begin(), numbers.end(), right);
      printf("%d\n", it2-it1);
    }
  }

  return 0;
}
