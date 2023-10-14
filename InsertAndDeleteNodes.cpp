#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

node *createNodeReturnAddress(int new_data, node *nextAddress);
void pushFirstSendPointer(node **headRef, int new_data);
node *pushFirstReturnNode(node *head, int new_data);
void pushAfter(node *previous, int new_data);
node *appendAndReturnAddress(node *head, int new_data);

void deleteLast(node *headRef);
void deleteMiddle(node *headRef, int deleteData);
node *removeNode(node *head, node *toDelete)




void pushFirstSendPointer(node **headRef, int new_data){
  node *new_node = new node();
  new_node->data = new_data;
  new_node->next = *headRef;
  *headRef = new_node;
}

node *pushFirstReturnNode(node *head, int new_data){
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
}



void pushAfter(node *previous, int new_data) {
  if(!previous) {
    printf("previous node cannot be null\n");
    return;
  }

  node *new_node = new node();
  new_node->data = new_data;
  new_node->next = previous->next;
  previous->next = new_node;
}

void append(node **headRef, int new_data) {
  node *new_node = new node();
  node *last = *headRef;
  new_node->data = new_data;
  if( *headRef == NULL ) {
    *headRef = new_node;
    return;
  }
  while(last->next != NULL) last = last->next;
  last->next = new_node;
}


node *appendAndReturnAddress(node *head, int new_data){
  node *new_node = new node();
  new_node = createNodeReturnAddress(new_data, NULL);
  if(head == NULL){
    return new_node;
  }
  node *current_node = new node();
  current_node = head;
  while(current_node->next != NULL) current_node = current_node->next;
  current_node->next = new_node;
  return head;
}



void deleteLast(node *headRef){
  if(headRef == NULL){
    printf("Can't delete, it's already NULL\n");
    return;
  }
  if(headRef->next == NULL){
    headRef = NULL;
    return;
  }

  while(headRef->next->next != NULL) headRef = headRef->next;
  node *temp = headRef->next;
  headRef->next = NULL;
  free(temp);
}


void deleteMiddle(node *headRef, int deleteData){
  if(headRef == NULL){
    printf("Can't delete, it's already NULL\n");
    return;
  }

  if(headRef->next == NULL){
    if(headRef->data == deleteData) headRef = NULL;
    return;
  }

  if(headRef->data == deleteData){
    printf("It's the first data so it can't be deleted by this function\n");
  }

  while( (headRef->next->next != NULL) && (headRef->next->data != deleteData) ){
    headRef = headRef->next;
  }
  if(headRef->next->data == deleteData){
    node *temp = headRef->next;
    headRef->next = headRef->next->next;
    free(temp);
  }

  return;
}


node *createNodeReturnAddress(int new_data, node *nextAddress){
  node *new_node = new node();
  if(new_node == NULL){
    printf("Node couldn't be created\n");
    exit(1);
  }
  new_node->data = new_data;
  new_node->next = nextAddress;
  return new_node;
}


node *removeNode(node *head, node *toDelete){
  node *current_node = head;

  if(head == toDelete){
    head = head->next;
    free(toDelete);
    return head;
  }

  while(current_node != NULL){
    if(current_node->next == toDelete) break;
    current_node = current_node->next;
  }

  if(current_node == NULL) return head;

  current_node->next = toDelete->next;
  free(toDelete);
  return head;
}



int main() {
  struct node *head = NULL, *second = NULL, *third = NULL ;
  head = new node();
  second = new node();
  third = new node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  third = createNodeReturnAddress(3, NULL);
  second = createNodeReturnAddress(2, third);
  head = createNodeReturnAddress(1, second);

  node *temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now insert a node at first\n");

  pushFirstSendPointer(&head, 0);

  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now push 99 after second node 2\n");
  pushAfter(second, 99);


  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }


  printf("Now push -1 after last node\n");
  pushAfter(third, -1);


  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now append after last node without passing last node directly\n");
  append(&head, 75);


  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now delete last node\n");
  deleteLast(head);
  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }


  printf("Now delete 0 node\n");
  deleteMiddle(head, 0);
  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now delete 2 node\n");
  deleteMiddle(head, 2);
  temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }


  return 0;
}
