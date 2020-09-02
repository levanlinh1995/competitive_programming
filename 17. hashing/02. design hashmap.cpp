// problem: 706. Design HashMap
// link: https://leetcode.com/problems/design-hashmap/description/

#include <iostream>
#include<vector>
#include <list>
using namespace std;

class Node {
public:
    int key;
    int value;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class MyHashMap {
private:
    int size;
    int buckets;
    float DEFAULT_LOAD_FACTOR = 0.7f;
    vector<list<Node*>> table;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        this->size = 0; // entry of data
        this->buckets = 20000; // capacity
        table.resize(this->buckets);
    }

    int hashFunction(int key) {
        return (key % this->buckets);
    }
    
    void put(int key, int value) {
        int hashIndex = this->hashFunction(key);
        list<Node*>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if ((*it)->key == key) {
                (*it)->value = value;
                return;
            }
        }

        this->table[hashIndex].push_back(new Node(key, value));
        this->size++;

        float loadFactor = (1.0f * this->size)/this->buckets;
        if (loadFactor > this->DEFAULT_LOAD_FACTOR) {
            rehashing();
        }
    }
    
    void rehashing() {
        // to do late
    }

    void remove(int key) {
        int hashIndex = this->hashFunction(key);

        list<Node*>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if ((*it)->key == key) {
                this->table[hashIndex].erase(it);
                this->size--;
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    int get(int key) {
        int hashIndex = this->hashFunction(key);

        list<Node*>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if ((*it)->key == key) {
                return (*it)->value;
            }
        }

        return -1;
    }
};

int main() {

    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(3);

    return 0;
}