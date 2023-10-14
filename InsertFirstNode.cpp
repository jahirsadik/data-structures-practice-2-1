#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};


void pushFirst(node **headRef, int new_data){
  node *new_node = new node();
  new_node->data = new_data;
  new_node->next = *headRef;
  *headRef = new_node;
}

void pushAfter(node *previous, int new_data){
  if(!previous){
    printf("previous node cannot be null\n");
    return;
  }
  node *new_node = new node();
  new_node->data = new_data;
  new_node->next = previous->next;
  previous->next = new_node;
}




int main(){
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

  node *temp = head;
  while(temp) {
    printf("address: %p, data: %d\n", temp, temp->data);
    temp = temp->next;
  }

  printf("Now insert a node at first\n");

  pushFirst(&head,0);

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


  return 0;
}
