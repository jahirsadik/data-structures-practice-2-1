#include<bits/stdc++.h>
using namespace std;

#define DisjSet DisjointSet
class DisjointSet{
  int *rank, *parent, size, numberOfSets;
  map<string, int> mpKeyString;
  map<int, string> mpKeyIndex;

public:
  DisjointSet(vector<string> &vc){
    int _size = vc.size();
    rank = new int[_size];
    parent = new int[_size];
    this->size = _size;
    numberOfSets = _size;
    makeSet(vc);
  }

  void makeSet(vector<string> &vc){
    for(int i=0; i<size; i++){
      mpKeyString[vc[i]] = i;
      mpKeyIndex[i] = vc[i];
      parent[i] = -1;
      rank[i] = 0;
    }
  }

  int find(int data){
    if(parent[data] < 0) return data;

    int result = find(parent[data]); // for path compKeyStringression
    parent[data] = result;
    return result;
  }

  void Union(string a, string b){
    if( (mpKeyString.find(a) == mpKeyString.end()) || (mpKeyString.find(b) == mpKeyString.end())){
      printf("Member not in union!\n");
      return;
    }
    cout << a << " and " << b << " becomes friend" << endl;
    int x = mpKeyString[a];
    int y = mpKeyString[b];
    int xset = find(x);
    int yset = find(y);
    if(xset == yset) return;
    numberOfSets--;

    if(rank[xset] < rank[yset]){
      parent[yset]+=parent[xset];
      parent[xset] = yset;
    }
    else if(rank[yset] < rank[xset]) {
      parent[xset]+= parent[yset];
      parent[yset] = xset;
    }
    else{
      parent[xset]+= parent[yset];
      parent[yset] = xset;
      rank[xset]++;
    }
  }

  int getNumberOfSets(){
    return numberOfSets;
  }

  void printArrays(){
    for(int i=0; i<size ; i++){
      cout << "i:" << i << "   parent:" << parent[i] << " " << "   rank:" << rank[i] << endl;
    }
    cout << endl;
  }

  void setElementNumber(int _data){
    int x = find(_data);
    printf("%d\n",-parent[x]);
  }

  void showRelationShips(vector<string> &vc){
    for(int i=0; i<size ; i++){
      cout << "i:" << i << " Person Name: " << vc[i] << "   parent:" << parent[i] << " " << "   rank:" << rank[i] << endl;
    }
    cout << endl;
  }

  void numberOfFriends(string a){
    if(mpKeyString.find(a) == mpKeyString.end()) cout << "Member not in union!" << endl;
    else{
      int _data = mpKeyString[a];
      int x = find(_data);
      cout << a << " has " << -parent[x]-1 << " friends." << endl;
    }
  }

  void findGroup(vector<string> vc, string a){
    if(mpKeyString.find(a) == mpKeyString.end()) cout << "Member not in union!" << endl;
    else{
      int _data = mpKeyString[a];
      int temp = find(_data);
      cout << vc[temp] << " is in the group" << endl;
      for(int k=0; k<size; k++){
        if(parent[k] == temp){
          cout << vc[k] << " is in the group" << endl;
        }
      }
    }
  }

};

int main()
{
    vector<string> vc = {"monon", "radi", "diggy", "turno", "farhan", "alif"};
    DisjSet obj(vc);
    obj.Union("monon", "radi");
    obj.Union("diggy", "radi");
    obj.Union("farhan", "turno");
    obj.showRelationShips(vc);
    obj.numberOfFriends("monon");
    obj.numberOfFriends("diggy");
    obj.numberOfFriends("alif");
    obj.findGroup(vc, "turno");
    return 0;
}
