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

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % size] != -1 && table[(index + i * i) % size] != -2) {
            i++;
            if (i == size) {
                cout << "Table is full\n";
                return;
            }
        }
        table[(index + i * i) % size] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % size] != -1) {
            if (table[(index + i * i) % size] == key)
                return true;
            i++;
            if (i == size) return false;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % size] != -1) {
            if (table[(index + i * i) % size] == key) {
                table[(index + i * i) % size] = -2;
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

    if (ht.search(15)) {
        cout << "15 Found" << endl;
    }

    ht.deleteKey(15);
    ht.display();

    return 0;
}