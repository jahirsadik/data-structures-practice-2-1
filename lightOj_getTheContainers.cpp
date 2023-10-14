#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll kotoContainersLagbeBolotoBabu(vector<int> vec, int n, ll mid){
  ll answer = 1, sum = 0;
  for(int i=0; i<n; i++){
    if(vec[i] > mid){
      answer = LLONG_MAX;
      break;
    }
    else if(vec[i]+sum <= mid){
      sum += vec[i];
      continue;
    }
    else{
      sum = vec[i];
      answer++;
    }
  }
  return answer;
}




int main(){
  int testCases;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    vector<int> vec;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int j=0; j<n; j++){
      int dhuru;
      scanf("%d",&dhuru);
      vec.push_back(dhuru);
    }
    ll high = LLONG_MAX, low = 0, mid, count = 0, ans = -1;
    int pasa = 500;
    while(pasa--){
      mid = (high+low)/2;
      count  = kotoContainersLagbeBolotoBabu(vec, n, mid);
      if(count > m) low = mid;
      else{
         high = mid;
         ans = mid;
      }
    }
    printf("Case %d: %lld\n", i, ans);
  }

  return 0;
}
