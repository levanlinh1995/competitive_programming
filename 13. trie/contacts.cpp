#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 26

struct Node {
    Node* child[MAX_LEN];
    bool isEndOfWord;
    int n_common;
};

Node* newNode() {
    Node* node = new Node;
    node->isEndOfWord = false;
    node->n_common = 0;
    for (int i = 0; i < MAX_LEN; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

void addWord(Node* root, string s) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (!temp->child[ch]) {
            temp->child[ch] = newNode();
        }

        temp = temp->child[ch];
        temp->n_common++;
    }
    
    temp->isEndOfWord = true;
}

int findWord(Node* root, string s) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {   
        ch = s[i] - 'a';
        if (!temp->child[ch]) {
            return 0;
        }

        temp = temp->child[ch];
    }

    return temp->n_common;
}

int main() {
    // freopen("input.txt", "r", stdin);
    Node* root = newNode();

    int n;
    string oper, word;

    cin >> n;

    while (n--)
    {
        cin >> oper >> word;
        if (oper == "add") {
            addWord(root, word);
        } else if (oper == "find") {
            cout << findWord(root, word);
            cout << endl;
        }
    }
    
    return 0;
}