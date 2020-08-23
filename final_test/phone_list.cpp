#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

struct Node {
    Node* child[MAX];
    bool isEndOfWord;
    int count;
};

Node* newNode() {
    Node* node = new Node();
    node->isEndOfWord = false;
    node->count = 0;

    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
} 

bool addWord(Node* root, string s) {
    Node* temp = root;
    int ch;
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - '0';

        if (temp->child[ch] != NULL && i == s.size() - 1) {
            k = temp->child[ch]->count;
        }

        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }

        temp = temp->child[ch];
        temp->count++;

        if (temp->isEndOfWord) {
            return false;
        }
    }

    temp->isEndOfWord = true;

    cout << k << " " <<  temp->count << " ";
    
    if (temp->count > k) {
        return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    int T, N;
    string s;

    cin >> T;

    while (T--)
    {
        Node* root = newNode();

        cin >> N;
        cin.ignore();

        int isNo = false;

        for (int i = 0; i < N; i++)
        {
            getline(cin, s);
            if(!addWord(root, s)) {
                isNo = true;
                break;
            }
        }

        if (isNo) {
            cout << "NO";
        } else {
            cout << "YES";
        }

        cout << endl;

        delete root;
    }

    return 0;
}