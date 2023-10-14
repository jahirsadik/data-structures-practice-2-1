#include<bits/stdc++.h>
using namespace std;

void nextGreatestFrequencyElement(int arr[], int n, int frequencies[]){
	stack<int> stck;
	int res[n] = {0};
	stck.push(0);
	for(int i=1; i<n; i++){
		if(frequencies[arr[stck.top()]] > frequencies[arr[i]] ) stck.push(i);
		else{
			while( (!stck.empty()) && (frequencies[arr[stck.top()]] < frequencies[arr[i]]) ){
				res[stck.top()] = arr[i];
				stck.pop();
			}
			stck.push(i);
		}
	}
	while(!stck.empty()){
		res[stck.top()] = -1;
		stck.pop();
	}
	for (int i = 0; i < n; i++)	{
		cout << res[i] << " ";
	}
}



int main(){
	int a[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
	int len = sizeof(a)/sizeof(a[0]);
	int max = -INT16_MAX;

	for (int i = 0; i < len; i++){
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int freq[max + 1] = {0};

	for (int i = 0; i < len; i++){
		freq[a[i]]++;
	}
	nextGreatestFrequencyElement(a, len, freq);

	return 0;
}
