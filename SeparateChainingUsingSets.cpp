#include<bits/stdc++.h>
using namespace std;

int strSum(string str){
  int len = str.length();
  int sum = 0;
  while(len!= -1){
    sum += str[len--];
  }
  return sum;
}

int main(){
  pair<string, int> p[7];
  p[0] = {"Tahmid", 1};
  p[1] = {"Monon" , 2};
  p[2] = {"Mico" , 3};
  p[3] = {"Foysal" , 4};
  p[4] = {"Mridul" , 5};
  p[5] = {"Fawwaz" , 6};
  p[6] = {"Adnan" , 7};

  set<pair<string, int>> st[5];

  for(auto i: p){
    int hashValue = (strSum(i.first)) % 5;
    cout << i.first << " " << hashValue << endl;
    st[hashValue].insert(make_pair(i.first, i.second));
  }

  while(true){
    string str;
    int opt;
    scanf("%d\n", &opt);
    getline(cin, str);
    int hashValue = (strSum(str)) % 5;
    if(opt == 2){   // removal operation
      for(auto i: st[hashValue]){
        if(i.first == str){
          st[hashValue].erase(make_pair(i.first, i.second));
          break;
        }
      }
    }

    else if(opt == 1){  // find operation
      bool found = false;
      for(auto i: st[hashValue]){
        if(i.first == str){
          cout << i.first << " is " << i.second << "th. " << hashValue << endl;
          found = true;
          break;
        }
      }
      if(!found) printf("Not found\n");
    }

    else if(opt == 3){ // insert operation
      int position;
      scanf("%d ", &position);
      st[hashValue].insert(make_pair(str, position));
      printf("Inserted ");
      cout << str <<"!" << endl;
    }

    else break;
  }

  return 0;
}
