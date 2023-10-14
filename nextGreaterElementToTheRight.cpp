#include<bits/stdc++.h>
using namespace std;

void nextGreaterElement(int arr[], int next[], int n){
  stack<int> stck;
  stck.push(0);
  for(int i=1; i<n; i++){
      if(arr[stck.top()] < arr[i]){
        while( (!stck.empty()) && (arr[stck.top()] < arr[i]) ){
          next[stck.top()] = i;
          stck.pop();
        }
      }
      stck.push(i);
  }

  while(!stck.empty()){
    next[stck.top()] = -1;
    stck.pop();
  }
  for(int i=0; i<n; i++) cout << next[i] << " ";
  cout << endl;
}

int main()
{
    int a[] = { 3, 4, 2, 7, 5, 8, 10, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    int next[n];
    nextGreaterElement(a,next,n);
    return 0;
}
