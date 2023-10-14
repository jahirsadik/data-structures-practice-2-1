#include<bits/stdc++.h>
using namespace std;



void heapifyBottomUp(int arr[], int n, int i){
  int parent = (i-1)/2;
  if(arr[parent]>0 && arr[i] > arr[parent]){
    swap(arr[i], arr[parent]);
    heapifyBottomUp(arr, n, parent);
  }
}

void heapifyTopDown(int arr[], int n, int i){
  int largest = i;
  int l = (2*i) + 1;
  int r = (2*i) + 2;
  if(l<n && arr[l] > arr[largest]) largest = l;
  if(r<n && arr[r] > arr[largest]) largest = r;
  if(largest != i){
    swap(arr[i], arr[largest]);
    heapifyTopDown(arr, n, largest);
  }
}

void insertToHeap(int arr[], int& n, int _data){
  n++;
  arr[n-1] = _data;
  heapifyBottomUp(arr, n, n-1);
}

void deleteRoot(int arr[], int&n){
  if(n>0){
    int lastElement = arr[n-1];
    arr[0] = lastElement;
    n--;
    heapifyTopDown(arr, n, 0);
  }
}

void heapSort(int arr[], int n){
  for(int i=n/2-1; i>=0; i--) heapifyTopDown(arr, n, i);

  //for(int i=0; i<n ; i++) heapifyBottomUp(arr,n, i);
// important to remember while heepifying is
// don't change the same thing twice. so go
// topDown n/2 to 0 or bottomup n/2 to n

  for(int i=n-1; i>0; i--){
    swap(arr[0], arr[i]);
    heapifyTopDown(arr, i, 0);
  }
}


int main(){
  int arr[1000] = {2, 3, 4, 6, 1 ,15, 12};
  int n = 7;

  printf("Initial array.\n");
  for(int i=0; i<n;i++) printf("%d ", arr[i]);
  printf("      . Value of n: %d\n", n);
  insertToHeap(arr, n, 100);

  printf("Inserted array.\n");
  for(int i=0; i<n;i++) printf("%d ", arr[i]);
  printf("      . Value of n: %d\n", n);

  //for(int i=n/2-1; i>0; i--) heapifyTopDown(arr, n, i);
  //for(int i = n/2-1; i<n; i++) heapifyBottomUp(arr, n, i);
  heapSort(arr, n);
  printf("Final array.\n");
  for(int i=0; i<n;i++) printf("%d ", arr[i]);
  printf("      . Value of n: %d\n", n);
  return 0;
}
