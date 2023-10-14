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

string getInfixFromPostfix(string str){
  stack <string> answer;

  for(int i=0; str[i]; i++){
    if(isOperand(str[i])) {
      string temp(1,str[i]);
      answer.push(temp);
    }

    else if(isOperator){
      string op1 = answer.top();
      answer.pop();
      string op2 = answer.top();
      answer.pop();
      answer.push("(" + op2 + str[i] + op1 +")");
    }
  }
  return answer.top();
}


string getInfixFromPrefix(string str){
  stack <string> answer;
  int len = str.length();
  for(int i=len-1; i>=0; i--){
    if(isOperand(str[i])) {
      string temp(1,str[i]);
      answer.push(temp);
    }

    else if(isOperator){
      string op2 = answer.top();
      answer.pop();
      string op1 = answer.top();
      answer.pop();
      answer.push("(" + op2 + str[i] + op1 +")");
    }
  }
  return answer.top();
}




int main(){

  cout << getInfixFromPrefix("*+AB+CD") << endl;
  return 0;
}
