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
  cout << "Next highest: ";
  for(int i=0; i<n; i++) cout << arr[next[i]] << " ";
  cout << endl;
}

void numberOfNextGreaterElement(int arr[], int ans[], int n){
  int next[n];
  memset(next, 0, sizeof(next));
  nextGreaterElement(arr, next, n);
  ans[n-1] = 0;
  for(int i=n-2; i>=0; i--){
    if(next[i] == -1) ans[i] = 0;
    else ans[i] = 1 + ans[next[i]];
  }
}


int main()
{
    int arr[] = { 3, 4, 2, 7, 5, 8, 10, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int next[n], ans[n];

    cout << "MAIN ARRAY: " ;
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    numberOfNextGreaterElement(arr, ans, n);

    cout << "Number of nge: " ;
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
