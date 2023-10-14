#include<bits/stdc++.h>
using namespace std;
#define ll long long

void luckyNumberGenerator(ll n){
  queue<ll> q;
  q.push(0);
  while(!q.empty()){
    ll x = q.front();
    q.pop();
    if(x >= n) break;
    if(x) printf("%ld\n",x);
    q.push((x*10+4));
    q.push((x*10+7));
  }
}


int main(){
  luckyNumberGenerator(9000000);
}
