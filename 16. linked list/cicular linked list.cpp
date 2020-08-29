#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNewNode(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = NULL;
}

void addToEmpty(Node* &last, int key) {
    if (!last) {
        Node* newNode = createNewNode(key);
        last = newNode;
        newNode->next = newNode;
    }
}

void addBegin(Node* &last, int key) {
    if (!last) {
        addToEmpty(last, key);
        return;
    }

    Node* newNode = createNewNode(key);
    newNode->next = last->next;
    last->next = newNode;
}

void addEnd(Node* &last, int key) {
    if (!last) {
        addToEmpty(last, key);
        return;
    }

    Node* newNode = createNewNode(key);
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void addAfter(Node* &last, int item, int key) {
    if (!last) {
        cout << "List is empty. So can not find value: " << item;
        return;
    }

    Node* temp = last->next; // firt node

    do {
        if (temp->data == item) {
            Node* newNode = createNewNode(key);
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last) {
                last = newNode;
            }

            return;
        }

        temp = temp->next;
    } while (temp != last->next);

}

void removeNode(Node* &last, int key) {
    if (!last) {
        cout << "List is empty.";
        return;
    }

    Node* temp = last->next; // first node
    Node* prev;

    // a number of node of list is only one node (last = first)
    if (last->next == last && last->data == key) {
        delete last;
        last = NULL;
        return;
    }

    // deleted node is first node
    if (last->next->data == key) {
        Node* firstNode = last->next;
        last->next = firstNode->next;
        delete firstNode;
        return;
    }

    do {
        if (temp->data == key) {
            prev->next = temp->next;

            if (temp == last) {
                last = prev;
            }   

            delete temp;

            return;
        }
        
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    cout << "no such keyfound";
}

void printList(Node* last) {
    if (!last) {
        cout << "list is empty";
        return;
    }

    Node* temp = last->next; // first node

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != last->next);
}

int main() {
    Node* last = NULL;

    addToEmpty(last, 3);
    addBegin(last, 2);
    addEnd(last, 4);
    addAfter(last, 4, 5);
    addAfter(last, 5, 6);

    removeNode(last, 2);

    printList(last);

    return 0;
}