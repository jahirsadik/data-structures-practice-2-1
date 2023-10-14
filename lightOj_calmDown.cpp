#include<bits/stdc++.h>
using namespace std;
int main(){
  int testCases,n;
  double r;
  scanf("%d",&testCases);
  for(int i=1; i<=testCases; i++){
    scanf("%lf %d", &r, &n);
    printf("Case %d: %.10lf\n", i, ((r*sin(M_PI/n))/(1+sin(M_PI/n))));
  }
  return 0;
}
