// problem from lightoj

#include<bits/stdc++.h>
using namespace std;

int main(){

  int t, i=1;
  string command;
  for(scanf("%d",&t); i<=t; i++){
    printf("Case %d:\n",i);
    string current = "http://www.lightoj.com/";
    stack <string> backward;
    stack <string> forward;
    while(1){

      cin >> command;
      if(command == "QUIT") break;
      else if(command == "VISIT"){
        string site;
        cin >> site;
        cout << site << endl;
        backward.push(current);
        current = site;
        while(!forward.empty()) forward.pop();
      }
      else if(command == "BACK"){
        if(!backward.empty()){
          forward.push(current);
          current = backward.top();
          cout << current << endl;
          backward.pop();
        }
        else cout << "Ignored\n";
      }
      else if(command == "FORWARD"){
        if(!forward.empty()){
          backward.push(current);
          current = forward.top();
          cout << current << endl;
          forward.pop();
        }
        else cout << "Ignored\n";
      }
      else break;
    }

  }
  return 0;
}
