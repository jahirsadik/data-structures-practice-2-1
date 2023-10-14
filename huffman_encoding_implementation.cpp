#include<bits/stdc++.h>
using namespace std;

struct HuffmanNode{
  char data;
  unsigned freq;
  HuffmanNode *left, *right;
  HuffmanNode(char _data, unsigned _freq){
    left = NULL;
    right = NULL;
    this->data = _data;
    this->freq = _freq;
  }
};

struct NodeComparator{
  bool operator()(HuffmanNode *first, HuffmanNode *second){
    return (first->freq > second->freq);
  }
};

void printHuffmanTreeCodes(HuffmanNode *root, string str, map<char,string> &decoderMap){
  if(!root) return;
  if(root->data != '&'){
    cout << root->data << ": " << str << "\n";
    decoderMap.insert(pair<char,string>(root->data, str));
  }
  printHuffmanTreeCodes(root->left, (str+"0"), decoderMap);
  printHuffmanTreeCodes(root->right, (str + "1"), decoderMap);
}

map<char,string> HuffmanConverter(multimap<unsigned, char> &multimp){ // don't think i need '&'
  HuffmanNode *left, *right, *top;
  priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeComparator> huffmanTree;

  for(auto it = multimp.begin(); it!= multimp.end(); it++){
    HuffmanNode* temp = new HuffmanNode(it->second, it->first);
    huffmanTree.push(temp);
  }

  while(huffmanTree.size() != 1){  // size one means done, only root remaining
    left = huffmanTree.top();
    huffmanTree.pop();
    right = huffmanTree.top();
    huffmanTree.pop();
    top = new HuffmanNode('&', (left->freq + right->freq));
    top->left = left;
    top->right = right;
    huffmanTree.push(top);
  }

  map<char, string> decoderMap;
  printHuffmanTreeCodes(huffmanTree.top(), "", decoderMap);
  return decoderMap;
}

multimap<unsigned, char> invertMapToMultimap(map<char, unsigned> &mp){
  multimap<unsigned, char> multimp;
  for(auto it = mp.begin(); it != mp.end(); it++){
    multimp.insert(pair<unsigned, char>(it->second, it->first));
  }
  return multimp;
}

void giveHuffmanEncoding(string str){
  int len = str.length();
  map<char, unsigned> mp;
  for(int i = 0; i<len; i++){
    char ch = str[i];
    if(mp.find(ch) == mp.end()){
      mp.insert(pair<char, unsigned>(ch, 1));
    }
    else mp[ch]++;
  }
  printf("Chars and frequency\n");
  for(auto i=mp.begin(); i!=mp.end(); i++){
      cout << i->first << " " << i->second << endl;
  }

  printf("Chars and frequency sorted according to frequency\n");
  multimap<unsigned, char> multimp = invertMapToMultimap(mp);

  for(auto i=multimp.begin(); i!=multimp.end(); i++){
     cout << i->first << " " << i->second << endl;
  }

  printf("Huffman encoding:\n" );
  map<char, string> decoderMap = HuffmanConverter(multimp);

  for(auto it = decoderMap.begin(); it != decoderMap.end(); it++){
    cout << "decoderMap elements:   " << it->first << "  code: " << it->second << endl;
  }

  printf("Encoded Message:\n\t\t\t");
  for(int i=0; i<len; i++){
    char ch = str[i];
    cout << decoderMap[ch];
  }
  cout << endl;

}

int main(){
  string str;
  getline(cin, str);
  giveHuffmanEncoding(str);

  return 0;
}
