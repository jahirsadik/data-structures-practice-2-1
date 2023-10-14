/*
  This union-find implementation can do the regular union-find operations
  as well as map a vector of strings to do union-find operations using
  mapping.
*/

#include<bits/stdc++.h>
using namespace std;

#define DisjSet DisjointSet

class DisjointSet{
private:
  map<string, int> dictionary;
  map<int, string> mp; // map for computation purposes
  int  numberOfComponents, size; // won't use rank if not necessary
  vector<int> parent, rank;
  bool isMapped;
  // rank is the length of the maximum length in the sets(length to parent)

  void makeSet(){
    for(int i=0; i<size; i++){
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  void makeSet(vector<string> v){
    for(int i=0; i<size; i++){
      parent.push_back(-1);
      rank.push_back(0);
      mp[i] = v[i]; // if strings are passed, we have to map them to numbers
      dictionary[v[i]] = i;
      cout << "\t\t" << v[i] << " is mapped to " << i << endl;
    }
    printf("\n");
  }

public:
  DisjointSet(unsigned _size){
    isMapped = false;
    this->size = _size;
    numberOfComponents = _size;
    makeSet();
  }

  DisjointSet(vector<string> v){
    isMapped = true;
    int _size = v.size();
    this->size = _size;
    numberOfComponents = _size;
    makeSet(v);
  }

  void addElement(){
    parent.push_back(-1);
    rank.push_back(0);
    size++;
    numberOfComponents++;
  }

  void addElement(string s){
    parent.push_back(-1);
    rank.push_back(0);
    dictionary[s] = size;
    mp[size++] = s;
    numberOfComponents++;
  }

  int find(int _data){
    if(_data < 0 || _data >= size) return -1; // in case of error in input data
    if(parent[_data] < 0) return _data;
    // next 2 lines for path compression using recursion
    int root = find(parent[_data]);
    parent[_data] = root;
    return root;
  }

  string find(string _data){
    if(dictionary.find(_data) ==  dictionary.end()) return "Not existant value";
    int mappedData = dictionary[_data];
    int answer = find(mappedData);
    return mp[answer];
  }

  void Union(int a, int b){
    int aroot = find(a);
    int broot = find(b);
    if(aroot == broot) return;
    // else numberOfComponents decreases
    numberOfComponents--;
    if(rank[aroot] > rank[broot]){
      parent[aroot] += parent[broot]; // number of elements in that component increases
      parent[broot] = aroot; // smaller one goes into the larger one
      // IT IS VERY IMPORTANT TO ADD FIRST AND THEN ASSIGN
    }
    else if(rank[aroot] < rank[broot]){
      parent[broot] += parent[aroot];
      parent[aroot] = broot;
    }
    else{
      parent[aroot] += parent[broot];
      parent[broot] = aroot; // randomly attached b to a
      rank[aroot]++; // rank increase one unit when both are the same rank
    }
  }

  void Union(string a, string b){
    if(dictionary.find(a) ==  dictionary.end()) return;
    if(dictionary.find(b) ==  dictionary.end()) return;
    int mappedData1 = dictionary[a];
    int mappedData2 = dictionary[b];
    Union(mappedData1, mappedData2);
  }

  int getNumberOfComponents(){
    return numberOfComponents;
  }

  void printArrays(){
    if(!isMapped){
      for(int i=0; i<size ; i++){
        cout << "i:" << i << "   parent:" << parent[i] << " " << "   rank:" << rank[i] << endl;
      }
      cout << endl;
    }
    else{
      for(int i=0; i<size; i++){
        cout << "item: " << mp[i] << ", i:" << i << "   parent:" << parent[i] << " " << "   rank:" << rank[i] << endl;
      }
      cout << endl;
    }
  }

  int getComponentSize(int _data){
    int x = find(_data);
    return -parent[x];
  }

  int getComponentSize(string _data){
    if(dictionary.find(_data) ==  dictionary.end()) return 0;
    int mappedData = dictionary[_data];
    return getComponentSize(mappedData);
  }
};


int main()
{
    vector<string> v;
    v.push_back("Monon");
    v.push_back("Abdu");
    v.push_back("Jawad");
    v.push_back("Diggy");
    v.push_back("Foysal");
    DisjointSet obj(v);

    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.addElement("Fawwaz");
    obj.Union(3,1);
    obj.addElement("Parabar");
    obj.printArrays();
    cout << obj.find("Jawad") << endl;
    obj.Union("Jawad", "Abdullah");
    cout << obj.getNumberOfComponents() << "  "  << obj.getComponentSize("Parabar") << endl;
    return 0;
}
