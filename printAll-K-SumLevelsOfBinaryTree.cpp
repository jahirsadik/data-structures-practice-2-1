#include<bits/stdc++.h>
using namespace std;

struct node{
  node *left, *right;
  int data;

  node(int _data){
    data = _data;
    left = NULL;
    right = NULL;
  }
};

node* newNode(int _data){
  node* temp = new node(_data);
  return temp;
}

void display(bool ans, vector<int> &levelData){
  if(!ans) cout << "NO MATCH!\n";
  else{
    for(auto i: levelData) cout << i << endl;
  }
}

void sumLevelOrder(node* root, int k){
  if(root == NULL) return;
  queue<node*> q;
  vector<int> levelData;
  q.push(root);
  bool flag = false;

  while(!q.empty()){
    int nodeCount = q.size();
    int sumTemp = 0;
    while(nodeCount>0){
      node* temp = q.front();
      sumTemp += temp->data;
      levelData.push_back(temp->data);
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
      q.pop();
      nodeCount--;
    }

    if(sumTemp == k){
      flag = true;
      break;
    }
    levelData.clear();
  }
  display(flag, levelData);
}


int main(){
  node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(6);
  int k = 9;
  sumLevelOrder(root, k);
  return 0;
}
