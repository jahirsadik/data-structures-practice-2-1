#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  node *next;
  node(int new_data) {
      data = new_data;
  }
};

struct linkedList {
  node *head;

  linkedList() {
    head = NULL;
  }

// The given data will be appended to the linked list
// This isn't part of the assignment
  void append(int new_data) {
    node *current_node = head;
    if(head == NULL){
      head = new node(new_data);
      head->next = NULL;
      return;
    }

    while(current_node->next != NULL) current_node = current_node->next;

    current_node->next = new node(new_data);
    current_node->next->next = NULL;
  }

// The given data will be prepended to the linked list
// This isn't part of the assignment
  void prepend(int new_data) {
    node *new_node = new node(new_data);
    new_node->next = head;
    head = new_node;
  }


  // void deleteCertainValue(int itemToDelete){
  //   if(head == NULL){
  //      return;
  //   }
  //   while(head->data == itemToDelete){
  //     head = head->next;
  //   }
  //
  //   node *current_node = head;
  //   while(current_node->next != NULL){
  //     if(current_node->next->data == itemToDelete){
  //       printf("Case matched where current_node is %d, next node is %d\n", current_node->data, current_node->next->data);
  //       current_node->next = current_node->next->next;
  //     }
  //     if(current_node!=NULL)current_node = current_node->next;
  //   }
  // }

  void deleteCertainValue(int itemToDelete){
    if(head == NULL){
       return;
    }
    while(head->data == itemToDelete){
      head = head->next;
    }

    node *current_node = head;
    while(current_node->next->next != NULL){
      if(current_node->next->data == itemToDelete){
        node *temp = current_node->next;
        current_node->next = current_node->next->next;
        free(temp);
      }
      current_node = current_node->next;
      if(current_node->next == NULL) return;
    }
    if(current_node->next->next == NULL && current_node->next->data == itemToDelete){
      node *temp = current_node->next;
      current_node->next = NULL;
      free(temp);
    }

  }

  void insertAfterValue(int k, int x) {
    if(head == NULL) return;
    node *current_node = head;
    while(current_node->next != NULL){
      if(current_node->data == x){
        node *new_node = new node(k);
        new_node->next = current_node->next;
        current_node->next = new_node;
      }
      current_node = current_node->next;
    }

    if(current_node->next == NULL && current_node->data == x){
      node *new_node = new node(k);
      current_node->next = new_node;
      new_node->next = NULL;
    }
  }

  void deleteWithValue(int k, int x){
    if(head == NULL || head->next == NULL) return;

    node *current_node = head;
    while(current_node->next->next != NULL){
      if(current_node->data == x && current_node->next->data == k){
        node *temp = current_node->next;
        current_node->next = current_node->next->next;
        free(temp);
      }
      current_node = current_node->next;
      if(current_node->next == NULL) return;
    }
    if(current_node->next->next == NULL && current_node->data == x && current_node->next->data == k){
      node *temp = current_node->next;
      current_node->next = NULL;
      free(temp);
    }
  }

  void reverseList(){
    node *current_node = head;
    node *previous = NULL, *next = NULL;
    while(current_node!=NULL){
      next = current_node->next;
      current_node->next = previous;
      previous = current_node;
      current_node = next;
    }
    head = previous;
  }

  void printList(){
    if(head == NULL) printf("Head is still null\n");
    node *current_node = head;
    while(current_node != NULL){
      printf("%d", current_node->data);
      if(current_node->next != NULL) printf(" ");
      current_node = current_node->next;
    }
    printf("\n");
  }

  bool isPalindrome(){
    struct linkedList  tempList;
    node *mainListCurrent = head, *tempListCurrent = new node(head->data);
    tempList.head = tempListCurrent;
    mainListCurrent = mainListCurrent->next;
    while(mainListCurrent->next != NULL){
      node *new_node = new node(mainListCurrent->data);
      tempListCurrent->next = new_node;
      tempListCurrent = tempListCurrent->next;
      mainListCurrent = mainListCurrent->next;
    }
    node *new_nodeeee = new node(mainListCurrent->data);
    tempListCurrent->next = new_nodeeee;
    tempListCurrent = tempListCurrent->next;
    tempListCurrent->next = NULL;
    tempList.reverseList();
    bool ans = true;
    node *temp_a, *temp_b;
    for(temp_a = head, temp_b = tempList.head; temp_a ; temp_a = temp_a->next, temp_b = temp_b->next){
      if(temp_a->data != temp_b->data){
        ans = false;
        break;
      };
    }

    struct linkedList *tempListPointer = &tempList;
    free(tempListPointer);
    return ans;
  }

};


int main(){
  struct linkedList ll;
  ll.append(1);
  ll.append(0);
  ll.append(1);
  printf("The given linked list is:\n");
  ll.printList();

//THIS IS AN EXAMPLE OF THE FIRST function
  printf("Insert 2 after every encountered 1\n");
  ll.insertAfterValue(2,1);
  ll.printList();

//THIS IS AN EXAMPLE OF THE SECOND function
  printf("Delete 1 after every encountered 0\n");
  ll.deleteWithValue(1,0);
  ll.printList();

//THIS IS AN EXAMPLE OF THE THIRD function
  if(ll.isPalindrome()) printf("The given Linked List is a palindrome\n");
  else printf("The given Linked List is NOT a palindrome\n");

// DELETING 0 And ADDING 1 to make it palindrome
  printf("Delete value 0 and append 1\n" );
  ll.deleteCertainValue(0);
  ll.append(1);
  ll.printList();


//THIS IS ANOTHER EXAMPLE OF THE THIRD function
  if(ll.isPalindrome()) printf("The given Linked List is now a palindrome\n");
  else printf("The given Linked List is NOT a palindrome\n");



  return 0;
}
