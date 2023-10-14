#include <bits/stdc++.h>
using namespace std;

void slidingWindowMax(int arr[], int n, int k)
{
	deque<int> dq;
	dq.push_back(0);
	for (int i=1; i < n; ++i) { // normal sliding windows
		if(i >= k) cout << arr[dq.front()] << " ";
		while ((!dq.empty()) && dq.front() <= i - k) dq.pop_front();
		while ((!dq.empty()) && arr[i] >= arr[dq.back()]) dq.pop_back();
		dq.push_back(i);
	}
	cout << arr[dq.front()];
}

int main()
{
	int arr[] = {8, 5, 10, 7, 9, 4, 2, 15, 12, 90, 13 }; // O: 10 10 10 9 15 15 90 90
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	slidingWindowMax(arr, n, k);
	return 0;
}
