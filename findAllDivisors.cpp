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


void printDivisors(int n){
  queue<ll> qtemp, qans;
  vector<ll> divisors;
  qtemp.push(1);
  qans.push(1);
  divisors.push_back(1);
  int sqr = sqrt(n);
  int count = 0;

  for(int i=2; i<=sqr; i++){
    count = 0;
    while(n % i == 0){
      n = n/i;
      count++;
    }
    if(count > 0){
    ll y;
      while(!qtemp.empty()){
        ll x = qtemp.front();
        qtemp.pop();
        for(int k=1, y = i; k<=count; k++, y*=i){
          qans.push((x*y));
          divisors.push_back((x*y));
        }
      }
      qtemp = qans;
      sqr = sqrt(n);
    }
  }

  if(n > 1){
    ll y;
      while(!qtemp.empty()){
        ll x = qtemp.front();
        qtemp.pop();
        for(int k=1, y = n; k<=1; k++, y*=n){
          qans.push((x*y));
          divisors.push_back((x*y));
        }
      }
  }

  sort(divisors.begin(), divisors.end());
  for(auto vi = divisors.begin(); vi != divisors.end(); ++vi){
    printf("%ld ", *vi);
  }
  printf("\n");
}

int main(){
  sieveOfErathosthenes(1000000);
  printFactors(42);
  printDivisors(1000000007);
  return 0;
}
