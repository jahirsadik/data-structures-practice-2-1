#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int low, int high, int n){
  int mid = (low+high)/2;
  if((mid==0 || arr[mid-1]<=arr[mid]) && (arr[mid+1]<=arr[mid] || mid ==n-1)) return mid;
  if(mid-1>=0 && arr[mid-1]>arr[mid]) return findPeak(arr, low, mid-1, n);
  return findPeak(arr, mid+1, high, n);
}

int main(){
  int arr[] = {8,9,10,2,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("%d\n", arr[findPeak(arr,0,n-1,n)]);

  return 0;
}
