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

int performOperationOn(int a, int b, char opt){
  if(opt == '+') return a+b;
  if(opt == '-') return a-b;
  if(opt == '*') return a*b;
  if(opt == '/') return a/b;
  if(opt == '^'){
    int power = 1;
    for(int i=1; i<=b; i++) power *= a;
    return power;
  }
  return 0;
}


string infixToPostfix(string str){
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

  return temp;
}

int evaluatePostfix(string str){
  stack <int> operandStack;
  int len = str.length();

  for(int i=0; i<len; i++){

    if(isOperand(str[i])){
      operandStack.push(str[i]-'0');
    }

    else if(isOperator(str[i])){
      int secondOperand = operandStack.top();
      operandStack.pop();
      int firstOperand = operandStack.top();
      operandStack.pop();
      int golPasa = performOperationOn(firstOperand, secondOperand, str[i]);
      operandStack.push(golPasa);
    }
  }
  int ans = operandStack.top();
  operandStack.pop();
  return ans;
}

string infixToPrefix(string str){
  reverse(str.begin(), str.end());
  int len = str.length();
  for(int i=0; i<len; i++){
    if(str[i]=='(') str[i] = ')';
    if(str[i]==')') str[i] = '(';
  }
  str = infixToPostfix(str);
  reverse(str.begin(), str.end());
  return str;
}




int main(){
  cout << infixToPrefix("a*b+c/d") << endl;
  return 0;
}
