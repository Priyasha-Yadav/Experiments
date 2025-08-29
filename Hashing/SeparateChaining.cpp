#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
public:
    int size;
    vector<list<int>> table;

    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15); 
    ht.insert(25); 

    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.deleteKey(15);
    cout << "After deleting 15:" << endl;
    ht.display();

    return 0;
}