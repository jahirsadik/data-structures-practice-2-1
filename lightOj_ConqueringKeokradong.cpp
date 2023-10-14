#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kotoDin(vector<int> vec, int n, ll mid, int flag){
  ll answer = 0, sum = 0;
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
      if(flag) printf("%d\n",sum);
      sum = vec[i];
      answer++;
    }
  }
  if(flag) printf("%d\n",sum);
  return answer;
}


int main(){
  int testCases;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    int n, k;
    vector<int> vec;
    scanf("%d %d", &n, &k);
    n++;
    for(int j=0; j<n; j++){
      int dhur;
      scanf("%d",&dhur);
      vec.push_back(dhur);
    }

    ll high = LLONG_MAX, low = 0, mid, count = 0, ans = -1;
    int pasa = 500;
    while(pasa--){
      mid = (high+low)/2;
      count  = kotoDin(vec, n, mid, 0);
      if(count > k) low = mid;
      else{
         high = mid;
         ans = mid;
      }
    }
    printf("Case %d: %lld\n", i, ans);
    k++;
    int dhur = k, bhai = 0;
    for(int b=0; b<n; b++){
      bhai+=vec[b];
      if((bhai>ans) || (n-b+1==dhur)){
        dhur--;
        bhai-=vec[b];
        printf("%d\n", bhai);
        bhai = vec[b];
      }
    }
    printf("%d\n",bhai);


  }

  return 0;
}
