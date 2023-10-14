#include<bits/stdc++.h>
using namespace std;

void next_greatest(int next[], int arr[], int n) {
  stack<int> st;
  st.push(0);
  for(int i=1; i<n; i++) {
    while(!st.empty()){
      int cur = st.top();
      if(arr[cur] < arr[i]){
        next[cur] = i;
        st.pop();
      }
      else break;
    }
    st.push(i);
  }
  while(!st.empty()){
    int cur = st.top();
    next[cur] = -1;
    st.pop();
  }
}

int answer_query(int a[], int next[],	int n, int index) {
	int position = next[index];
	if (position == -1)
		return -1;
	else
		return a[position];
}

int main()
{
	int a[] = {3, 4, 2, 7, 5, 8, 10, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	int next[n] = { 0 };
	next_greatest(next, a, n);
	cout << answer_query(a, next, n, 3) << " ";
	cout << answer_query(a, next, n, 6) << " ";
	cout << answer_query(a, next, n, 1) << " ";
  return 0;
}
