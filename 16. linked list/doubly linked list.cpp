#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNewNode(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void addFirst(Node* &head, int key) {
    Node* newNode = createNewNode(key);

    if (!head) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void append(Node* &head, int key) {
    if (!head) {
        addFirst(head, key);
        return;
    }

    Node* newNode = createNewNode(key);

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Node* node, int key) {
    if (!node)
    {
        cout << "a given node contains NULL";
        return;
    }

    Node* newNode = createNewNode(key);

    if (node->next) {
        node->next->prev = newNode;
    }

    newNode->next = node->next;
    newNode->prev = node;
    node->next = newNode;
}

void insertBefore(Node* &head, Node* node, int key) {
    if (!node) {
        cout << "a given node contains NULL";
        return;
    }

    Node* newNode = createNewNode(key);

    if (node->prev) {
        node->prev->next = newNode;
    } else {
        head = newNode;
    }

    newNode->prev = node->prev;
    newNode->next = node;
    node->prev = newNode;
}

void removeNode(Node* &head, int key) {
    Node* temp = head;
    while (temp && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void printList(Node* head) {
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = NULL;

    addFirst(head, 1);
    addFirst(head, 2);
    addFirst(head, 3);
    append(head, 0);

    insertBefore(head, head, 9);

    removeNode(head, 0);

    printList(head);

    return 0;
}