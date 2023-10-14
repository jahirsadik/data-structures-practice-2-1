#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

ll frequencyCount(vector<ll> vec, int n, ll x){
    int l = lower_bound(vec.begin(), vec.end(), x)-vec.begin();
    int r = upper_bound(vec.begin(), vec.end(), x)-vec.begin();
    if(l==r) return 0;
    else return r-l;
}

int main(){
  vector<ll> vec ={-1, 9, 7, 2, 3, 3, 3, 4, 9};
  map<ll,ll> mp;
  for(int i=0; i<9; i++){
    mp[vec[i]]++;
  }
  cout << "-1: " << mp[-1] << endl;
  cout << "9: " << mp[9] << endl;
  cout << "3: " << mp[3] << endl;


  return 0;
}
