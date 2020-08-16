#include <iostream>
using namespace std;

#define MAX 26

struct Node {
    Node* child[MAX];
    int count;
    int weight;
};

bool isWord(Node* node) {
    return node->count > 0;
}

Node* newNode() {
    Node* node = new Node;
    node->count = 0;
    node->weight = 0;
    for (int i = 0; i < MAX; i++)
    {
        node->child[i] = NULL;
    }
    
    return node;
}

void addWord(Node* root, string s, int weight) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (!temp->child[ch]) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        temp->weight = max(weight, temp->weight);
    }
    
    temp->count++;
}

int findMaxWeight(Node* root, string search_str) {
    int ch;
    Node* temp = root;

    for (int i = 0; i < search_str.size(); i++)
    {
        ch = search_str[i] - 'a';
        if (!temp->child[ch]) {
            return -1;
        }
        temp = temp->child[ch];
    }

    return temp->weight;
}

int main() {
    // freopen("input.txt", "r", stdin);
    Node* root = newNode();

    int n, q;
    string s, t;
    int weight;

    cin >> n >> q;
    while (n--)
    {
        cin >> s >> weight;
        addWord(root, s, weight);
    }

    while (q--)
    {
        cin >> t;
        cout << findMaxWeight(root, t) << endl;
    }

    return 0;
}