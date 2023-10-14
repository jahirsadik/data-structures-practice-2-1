// use two queues for left and right


#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  int l,m;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d", &l, &m);
    int leftNaki = 0, timeCount = 0;
    l *= 100;
    queue<int> left, right;
    int len;
    char str[50];
    while(m--){
      scanf("%d %s", &len, str);
      if(str[0]=='l') left.push(len);
      else right.push(len);
    }


    while(!left.empty() || !right.empty()) {
      int totalLen = 0;
      timeCount++;
      if(!leftNaki){
        while(!left.empty()){
          if(totalLen + left.front() > l) break;
          totalLen += left.front();
          left.pop();
        }
      }
      else{
        while(!right.empty()){
          if(totalLen + right.front() > l) break;
          totalLen += right.front();
          right.pop();
        }
      }
      if(!leftNaki) leftNaki = 1;
      else leftNaki = 0;

    }
    printf("%d\n", timeCount);
  }
  return 0;
}
