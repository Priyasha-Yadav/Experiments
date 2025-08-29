#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
public:
    int size;
    int count;
    float loadFactorThreshold;
    vector<list<int>> table;

    HashTable(int s, float lf = 0.75) {
        size = s;
        count = 0;
        loadFactorThreshold = lf;
        table.resize(size);
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        if ((float)(count + 1) / size > loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(key);
        table[index].push_back(key);
        count++;
    }

    void rehash() {
        int newSize = size * 2;
        vector<list<int>> oldTable = table;

        table.clear();
        table.resize(newSize);
        size = newSize;
        count = 0;

        for (const auto& chain : oldTable) {
            for (int key : chain) {
                insert(key);
            }
        }
        cout << "Table rehashed to new size: " << size << endl;
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
        count--;
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
    HashTable ht(5, 0.6); 

    ht.insert(5);
    ht.insert(15); 
    ht.insert(25); 
    ht.insert(35); 

    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.deleteKey(15);
    cout << "After deleting 15:" << endl;
    ht.display();

    return 0;
}