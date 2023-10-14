// Link: https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
// https://www.geeksforgeeks.org/huffman-coding-using-priority-queue/?ref=rp
// implemented new things apart from the link
#include<bits/stdc++.h>
using namespace std;

struct huffmanNode{
  char data;
  unsigned freq;
  huffmanNode *left, *right;
  huffmanNode(char _data, unsigned _freq){
    left = NULL;
    right = NULL;
    this->data = _data;
    this->freq = _freq;
  }
};

struct compareHuffmanNodes{
  bool operator()(huffmanNode *left, huffmanNode *right)
  {
      return (left->freq > right->freq);
  }
};

void printHuffmanTreeCodes(huffmanNode* root, string str, map<char, string> &decoderMap){
  if(!root) return;

  if(root->data != '&'){
    cout << root->data << ": " << str << "\n";
    decoderMap.insert(pair<char, string>(root->data, str));
  }
  printHuffmanTreeCodes(root->left, str + "0", decoderMap);
  printHuffmanTreeCodes(root->right, str + "1", decoderMap);
}

map<char, string> HuffmanConverter(multimap<unsigned, char> &multimp){
  huffmanNode *left, *right, *top;
  priority_queue<huffmanNode*, vector<huffmanNode*>, compareHuffmanNodes> huffmanTree;

  for(auto it = multimp.begin(); it != multimp.end(); it++){
    huffmanNode* temp = new huffmanNode(it->second, it->first);
    huffmanTree.push(temp);
  }

  while(huffmanTree.size() != 1){
    left = huffmanTree.top();
    huffmanTree.pop();
    right = huffmanTree.top();
    huffmanTree.pop();
    top = new huffmanNode('&', (left->freq + right->freq));
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
    for(auto i=mp.begin(); i!=mp.end(); i++){
        multimp.insert(pair<unsigned, char>(i->second, i->first));
    }
    return multimp;
}


void giveHuffmanEncoding(string str){
  int len = str.length();
  map<char, unsigned> mp;
  for(auto i = 0; i<len; i++){
    char ch = str[i];
    if(mp.find(ch)==mp.end()){
      mp.insert(pair<char,unsigned>(ch,1));
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
