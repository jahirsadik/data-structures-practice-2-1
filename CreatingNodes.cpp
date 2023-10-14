#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

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



  return 0;
}
