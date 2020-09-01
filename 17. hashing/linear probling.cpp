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

    bool isFull() {
        return this->size == this->capacity;
    }

    int hashFunction(K key) {
        return key % this->capacity;
    }

    // insert key-value pair
    void insertNode(K key, V value) {
        if (this->isFull())
        {
            return;
        }
        
        Node<K, V>* newNode = new Node<K, V>(key, value);
        int index = this->hashFunction(key);

        int i = 0;
        int hashIndex = index;

        while (this->table[hashIndex] && (this->table[hashIndex]->key != key)
            && this->table[hashIndex]->key != -1)
        {
            hashIndex = (index + i) % this->capacity;
            i++;
        }

        if (this->table[hashIndex] && (this->table[hashIndex]->key == key)) {
            return;
        }

        this->table[hashIndex] = newNode;
        this->size++;
    }

    // delete key-value pair
    void deleteNode(K key) {
        int index = this->hashFunction(key);
        int hashIndex = index;
        int i = 0;

        while (this->table[hashIndex])
        {
            if (this->table[hashIndex]->key == key) {
                this->table[hashIndex] = this->dummy;
                this->size--;
                return;
            }

            hashIndex = (index + i) % this->capacity;
            i++;
        }
    }

    // search value from a given key
    V searchNode(K key) {
        int index = this->hashFunction(key);
        int hashIndex = index;
        int i = 0;

        while (this->table[hashIndex])
        {
            if (this->table[hashIndex]->key == key) {
                return this->table[hashIndex]->value;
            }

            hashIndex = (index + i) % this->capacity;
            i++;
        }

        return -1;
    }

    void displayHashMap() {
        for (int i = 0; i < this->capacity; i++)
        {
            cout << "index " << i;
            if (this->table[i]) {
                cout << " :(" << this->table[i]->key << ", " << this->table[i]->value << ")";
            } else {
                cout << " : NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap<int, int> *h = new HashMap<int, int>(200);
    h->insertNode(0, 0);
    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(3, 3);
    h->insertNode(3, 3);
    h->displayHashMap();

    cout << h->getSize() << endl;

    h->deleteNode(2);

    h->displayHashMap();
    
    // cout << h->isEmpty() << endl;

    cout << h->getSize() << endl;
    // cout << h->searchNode(1000) << endl;

    return 0;
}
