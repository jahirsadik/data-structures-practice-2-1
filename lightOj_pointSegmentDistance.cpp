#include<bits/stdc++.h>
using namespace std;
typedef double dd;

dd distanceBoloToBabu(dd ax, dd ay, dd az, dd cx, dd cy, dd cz){
  dd distance;
  distance = sqrt( (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy) + (az-cz)*(az-cz));
  return distance;
}

int main(){
  int testcases;
  scanf("%d",&testcases);
  for(int i=1; i<=testcases; i++){
    dd x1, y1, z1, x2, y2, z2, x, y, z, tempDis1, tempDis2, high = 1.0, low = 0.0, mid1, mid2;
    dd ax, ay, az;
    int pasa = 100;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x, &y, &z);
    while(pasa--){
      mid1 = (2*low + high)/3.00;
      ax = (1-mid1)*x1 + mid1*x2;
      ay = (1-mid1)*y1 + mid1*y2;
      az = (1-mid1)*z1 + mid1*z2;
      tempDis1 = distanceBoloToBabu(ax,ay,az,x,y,z);
      mid2 = (low + 2*high)/3.00;
      ax = (1-mid2)*x1 + mid2*x2;
      ay = (1-mid2)*y1 + mid2*y2;
      az = (1-mid2)*z1 + mid2*z2;
      tempDis2 = distanceBoloToBabu(ax,ay,az,x,y,z);
      if(tempDis1>tempDis2) low = mid1;
      else high = mid2;
    }
    printf("Case %d: %0.9lf\n", i, tempDis1);
  }

  return 0;
}
