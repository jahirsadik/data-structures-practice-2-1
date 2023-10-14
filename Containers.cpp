
// used vector of stacks
// for more info check link
// https://saicheems.wordpress.com/2013/08/27/uva-1062-containers/




#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  int t;
  int count = 0;

  t = 1;
  while(1){
    getline(cin, str);
    if(str == "end") break;
    stack <char> stck;
    vector<stack<char>> containers;
    int len = str.length();
    count = 0;
    int flag = 0;

    for(int j=0; j<len; j++){

      flag = 0;
      for(int k=0; k < containers.size(); k++){
        if(str[j] <= containers[k].top()){
          containers[k].push(str[j]);
          flag = 1;
          break;
        }
      }
      if(!flag){
        containers.push_back(stck);
        containers[containers.size()-1].push(str[j]);
        count++;
      }

    }

    printf("Case %d: %d\n",t++, count);
  }
  return 0;
}
