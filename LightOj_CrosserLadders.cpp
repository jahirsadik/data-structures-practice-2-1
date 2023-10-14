#include<bits/stdc++.h>
using namespace std;

int main(){
  double x,y,c,a,b,w;
  int testCases;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    scanf("%lf %lf %lf",&x,&y,&c);
    double low = 0.0, high = min(x,y), mid;
    int dhuru =100;
    double ans = 1;
    while(dhuru--){
      mid = (high+low)/2.0;
      double tempa, tempb, temp;
      tempa = sqrt((x*x) - (mid*mid));
      tempb = sqrt((y*y) - (mid*mid));
      temp = (tempa*tempb)/(tempa+tempb);
      if(temp<=c) high = mid;
      else low = mid;
    }
    printf("Case %d: %0.9lf\n",i, mid);

  }


  return 0;
}
