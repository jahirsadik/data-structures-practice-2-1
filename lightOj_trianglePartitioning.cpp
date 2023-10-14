#include<bits/stdc++.h>
using namespace std;


double area(double a, double b, double c){
  double s = (a+b+c)/2.0;
  double temp = s * (s-a) * (s-b) * (s-c);
  return sqrt(temp);
}

double answerBolShalarpo(double ab, double ac, double bc, double givenRatio){
  double low = 0.0;
  double high = ab;
  double cAB, cAC, cBC;
  double bTArea = area(ab,ac,bc);
  double mid;
  for(int w = 100; w; w--){
    mid = (low+high)/2.00;
    cAB = mid;
    cAC = (cAB/ab) * ac;
    cBC = (cAB/ab) * bc;
    double tArea = area(cAB, cAC, cBC);
    double oArea = bTArea -tArea;
    if((tArea/oArea) > givenRatio){
      high = mid;
    }
    else low = mid;
  }
  return mid;
}

int main(){
  int testCases;
  double ab, ac, bc, givenRatio;
  scanf("%d", &testCases);
  for(int i=1; i<=testCases; i++){
    scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &givenRatio);
    double ans = answerBolShalarpo(ab, ac, bc, givenRatio);
    printf("Case %d: %.7lf\n",i, ans);
  }
  return 0;
}
