#include<bits/stdc++.h>
using namespace std;

int precedence(char ch) {
  if(ch == '^') return 4;
  if(ch == '*' || ch == '/') return 3;
  if(ch == '+' || ch == '-') return 2;
  if(ch == '(') return 1;
  return -1;
}

bool isOperand(char ch){
  if(ch >= 'a' && ch <= 'z') return true;
  if(ch >= 'A' && ch <= 'Z') return true;
  if(ch >= '0' && ch <= '9') return true;
  return false;
}

bool isOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') return true;
  return false;
}

void infixToPostfix(string str){
  stack <char> stck;
  int len = str.length();
  string temp;
  for(int i=0; i<len; i++) {
    if(isOperand(str[i])) temp += str[i];
    else if(str[i] == '(') stck.push('(');
    else if(str[i] == ')') {
      while(!stck.empty() && stck.top() != '(') {
        temp += stck.top();
        stck.pop();
      }
      if(stck.top() == '(') stck.pop();
    }

    else if(isOperator(str[i])){
      while(!stck.empty() && precedence(str[i])<=precedence(stck.top())){
        temp += stck.top();
        stck.pop();
      }
      stck.push(str[i]);
    }
  }
  while(!stck.empty()){
    temp += stck.top();
    stck.pop();
  }

  cout << temp << endl;

}

int main()
{
    string exp = "((a+b)*r+w/t)*x";
    infixToPostfix(exp);
    return 0;
}
