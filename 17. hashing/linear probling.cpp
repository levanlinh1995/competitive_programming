#include <iostream>
#include <vector>
using namespace std;

template<typename K, typename V>
class Node {
public:
    K key;
    V value;

    Node() {}

    Node(K newKey, V newValue) {
        this->key = newKey;
        this->value = newValue;
    }
};

template<typename K, typename V>
class HashMap {
private:
    int capacity;
    int size;
    vector<Node<K, V>*> table;
    Node<K, V>* dummy;
public:
    HashMap() {}

    HashMap(int newCapacity) {
        this->capacity = newCapacity;
        this->size = 0;
        dummy = new Node<K, V>(-1, -1);
        table.resize(newCapacity);
    }

    bool isEmpty() {
        return this->size == 0;
    }

    int getSize() {
        return this->size;
    }

    int hashFunction(K key) {
        return key % this->capacity;
    }

    // insert key-value pair
    void insertNode(K key, V value) {
        Node<K, V>* newNode = new Node<K, V>(key, value);
        int hashIndex = this->hashFunction(key);

        while (this->table[hashIndex] && (this->table[hashIndex]->key != key)
            && this->table[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= this->capacity;
        }

        if (this->table[hashIndex] && (this->table[hashIndex]->key == key)) {
            return;
        }

        this->table[hashIndex] = newNode;
        this->size++;
    }

    // delete key-value pair
    void deleteNode(K key) {
        
    }

    // search value from a given key
    V searchNode(K key) {

    }

    void displayHashMap() {

    }
};

int main() {
    HashMap<int, int> *h = new HashMap<int, int>(20);
    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(3, 3);
    h->insertNode(3, 3);
    h->displayHashMap();

    cout << h->getSize() << endl;
    // cout << h->deleteNode(3) << endl;
    cout << h->isEmpty() << endl;
    // cout << h->searchNode(2) << endl;

    return 0;
}
