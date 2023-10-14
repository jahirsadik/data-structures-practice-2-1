#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> vec = {1,2,3,4,5};
  cout << upper_bound(vec.begin(),vec.end(), 4)-vec.begin()  << endl;
  return 0 ;
}
