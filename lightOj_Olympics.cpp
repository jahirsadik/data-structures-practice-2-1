//https://turing13.wordpress.com/2016/09/13/light-oj-1056-olympics/
//https://shahidul-brur.blogspot.com/2017/04/tutorial-lightoj-1056-olympics.html
#include<bits/stdc++.h>
using namespace std;

int main(){
  int testCases;
  scanf("%d", &testCases);

  for(int i=1; i<=testCases; i++){
    double l,w,r,theta, ratio, s;
    scanf("%lf : %lf", &l, &w);
    r = sqrt(((l/2)*(l/2))+((w/2)*(w/2)));
    theta = acos((r*r + r*r - w*w)/(2.0 * r * r));
    s = r*theta;
    ratio = 400.00/(2*l+2*s);
    printf("Case %d: %.10lf %.10lf\n",i, ratio*l,ratio*w);
  }
  return 0;
}
