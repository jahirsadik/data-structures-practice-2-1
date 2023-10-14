#include<bits/stdc++.h>
using namespace std;
typedef double dd;

dd distanceBoloToBabu(dd ax, dd ay, dd cx, dd cy){
  dd distance;
  distance = sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
  return distance;
}

int main(){
  int testcases;
  scanf("%d",&testcases);
  for(int i=1;i<=testcases;i++){
    dd xa,xb,ya,yb,xc,xd,yc,yd,ABx, ABy, CDx, tempDis1, tempDis2, CDy, low = 0.0, high = 1.0, mid = 100000.00;
    dd mid1, mid2;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
    int pasa = 100;
    while(pasa--){
      mid1 = (2*low + high)/3.0;
      mid2 = (low + 2*high)/3.0;
      ABx = (1-mid1)*xa + mid1*xb;
      ABy = (1-mid1)*ya + mid1*yb;
      CDx = (1-mid1)*xc + mid1*xd;
      CDy = (1-mid1)*yc + mid1*yd;
      tempDis1 = distanceBoloToBabu(ABx, ABy, CDx, CDy);
      ABx = (1-mid2)*xa + mid2*xb;
      ABy = (1-mid2)*ya + mid2*yb;
      CDx = (1-mid2)*xc + mid2*xd;
      CDy = (1-mid2)*yc + mid2*yd;
      tempDis2 = distanceBoloToBabu(ABx, ABy, CDx, CDy);

      if(tempDis1 > tempDis2){
        low = mid1;
      }
      else high = mid2;
    }

    ABx = (1-mid1)*xa + mid1*xb;
    ABy = (1-mid1)*ya + mid1*yb;
    CDx = (1-mid1)*xc + mid1*xd;
    CDy = (1-mid1)*yc + mid1*yd;
    printf("Case %d: %lf\n",i, distanceBoloToBabu(ABx, ABy, CDx, CDy)) ;
  }
  return 0;
}
