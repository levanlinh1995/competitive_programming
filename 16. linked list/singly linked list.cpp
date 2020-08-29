#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// class Node {
//     public:
//         int data;
//         Node* next;
// };

void printList(Node* &node) {
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* createNewNode(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = NULL;

    return newNode;
}

void addFirst(Node* &head, int key) {
    Node* newNode = createNewNode(key);

    if (!head) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}


void insertAfter(Node* &prevNode, int key) {
    if (!prevNode) {
        cout << "the given previous node can not be NULL";
        return;
    }
    
    Node* newNode = createNewNode(key);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void append(Node** head, int key) {
    if (!(*head)) {
        addFirst((*head), key);
        return;
    }

    Node* newNode = createNewNode(key);

    Node* last = (*head);
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}

void removeNode(Node* &head, int key) {
    Node* temp = head;
    if (head && head->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    Node* prevNode;
    while (temp && temp->data != key)
    {
        prevNode = temp;
        temp = temp->next;
    }
    
    prevNode->next = temp->next;
    delete temp;
}

int main() {

    Node* head = NULL;

    addFirst(head, 3);
    addFirst(head, 2);
    addFirst(head, 1);
    append(&head, 4);
    insertAfter(head->next, 9);
    removeNode(head, 9);

    printList(head);

    return 0;
}