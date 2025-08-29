#include <iostream>
#include <vector>
using namespace std;

class HashTable {
public:
    int size;
    vector<int> hashTable;

    HashTable(int s) {
        size = s;
        hashTable.resize(size, -1); 
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            cout << "Collision occurred at index " << index << endl;
        }
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        if (hashTable[index] == key) {
            hashTable[index] = -1;
        } else {
            cout << "Key not found at index " << index << endl;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        return hashTable[index] == key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (hashTable[i] != -1)
                cout << i << ": " << hashTable[i] << endl;
            else
                cout << i << ": " << "Empty" << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15); 
    ht.insert(25); 

    ht.display();

    if (ht.search(5)) {
        cout << "5 Found" << endl;
    }

    ht.deleteKey(5);
    ht.display();

    return 0;
}
