#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* right;
    Node* left;
};

Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->key = x;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

Node* insertNode(Node* root, int x) {
    if (root == NULL) {
        return createNode(x);
    } else if (root->key > x) {
        root->right = insertNode(root->right, x);
    } else if (root->key < x) {
        root->left = insertNode(root->left, x);
    }

    return root;
}

void createTree(Node* &root, const vector<int> &arr) {
    for (int x : arr) {
        root = insertNode(root, x);
    }
}

Node* findMinValue(Node* node) {
    Node* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* &root, int x) {
    if(root == NULL) {
        return root;
    }

    if (root->key > x) {
        root->left = deleteNode(root->left, x);
    } else if (root->key < x) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == NULL) {
            Node* minValue = findMinValue(root->right);
            root->key = minValue->key;
            root->right = deleteNode(root->right, minValue->key);
        }
    }

    return root;
}

void traversalTree(Node* root) {
    if (root != NULL) {
        traversalTree(root->left);
        cout << root->key;
        traversalTree(root->right);
    }
}

int size(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return size(root->left) + 1 + size(root->right);
    
}

void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Node* node = new Node;
    
    return 0;
}
