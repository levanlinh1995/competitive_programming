#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

struct Node {
    Node* child[MAX];
    bool isEndOfWord;
};

Node* newNode() {
    Node* node = new Node();
    node->isEndOfWord = false;

    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

bool isWord(Node* root) {
    return root->isEndOfWord;
}

void addWord(Node* root, string s) {
    Node* temp = root;
    int ch;

    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }

        temp = temp->child[ch];
    }

    temp->isEndOfWord = true;
}

bool findWord(Node* root, string s) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            return false;
        }

        temp = temp->child[ch];
    }

    return temp->isEndOfWord;
}

void printTree(Node* root, string s) {
    if (isWord(root)) {
        cout << s << endl;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i] != NULL) {
            printTree(root->child[i], s +  (char) (i + 'a'));
        }
    }
    

}


int main() {

    Node* root = newNode();

    addWord(root, "le");
    addWord(root, "linh");
    addWord(root, "haha");
    addWord(root, "linhle");

    cout << findWord(root, "linhle");

    // printTree(root, "");

    return 0;
}