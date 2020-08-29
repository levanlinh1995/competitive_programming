// problem: 707. Design Linked List
// link: https://leetcode.com/problems/design-linked-list/description/

#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
};

class MyLinkedList {
    Node* head;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    int getsize() {
        return this->size;
    }

    Node* createNewNode(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= this->getsize()) {
            return -1;
        }

        if (!this->head) {
            return -1;
        }

        int i = 0;
        Node* temp = this->head;

        while (temp)
        {
            if (i == index) {
                return temp->data;
            }

            temp = temp->next;
            i++;
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = this->createNewNode(val);
        
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!this->head) {
            this->addAtHead(val);
            return;
        }

        Node* newNode = this->createNewNode(val);

        Node* last = this->head;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = newNode;
        this->size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->getsize()) {
            return;
        }

        if (index == this->getsize()) {
            this->addAtTail(val);
            return;
        }

        if (index == 0) {
            this->addAtHead(val);
            return;
        }

        Node* newNode = createNewNode(val);
        Node* temp = this->head;
        Node* prev;
        int i = 0;

        while (temp)
        {
            if (i == index) {
                prev->next = newNode;
                newNode->next = temp;
                this->size++;
                return;
            }

            prev = temp;
            temp = temp->next;
            i++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= getsize()) {
            return;
        }

        Node* temp = this->head;

        if (index == 0) {
            this->head = this->head->next;
            delete temp;
            this->size--;
            return;
        }

        Node* prev;
        int i = 0;

        while (temp)
        {
            if (i == index) {
                prev->next = temp->next;
                delete temp;
                this->size--;
                return;
            }

            prev = temp;
            temp = temp->next;
            i++;
        }
    }

    void printList() {
        Node* temp = this->head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
    }
};

int main() {
    // MyLinkedList* obj = new MyLinkedList();
    // int val = obj->get(0);
    // cout << val;
    // obj->addAtHead(1);
    // obj->addAtTail(val);
    // obj->addAtIndex(index,val);
    // obj->deleteAtIndex(0);
    // obj->printList();

    return 0;
}