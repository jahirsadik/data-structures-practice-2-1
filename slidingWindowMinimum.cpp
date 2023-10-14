#include<bits/stdc++.h>
using namespace std;

void slidingWindowMinimum(int arr[], int n, int k){
  deque<int> dq;

  for(int i=0; i<k; i++){
    while((!dq.empty())&&(arr[i] <= arr[dq.back()])) dq.pop_back();
    dq.push_back(i);
  }
  for(int i=k; i<n; i++){
    cout << arr[dq.front()] << " ";
    while((!dq.empty())&&(arr[i] <= arr[dq.back()])) dq.pop_back();
    while((!dq.empty())&&(dq.front() <= i - k)) dq.pop_front();
    dq.push_back(i);
  }
  cout << arr[dq.front()];
}

int main()
{
	int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
  for(int i=0; i<n; i++) cout << arr[i] << " ";
  cout << endl;
	slidingWindowMinimum(arr, n, k);
	return 0;
}
