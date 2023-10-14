#include<bits/stdc++.h>
using namespace std;






int answerDaoBhai(int n,int m){
  int turns = 0;
  queue<vector<int>> q;
  bool breakBool = false;
  while(!breakBool){
    int mValue = turns % (m+1);
    breakBool = true;
    int bal = 0;

    while(true){
      vector<int>::iterator it = find(q.front().begin(), q.front().end(), mValue);
      if(it == q.front().end()){
        q.front().push_back(mValue);
        breakBool = false;
        turns++;
        break;
      }
      else{
        std::vector<int> v = q.front();
        q.push(v);
        q.pop();
        bal++;
      }
      if(bal == q.size()) {
        breakBool = true;
        break;
      }
    }


  }
  return turns*5;
}

int main(){
  int t, i = 1, n, m;
  for(scanf("%d",&t); i<=t; i++){
    cin >> n >> m;
    cout << "Case" << " " << i << ": "<< answerDaoBhai(n,m) << endl;
  }
  return 0;
}
