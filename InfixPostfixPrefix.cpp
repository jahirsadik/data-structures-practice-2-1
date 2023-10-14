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

double performOperationOn(double a, double b, char opt){
  if(opt == '+') return a+b;
  if(opt == '-') return a-b;
  if(opt == '*') return a*b;
  if(opt == '/'){
    if(b==0) return -189;
    else return a/b;
  }
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

double evaluatePostfix(string str){
  stack <double> operandStack;
  int len = str.length();

  for(int i=0; i<len; i++){

    if(isOperand(str[i])){
      operandStack.push(str[i]-'0');
    }

    else if(isOperator(str[i])){
      double secondOperand = operandStack.top();
      operandStack.pop();
      if(operandStack.empty() && str[i]=='-') {
        secondOperand *= -1;
        operandStack.push(secondOperand);
        continue;
      }
      if(operandStack.empty() && str[i]!= '-'){
        return -189;
      }

      double firstOperand = operandStack.top();
      operandStack.pop();

      double golPasa = performOperationOn(firstOperand, secondOperand, str[i]);
      if(golPasa == -189){
        return -189;
      }
      operandStack.push(golPasa);
    }
  }
  double ans = operandStack.top();
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



double evaluationPrefix(string str){
  int len = str.length();
  stack<int> operandStack;
  for(int i=len-1; i>=0; i--){

    if(isOperand(str[i])){
      operandStack.push(str[i]-'0');
    }
    else if(isOperator(str[i])){
      double firstOperand = operandStack.top();
      operandStack.pop();
      double secondOperand = operandStack.top();
      operandStack.pop();
      double golPasa = performOperationOn(firstOperand, secondOperand, str[i]);
      operandStack.push(golPasa);
    }
  }
  double ans = operandStack.top();
  operandStack.pop();
  return ans;
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

double infixEvaluation(string infixForm){
  return evaluatePostfix(infixToPostfix(infixForm));
}


int main(){
  string bal;
  getline(cin, bal);
  cout << infixToPrefix(bal) << endl;
  return 0;
}
