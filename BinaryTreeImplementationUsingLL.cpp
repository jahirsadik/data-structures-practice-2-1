#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* leftChild;
  node* rightChild;

  node(int _data){
    data = _data;
    leftChild = NULL;
    rightChild = NULL;
  }
};

struct bst{
  node* root;

  bst(){
    root = NULL;
  }

  bst(node* _root){
    root = _root;
  }

  void insert(int _data){
    node* cur = root;
    insertnode(cur, _data);
  }

  void searchValue(int _data){
    node* cur = root;
    cur = searchValueMain(cur, _data);
    if(!cur) printf("Not found\n");
    else printf("Value: %d,Found! In node %p.\n", cur);
  }

  void inorderTraversal() {
    printf("Inorder Traversal:\n");
    node* cur = root;
    inorderTraversalMain(cur);
    printf("\n");
  }

  void preorderTraversal() {
    printf("Preorder Traversal:\n");
    node* cur = root;
    preorderTraversalMain(cur);
    printf("\n");
  }

  void postorderTraversal(){
    printf("Postorder Traversal:\n");
    node* cur = root;
    postorderTraversalMain(cur);
    printf("\n");
  }

  int upperbound(int _data){
    node* cur = root;
    cur = upperboundNode(cur, _data);
    if(!cur) return -1;
    else return cur->data;
  }

  int lowerbound(int _data){
    node* cur = root;
    cur = lowerboundNode(cur, _data);
    if(!cur) return -1;
    else return cur->data;
  }

  void deleteValue(int _data){
    root = deletenode(root, _data);
  }

  int findMin(){
    if(!root){
      printf("Root is null\n");
      return -1;
    }
    return (*findMinNode(root)).data;
  }

  int findMax(){
    if(!root){
      printf("Root is null\n");
      return -1;
    }
    return (*findMaxNode(root)).data;
  }

  int findHeight(){
    node* cur = root;
    return findHeightOfNode(cur);
  }


private:
  node* searchValueMain(node* cur, int _data){
    if(!cur) return NULL;
    if(cur->data == _data) return cur;
    else if(cur->data > _data) return searchValueMain(cur->leftChild, _data);
    else return searchValueMain(cur->rightChild, _data);
  }

  void insertnode(node* cur, int _data){
    if(!cur){
      root = new node(_data);
      return;
    }
    if(_data <= cur->data){
      if(!cur->leftChild){
        cur->leftChild = new node(_data);
        return;
      }
      insertnode(cur->leftChild, _data);
    }
    else{
        if(!cur->rightChild){
          cur->rightChild = new node(_data);
          return;
        }
          insertnode(cur->rightChild, _data);
      }
  }

  void inorderTraversalMain(node* cur){
    if(!cur) return;
    inorderTraversalMain(cur->leftChild);
    printf("%d ", cur->data);
    inorderTraversalMain(cur->rightChild);
  }

  void preorderTraversalMain(node* cur){
    if(!cur) return;
    printf("%d ", cur->data);
    preorderTraversalMain(cur->leftChild);
    preorderTraversalMain(cur->rightChild);
  }

  void postorderTraversalMain(node* cur){
    if(!cur) return;
    postorderTraversalMain(cur->leftChild);
    postorderTraversalMain(cur->rightChild);
    printf("%d ", cur->data);
  }

  node* upperboundNode(node* cur, int _data){
    if(cur->data <= _data && !cur->rightChild) return NULL;
    else if(cur->data <= _data && cur->rightChild) return upperboundNode(cur->rightChild, _data);
    else if(cur->data > _data && !cur->leftChild) return cur;
    return upperboundNode(cur->leftChild, _data);
  }

  node* lowerboundNode(node* cur, int _data){
    if(cur->data >= _data && !cur->leftChild) return cur;
    else if(cur->data >= _data && cur->leftChild){
      if(cur->leftChild->data < _data) return cur;
      else return lowerboundNode(cur->leftChild, _data);
    }
    else if(cur->data < _data && !cur->rightChild) return NULL;
    else return lowerboundNode(cur->rightChild, _data);
  }

  node* deletenode(node* cur, int _data){
    if(!cur) return cur;
    else if(_data < cur->data) cur->leftChild = deletenode(cur->leftChild, _data);
    else if(_data > cur->data) cur->rightChild = deletenode(cur->rightChild, _data);
    else {
      if(!cur->leftChild && !cur->rightChild){
        free(cur);
        cur = NULL;
      }
      else if(!cur->leftChild){
        node* temp = cur;
        cur = cur->rightChild;
        free(temp);
      }
      else if(!cur->rightChild){
        node* temp = cur;
        cur = cur->leftChild;
        free(temp);
      }
      else{
        node* temp = upperboundNode(cur, _data);
        cur->data = temp->data;
        cur->rightChild = deletenode(cur->rightChild, temp->data);
      }
    }
    return cur;
  }

  node* findMinNode(node* cur){
    if(!cur->leftChild) return cur;
    return findMinNode(cur->leftChild);
  }

  node* findMaxNode(node* cur){
    if(!cur->rightChild) return cur;
    return findMaxNode(cur->rightChild);
  }

};

int main(){
  bst demoBst;
  vector<int> vec{20, 10, 26, 8, 12};
  for(auto i = vec.begin(); i!=vec.end(); i++) demoBst.insert(*i);

  demoBst.inorderTraversal();
  // demoBst.deleteValue(13);
  // demoBst.inorderTraversal();
  // demoBst.preorderTraversal();
  // demoBst.postorderTraversal();
  printf("%d\n", demoBst.upperbound(8));
//  cout <<"upperbound: "<< demoBst.lowerbound(2) << endl;;

  return 0;
}
