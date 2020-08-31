#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename K>
class Hash {
    int bucket;
    vector<list<K>> table;

public:
    Hash(int bucket);

    int hashFunction(K key);
    void deleteItem(K key);
    void insertItem(K key);
    void displayHash();
};

template<typename K>
Hash<K>::Hash(int bucket) {
    this->bucket = bucket;
    table.resize(bucket);
}

template<typename K>
int Hash<K>::hashFunction(K key) {
    return (key % this->bucket);
}

template<typename K>
void Hash<K>::insertItem(K key) {
    int index = this->hashFunction(key);

    typename list<K>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++)
    {
        if (*it == key) {
            return;
        }
    }

    this->table[index].push_back(key);
}

template<typename K>
void Hash<K>::deleteItem(K key) {
    int index = this->hashFunction(key);
    typename list<K>::iterator it;
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

template<typename K>
void Hash<K>::displayHash() {
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
    vector<int> arr = {15, 11, 27, 8, 12, 11};
    Hash<int>* hash = new Hash<int>(7);

    for(int x : arr) {
        hash->insertItem(x);
    }

    hash->deleteItem(12);

    hash->displayHash();

    return 0;
}