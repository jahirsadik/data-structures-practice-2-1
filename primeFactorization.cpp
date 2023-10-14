#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool sieveOfErathosthenesGlobal[20000000];
vector<int> allPrimes;

void sieveOfErathosthenes(int n){
  memset(sieveOfErathosthenesGlobal, true, sizeof(sieveOfErathosthenesGlobal));
  for(int i=2; i*i<=n; i++){
    if(sieveOfErathosthenesGlobal[i] == true){
      for(int j=i*i; j<=n; j+=i){
        sieveOfErathosthenesGlobal[j] = false;
      }
    }
  }
  for(int i=2; i<=n; i++){
    if(sieveOfErathosthenesGlobal[i]){
      allPrimes.push_back(i);
    }
  }
}


void printFactors(int n){
  queue<ll> qtemp, qans;
  qtemp.push(1);
  int sqr = sqrt(n);
  int count = 0;

  for(int i=2; i<=sqr; i++){
    count = 0;
    while(n % i == 0){
      n = n/i;
      count++;
    }
    if(count > 0){
      printf("%d %d\n", i, count);
      sqr = sqrt(n);
    }
  }

  if(n > 1){
    printf("%d 1\n", n);
  }
}

int main(){
  sieveOfErathosthenes(100);
  printFactors(42);
  return 0;
}
