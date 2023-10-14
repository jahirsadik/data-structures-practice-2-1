// Implementation no 1.

bool isBinarySearchTreeMain(node* cur){
  if(!cur){
    printf("Aschi\n");
    return true;
  }
  int maxLeft;
  if(findMaxNode(cur->leftChild)) maxLeft = findMaxNode(cur->leftChild)->data;
  else maxLeft = -11;
  int minRight;
  if(findMinNode(cur->rightChild)) minRight = findMinNode(cur->rightChild)->data;
  else minRight = 111;
  if((maxLeft<= cur->data)&&(minRight>cur->data)
    &&(isBinarySearchTreeMain(cur->leftChild))&&(isBinarySearchTreeMain(cur->rightChild)) ) return true;
  else return false;
}


// Implementation no 2

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

bool isBinarySearchTreeMain(node* cur){
  if(!cur) return true;
  if((isSubtreeLesser(cur->leftChild, cur->data))&&(isSubtreeGreater(cur->rightChild, cur->data))
    &&(isBinarySearchTreeMain(cur->leftChild))&&(isBinarySearchTreeMain(cur->rightChild)) ) return true;
  else return false;
}
