// revise balanced parentheses problem
// make a stack of open brackets and
// if you encounter closed ones, check stack and compare

#include<bits/stdc++.h>
using namespace std;

int main(){
  string str, temp;
  int t;
  scanf("%d",&t);
  cin.ignore();

  for(int i=1; i<=t; i++){
    getline(cin, str);
    stack <char> stck;
    int len = str.length();

    for(int j = 0; j<len; j++){
      if(!stck.empty() && str[j] == ')' && stck.top()=='('){
        stck.pop();
      }
      else if(!stck.empty() && str[j] == ']' && stck.top()=='['){
        stck.pop();
      }
      else if(str[j]!='(' && str[j]!=')'&& str[j]!='[' && str[j]!=']'){
        printf("Continue\n" );
        continue;
      }
      else stck.push(str[j]);
    }

    if(stck.empty()) printf("Yes\n");
    else printf("No\n");

  }

  return 0;
}
