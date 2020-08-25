// Prolem: DNA Prefix
// Link: https://vjudge.net/problem/LightOJ-1224

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> dna = {'A', 'C', 'G', 'T'};
int res = 0;

struct Node {
   Node* child[4];
   int n_common;
};

Node *newNode() {
   Node *new_node = new Node;
   new_node->n_common = 0;
   for (int i = 0; i < dna.size(); i++) {
      new_node->child[i] = nullptr;
   }
   return new_node;
}

void addWord(Node* root, const string& s) {
   Node* temp = root;
   for (int i = 0; i < s.size(); i++) {
      int ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
      int level = i + 1;

      if (temp->child[ch] == nullptr) {
         temp->child[ch] = newNode();
      }

      temp = temp->child[ch];
      temp->n_common++;
      res = max(res, temp->n_common * level);
   }
}
      
int main() {
   int t, n, tc;
   string s;
   cin >> t;

   for (tc = 1; tc <= t; tc++) {
      cin >> n;
      Node* root = newNode();
      res = 0;

      for (int i = 0; i < n; i++) {
         cin >> s;
         addWord(root, s);
      }

      cout << "Case " << tc << ": " << res << endl;
   }
   return 0;
}