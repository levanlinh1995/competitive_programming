#include <bits/stdc++.h>
using namespace std;

#define MAX 26

struct Node {
    Node* child[MAX];
    int count;
};

Node* newNode() {
    Node* node = new Node;
    node->count = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

void addWord(Node* root, string s) {
    int c;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i] - 'a';
        if (temp->child[c] == NULL) {
            temp->child[c] = newNode();
        }
        temp = temp->child[c];
    }

    temp->count++;
}

bool searchWord(Node* root, string s) {
    int c;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i] - 'a';
        if (temp->child[c] == NULL) {
            return false;
        }
        temp = temp->child[c];
    }
    
    return temp->count > 0;
}

bool isWord(Node* root) {
    return root->count > 0;
}

bool isEmpty(Node* root) {
    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i] != NULL) {
            return false;
        }
    }

    return true;
}

bool removeWord(Node* root, string s, int level, int len) {
    if (!root) {
        return false;
    }

    int ch = s[level] - 'a';
    if (level == len) {
        if (root->count > 0) {
            root->count--;
            return true;
        }

        return false;
    }

    int flag = removeWord(root->child[ch], s, level + 1, len);

    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
        delete root->child[ch];
        root->child[ch] = NULL;
    }

    return flag;
}

void printTrie(Node* root, string s) {
    if (isWord(root)) {
        cout << s << endl;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i]) {
            printTrie(root->child[i], s + (char) (i + 'a'));
        }
    }
}


int main() {
    Node* root = newNode();

    addWord(root, "big");
    addWord(root, "bigo");
    addWord(root, "bigohaha");

    cout << searchWord(root, "big0") << endl;

    removeWord(root, "bigo", 0, 4);


    printTrie(root, "");

    return 0;
}