#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    public: int size;
    vector < int > hashTable;

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
            int ogIndex = index;
            do {
                index = (index + 1) % size;
                if (hashTable[index] == -1) {
                    hashTable[index] = key;
                    return;
                }
            }
            while (index != ogIndex);
            cout << "Hash table is full, cannot insert key " << key << endl;

        }
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        do
        {
            if (hashTable[index] == key)
                return true;
            if (hashTable[index] == -1)
                return false;
            index = (index + 1) % size;
        } while (index != originalIndex);
        return false;
    }

    void deleteKey(int key){
        int index = hashFunction(key);
        int originalIndex = index;
        do{
            if (hashTable[index] == key){
                hashTable[index] = -1;
                return;
            }
            if (hashTable[index] == -1){
                cout << "Key not found: " << key << endl;
                return;
            }
            index = (index + 1) % size;
        } 
        while (index != originalIndex);
        cout << "Key not found: " << key << endl;
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