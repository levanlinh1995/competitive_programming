#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hash {
    int bucket;
    vector<list<int>> table;

public:
    Hash(int bucket);

    int hashFunction(int key);
    void deleteItem(int key);
    void insertItem(int key);
    void displayHash();
};

Hash::Hash(int bucket) {
    this->bucket = bucket;
    table.resize(bucket);
}

int Hash::hashFunction(int key) {
    return (key % this->bucket);
}

void Hash::insertItem(int key) {
    int index = this->hashFunction(key);
    this->table[index].push_back(key);
}

void Hash::deleteItem(int key) {
    int index = this->hashFunction(key);
    list<int>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++)
    {
        if (*it == key) {
            break;
        }
    }

    if (it != table[index].end()) {
        table[index].erase(it);
    }
}

void Hash::displayHash() {
    for (int i = 0; i < this->bucket; i++)
    {
        cout << i << "-->";
        for (auto x : this->table[i]) {
            cout << x << "-->";
        }

        cout << endl;
    }
    
}

int main() {
    vector<int> arr = {15, 11, 27, 8, 12};
    Hash* hash = new Hash(7);

    for(int x : arr) {
        hash->insertItem(x);
    }

    hash->deleteItem(12);

    hash->displayHash();

    return 0;
}