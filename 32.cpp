#include<bits/stdc++.h>
using namespace std;

// node structure

struct node {
  int data;
  node *next;
  node(int new_data) {
      data = new_data;
      next = NULL;
  }
};


// LinkedList structure

struct linkedList {
  node *head;

  linkedList() {
    head = NULL;
  }


// ASSIGNMENT PART 1.
// INSERTS value K after every encountered X

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

// ASSIGNMENT PART 2
// DELETES value K if the previous value is X

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


// ASSIGNMENT PART 3
// Checks if a linked list is palindrome

  bool isPalindrome(){
    struct linkedList  tempList;
    tempList.head = copyListReturnHead();
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

// This isn't part of the assignment
// The given data will be appended to the linked list

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


// This isn't part of the assignment
// The given data will be prepended to the linked list

  void prepend(int new_data) {
    node *new_node = new node(new_data);
    new_node->next = head;
    head = new_node;
  }

// This isn't part of the assignment
// DELETES EVERY ENCOUNTERED argument value

  void deleteCertainValue(int itemToDelete){
    if(head == NULL){
       return;
    }
    while(head->data == itemToDelete){
      head = head->next;
    }

    node *current_node = head;
    if(!current_node->next) return;
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

// This isn't part of the assignment
// REVERSES A LINKED LIST


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


// This isn't part of the assignment
/* THIS FUNCTION MAKES A NEW LIST WHICH IS SAME AS THE GIVEN LIST AND RETURNS
 * THE HEAD NODE OF THE NEW LIST
*/

  node* copyListReturnHead(){
    node *mainListCurrent = head, *tempListCurrent = new node(head->data);
    node *dhuru = tempListCurrent;
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
    return dhuru;
  }




  node* tempCopyListReturnHead(){
    node *mainListCur = head;
    if(!head)  return NULL;
    node *tempListCur = new node(head->data);
    node *finalHead = tempListCur;
    while(mainListCur->next != NULL){
      node *new_node = new node(mainListCur->next->data);
      tempListCur->next = new_node;
      mainListCur = mainListCur->next;
      tempListCur = tempListCur->next;
      printf("%d %p\n", tempListCur->data, tempListCur->next);
    }
    return finalHead;
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

  struct linkedList ll2;
  ll2.head = ll.tempCopyListReturnHead();
  ll.printList();
  ll2.printList();


  return 0;
}
