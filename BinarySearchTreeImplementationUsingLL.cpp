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
  node* ub = NULL;
  node* lb = NULL;
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

  int newUpperBound(int value){
    newUpperBoundRec(root, value);
    if(!ub) return -1;
    return ub->data;
  }

    int newLowerBound(int value){
    newLowerBoundRec(root, value);
    if(!lb) return 100000;
    return lb->data;
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

  void levelOrderTraversal(){
    node* cur = root;
    printf("Level Order Traversal: ");
    levelOrderTraversalMain(cur);
    printf("\n");
  }

  node* copyBST(){
    printf("Copying bst.\n");
    return copyBSTmain(root);
  }

  void isBinarySearchTree(){
    if(isBinarySearchTreeMain(root, INT_MIN, INT_MAX)) printf("Yes, it's a binary search tree\n");
    else printf("No, it's not a binary search tree\n");
  }

  int getSuccessor(int _data){
    node* temp = getSuccessorNode(root, _data);
    if(temp) return (*temp).data;
    else return -1;
  }

  int getPredecessor(int _data){
    node* temp = getPredecessorNode(root, _data);
    if(temp) return (*temp).data;
    else return -1;
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

  void levelOrderTraversalMain(node* cur){
    if(!cur) return;
    queue<node*> q;
    q.push(cur);
    while(!q.empty()){
      node* current = q.front();
      printf("%d ", current->data);
      if(current->leftChild) q.push(current->leftChild);
      if(current->rightChild) q.push(current->rightChild);
      q.pop();
    }
  }

  node* upperboundNode(node* cur, int _data){
    if(cur->data <= _data && !cur->rightChild) 
        return NULL;
    else if(cur->data <= _data && cur->rightChild) 
        return upperboundNode(cur->rightChild, _data);
    else if(cur->data > _data && !cur->leftChild) 
        return cur;
    return upperboundNode(cur->leftChild, _data);
  }

  node* lowerboundNode(node* cur, int _data){
    if(cur->data >= _data && !cur->leftChild) 
        return cur;
    else if(cur->data >= _data && cur->leftChild){
      if(cur->leftChild->data < _data) return cur;
      else 
          return lowerboundNode(cur->leftChild, _data);
    }
    else if(cur->data < _data && !cur->rightChild) 
        return NULL;
    else return lowerboundNode(cur->rightChild, _data);
  }

  node* deletenode(node* cur, int _data){
    if(!cur) return cur;
    else if(_data < cur->data) 
        cur->leftChild = deletenode(cur->leftChild, _data);
    else if(_data > cur->data) 
        cur->rightChild = deletenode(cur->rightChild, _data);
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
    if(!cur) return NULL;
    if(!cur->leftChild) return cur;
    return findMinNode(cur->leftChild);
  }

  node* findMaxNode(node* cur){
    if(!cur) return NULL;
    if(!cur->rightChild) return cur;
    return findMaxNode(cur->rightChild);
  }

  int findHeightOfNode(node* cur){
    if(!cur) return -1;
    int leftMaxHeight, rightMaxHeight;
    leftMaxHeight = findHeightOfNode(cur->leftChild);
    rightMaxHeight = findHeightOfNode(cur->rightChild);
    return (1 + max(leftMaxHeight,rightMaxHeight));
  }

  node* copyBSTmain(node* cur){
    if(!cur) return NULL;
    node* tempRoot = new node(cur->data);
    tempRoot->leftChild = copyBSTmain(cur->leftChild);
    tempRoot->rightChild = copyBSTmain(cur->rightChild);
    return tempRoot;
  }

  bool isSubtreeLesser(node* cur, int _data){
    if(!cur) return true;
    if(cur->data <= _data && isSubtreeLesser(cur->leftChild, _data)
      && isSubtreeLesser(cur->rightChild, _data)) return true;
    else return false;
  }

  bool isSubtreeGreater(node* cur, int _data){
    if(!cur) return true;
    if(cur->data > _data && isSubtreeGreater(cur->rightChild, _data)
      && isSubtreeGreater(cur->rightChild, _data)) return true;
    else return false;
  }

  bool isBinarySearchTreeCostly(node* cur){
    if(!cur) return true;
    if((isSubtreeLesser(cur->leftChild, cur->data))&&(isSubtreeGreater(cur->rightChild, cur->data))
      &&(isBinarySearchTreeCostly(cur->leftChild))&&(isBinarySearchTreeCostly(cur->rightChild)) ) return true;
    else return false;
  }

  bool isBinarySearchTreeMain(node* cur, int minVal, int maxVal){
    if(!cur) return true;
    if((cur->data > minVal) && (cur->data <= maxVal) &&
        isBinarySearchTreeMain(cur->leftChild, minVal, cur->data) &&
        isBinarySearchTreeMain(cur->rightChild, cur->data, maxVal))
        return true;
    else return false;
  }

  node* getSuccessorNode(node* cur, int _data){
    node* current = searchValueMain(root, _data);
    node* successor = NULL;
    if(!current) return successor;
    if(current->rightChild){
      return findMinNode(current->rightChild);
    }
    else{
      node* ancestor = root;
      while(ancestor!=current){
        if(current->data < ancestor->data){
          successor = ancestor;
          ancestor = ancestor->leftChild;
        }
        else ancestor = ancestor->rightChild;
      }
    }
    return successor;
  }

  node* getPredecessorNode(node* cur, int _data){
    node* current = searchValueMain(root, _data);
    node* predecessor = NULL;
    if(!current) return predecessor;
    if(current->leftChild){
      return findMaxNode(current->leftChild);
    }
    else{
        node* ancestor = root;
        while(ancestor!=current){
          if(ancestor->data < current->data){
            predecessor = ancestor;
            ancestor = ancestor->rightChild;
          }
          else ancestor = ancestor->leftChild;
        }
    }
    return predecessor;
  }

  void newUpperBoundRec(node *cur, int value){
    if(!cur) return;
    if(cur->data > value){
      ub = cur;
      newUpperBoundRec(cur->leftChild, value);
    }else{
      newUpperBoundRec(cur->rightChild, value);
    }
  }

  void newLowerBoundRec(node *cur, int value){
    if(!cur) return;
    if(cur->data >= value){
      lb = cur;
      newLowerBoundRec(cur->leftChild, value);
    }else{
      newLowerBoundRec(cur->rightChild, value);
    }
  }

};

//askjdhaskjh


int main(){
  bst demoBst;
  cout << "Simple BST Implementation" << endl;
  vector<int> vec{20, 10, 26, 8, 12};
  for(auto i = vec.begin(); i!=vec.end(); i++) demoBst.insert(*i);
  bst copiedBst = demoBst.copyBST();
  copiedBst.levelOrderTraversal();
  // demoBst.inorderTraversal();
  // demoBst.deleteValue(13);
  // copiedBst.inorderTraversal();
  // // demoBst.inorderTraversal();
  // // demoBst.preorderTraversal();
  // // demoBst.postorderTraversal();
  // // printf("Height: %d\n", demoBst.findHeight());
  // // demoBst.levelOrderTraversal();
  // copiedBst.isBinarySearchTree();
  // printf("P:%d\n",copiedBst.getPredecessor(12));
  // printf("S:%d\n", copiedBst.getSuccessor(33));
  printf("\tupperbound: %d\n", demoBst.newLowerBound(7));


//  cout <<"upperbound: "<< demoBst.lowerbound(2) << endl;;

  return 0;
}
