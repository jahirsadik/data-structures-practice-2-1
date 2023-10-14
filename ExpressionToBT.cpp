#include<bits/stdc++.h>
using namespace std;


struct node{
  char data;
  node* leftChild;
  node* rightChild;

  node(char _data){
    data = _data;
    leftChild = NULL;
    rightChild = NULL;
  }
};


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

node* postfixToBT(string input){
  int len = input.length();
  stack<node*> stck;
  for(int i=0; i<len; i++){
    if(isOperand(input[i])){
      node *temp = new node(input[i]);
      stck.push(temp);
      continue;
    }

    else if(isOperator(input[i])){
      node *temp = new node(input[i]);
      temp->rightChild = stck.top();
      stck.pop();
      temp->leftChild = stck.top();
      stck.pop();
      stck.push(temp);
    //  printf("%c %c %c\n", temp->data, temp->leftChild->data, temp->rightChild->data);
    }
  }
  return stck.top();
}

void inorderTraversalMain(node* cur){
  if(!cur) return;
  inorderTraversalMain(cur->leftChild);
  printf("%c ", cur->data);
  inorderTraversalMain(cur->rightChild);
}
//asjkh
double evaluationOfBT(node* cur){
  double answer;

  if((!cur->rightChild)&&(!cur->leftChild)){
    answer =  ((double)cur->data) - 48.0;
    printf("Pailam leaf %d\n", answer);
    return answer;
  }

  double leftAns = evaluationOfBT(cur->leftChild);
  double rightAns = evaluationOfBT(cur->rightChild);
  printf("%d %c %d\n", leftAns, cur->data, rightAns);
  answer = performOperationOn(leftAns, rightAns, cur->data);
  return answer;
}

int main(){
  string input;
  getline(cin, input);
  input = infixToPostfix(input);
  node* head = postfixToBT(input);
//  inorderTraversalMain(head);
  cout << evaluationOfBT(head) << endl;

  return 0;
}
