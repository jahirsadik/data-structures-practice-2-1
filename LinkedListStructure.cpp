#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
  node(int new_data){
      data = new_data;
  }
};

struct linkedList{
  node* head;

  linkedList(){
    head = NULL;
  }

  void append( int data ) {
    node *current_node = head;
    if( head == NULL ){
      head = new node(data);
      return;
    }
    while(current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node-> = new node(data);
  }
  void prepend( int data ){
    node *new_head = new node(data);
    new_head->next = head;
    head = new_head;
  }

  void deleteCertainValue(int item){
    if(head == NULL) return;
    while(head->data == item){     /// if chilo while disi
      head = head->next;
    }
    node *current_node = head;
    while( current_node->next != NULL) {
      if(current_node->next->data == item){
        current_node->next = current_node->next->next;
      }
      current_node = current_node->next;
    }
  }


};
