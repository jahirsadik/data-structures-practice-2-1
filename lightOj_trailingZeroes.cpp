#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull zeroKoita(ull n){
  ull count = 0, number, power = 5;

  while(power <= n){
    count += n/power;
    power*=5;
  }
  return count;
}


int main(){
  int testCases;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    ull q;
    scanf("%llu", &q);
    ull high = ULLONG_MAX, low = 0, ans = -1, mid;
    int x=500;
    while(x--){
      mid = (low+high)/2;
      ull zeros = zeroKoita(mid);
      if(zeros > q) high = mid;
      else if(zeros < q) low = mid;
      else{
        ans = mid;
        high = mid;
      }
    }

    if(ans == -1) printf("Case %d: impossible\n", i);
    else printf("Case %d: %llu\n",i,ans);
  }

  return 0;
}
