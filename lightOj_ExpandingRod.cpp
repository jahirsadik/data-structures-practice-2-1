#include<bits/stdc++.h>
using namespace std;

int main(){
  int testCases;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    double l, h, lp, n, c, r, theta, tempLp;
    scanf("%lf %lf %lf",&l, &n, &c);
    lp = (1.0+ (n*c))*l;
    double low = 0.0, high = l, mid, pasa = 100;
    while(pasa--){
      mid = (high+low)/2.0;
      r = (mid/2.0)+((l*l)/(8.0*mid));
      theta = 2 * asin((l)/(2.0*r));
      tempLp = r*theta;
      if(tempLp >= lp) high = mid;
      else low = mid;
    }
    printf("Case %d: %0.9lf\n", i, low);
  }


  return 0;
}
