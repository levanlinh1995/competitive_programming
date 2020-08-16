#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN  26

struct Node {
    Node* child[MAX_LEN];
    bool isEndOfWord;

};

Node* newNode() {
    Node* node = new Node;
    node->isEndOfWord = false;

    for (int i = 0; i < MAX_LEN; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

bool addWord(Node* root, string s) {
    int ch;
    Node* temp = root;
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';

        if (!temp->child[ch]) {
            flag = true;
            temp->child[ch] = newNode();
        }

        temp = temp->child[ch];

        if (temp->isEndOfWord) {
            return false;
        }

    }
    
    temp->isEndOfWord = true;

    return flag;
}

int main() {

    freopen("input.txt", "r", stdin);

    Node* root = newNode();
    int N;
    string str;
    cin >> N;

    while (N--)
    {
        cin >> str;
        if (!addWord(root, str)) {
            cout << "vulnerable";
            return 0;
        }
    }

    cout << "non vulnerable";

    return 0;
}