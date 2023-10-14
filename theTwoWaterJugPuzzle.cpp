// Puzzle problem
// Link: https://www.geeksforgeeks.org/two-water-jug-puzzle/

// new

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  return b? gcd(b, a%b) : a;
}

int pourWater(int fromCap, int toCap, int d){
  int from = fromCap;
  int to = 0;
  int step = 1;
  cout << "\n\tSteps taken: \n";
  cout << "(" << from << "," << to << "), ";
  while(from!=d && to!=d){
    int maxAmountTobePoured;
    maxAmountTobePoured = min(from, toCap-to);
    to += maxAmountTobePoured;
    from -= maxAmountTobePoured;
    step++;
    cout << "(" << from << "," << to << "), ";
    if(from == d || to == d) break;
    if(from ==0){
      from = fromCap;
      step++;
      cout << "(" << from << "," << to << "), ";
    }
    if(to == toCap){
      to = 0;
      step++;
      cout << "(" << from << "," << to << "), ";
    }
  }
  cout << "\n\tended\n";
  return step;
}

int minStepsToPour(int m, int n, int d){
  if(m > n) swap(m,n);
  if(d>n) return -1;
  if((d%gcd(n,m))!=0) return -1;
  return min(pourWater(n,m,d), pourWater(m,n,d));
}

int main(){
  int n = 12, m = 5, d = 8;
  printf("Minimum number of steps: %d\n", minStepsToPour(m,n,d));
  return 0;
}
