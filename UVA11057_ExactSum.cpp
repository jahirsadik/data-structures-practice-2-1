#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string str;
  while(scanf("%d",&n)!=EOF){
    vector<int> vec;
    int sum;
    for(int i=0; i<n;i++){
      int bal;
      scanf("%d",&bal);
      vec.push_back(bal);
    }
    scanf("%d",&sum);
    getline(cin,str);
    sort(vec.begin(),vec.end());
    int i=0, j=n-1, left, right;
    while(i<j){
      if((vec[i]+vec[j])>sum) j--;
      else if((vec[i]+vec[j])<sum) i++;
      else if((vec[i]+vec[j])==sum){
        left = i;
        right = j;
        i++;
        j--;
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n",vec[left],vec[right]);
    printf("\n");
  }

  return 0;
}
