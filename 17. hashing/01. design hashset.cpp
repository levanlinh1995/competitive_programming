// problem: 705. Design HashSet
// link: https://leetcode.com/problems/design-hashset/description/

#include <iostream>
#include<vector>
#include <list>
using namespace std;

class MyHashSet {
private:
    int size;
    int buckets;
    float DEFAULT_LOAD_FACTOR = 0.7f;
    vector<list<int>> table;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        this->size = 0; // entry of data
        this->buckets = 20000; // capacity
        table.resize(this->buckets);
    }

    int hashFunction(int key) {
        return (key % this->buckets);
    }
    
    void add(int key) {
        int hashIndex = this->hashFunction(key);
        list<int>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if (*it == key) {
                return;
            }
        }

        this->table[hashIndex].push_back(key);
        this->size++;

        float loadFactor = (1.0f * this->size)/this->buckets;
        if (loadFactor > this->DEFAULT_LOAD_FACTOR) {
            rehashing();
        }
    }
    
    void rehashing() {

    }

    void remove(int key) {
        int hashIndex = this->hashFunction(key);

        list<int>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if (*it == key) {
                this->table[hashIndex].erase(it);
                this->size--;
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashIndex = this->hashFunction(key);

        list<int>::iterator it;
        for (it = this->table[hashIndex].begin(); it != this->table[hashIndex].end(); it++)
        {
            if (*it == key) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    //Your MyHashSet object will be instantiated and called as such:
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    obj->add(3);
    obj->remove(1);
    bool param_3 = obj->contains(2);

    cout << param_3;

    return 0;
}