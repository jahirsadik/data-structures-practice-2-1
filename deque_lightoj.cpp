// Learn deque from cpp reference


#include<bits/stdc++.h>
using namespace std;

int main(){
  int i = 1, t, n, m;
  for(scanf("%d",&t); i<=t; i++){
    printf("Case %d:\n",i);
    scanf("%d %d",&n, &m);
    deque <int> deq;
    string str;
    int temp;
    while(m--){
      cin >> str;
      if(str == "pushLeft"){
        scanf("%d",&temp);
        if(deq.size()==n) {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            deq.push_front(temp);
            printf("Pushed in left: %d\n",temp);
        }
      }
      else if(str=="pushRight"){
        scanf("%d",&temp);
        if(deq.size()==n) {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            deq.push_back(temp);
            printf("Pushed in right: %d\n",temp);
        }
      }
      else if(str=="popLeft"){
        if(deq.empty())
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            printf("Popped from left: %d\n",deq.front());
            deq.pop_front();
        }
      }
      else if(str=="popRight"){
        if(deq.empty())
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            printf("Popped from right: %d\n",deq.back());
            deq.pop_back();
        }
      }

    }

  }

  return 0;
}
