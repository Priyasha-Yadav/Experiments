#include <iostream>
#include <vector>
using namespace std;

class HashTable {
public:
    int size;
    vector<int> table;

    HashTable(int s) {
        size = s;
        table.resize(size, -1);
    }

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1 && table[(index + i * step) % size] != -2) {
            i++;
            if (i == size) {
                cout << "Table is full\n";
                return;
            }
        }
        table[(index + i * step) % size] = key;
    }

    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            if (table[(index + i * step) % size] == key)
                return true;
            i++;
            if (i == size) return false;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            if (table[(index + i * step) % size] == key) {
                table[(index + i * step) % size] = -2;
                return;
            }
            i++;
            if (i == size) return;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] == -1)
                cout << i << ": Empty" << endl;
            else if (table[i] == -2)
                cout << i << ": Deleted" << endl;
            else
                cout << i << ": " << table[i] << endl;
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