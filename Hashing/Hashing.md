# Hashing and Hash Tables in C++

## Introduction

Hashing is a powerful technique in **Data Structures and Algorithms (DSA)** that allows us to store and retrieve data in **constant average time (O(1))**.

It works by applying a **hash function** to a key, which generates an index where the value is stored in a **hash table**.

Hash tables are widely used in real-world applications like **databases, compilers, caching, and networking**.

---

## What is Hashing?

- **Hashing**: A process of mapping large or infinite input data into a fixed-size integer value (hash code).
- **Hash Function**: A function that takes a key and returns an index.
    - Example:
        
        ```cpp
        index = key % table_size;

        ```
        
- **Hash Table**: A data structure (array-like) that stores values at indices computed using the hash function.

---

## Key Concepts

### 1. Hash Function

- Converts a key into an index in the table.
- Should be:
    - **Fast** (constant time)
    - **Deterministic** (same input → same output)
    - **Uniform** (distributes keys evenly to minimize collisions)

### 2. Collision

When two keys map to the same index.

Since collisions are unavoidable, we need **collision handling techniques**.

### Collision Handling Methods

- **Chaining** → Use a linked list/vector at each index.
- **Open Addressing** → Find another empty slot.
    - Linear Probing
    - Quadratic Probing
    - Double Hashing

### 3. Load Factor (α)

Ratio of number of elements to table size:

```
α = n / m

```

- `n` = number of elements
- `m` = table size
- High load factor → more collisions → rehashing required.

---

## Operations in Hash Table

| Operation | Average Case | Worst Case (with bad hash) |
| --- | --- | --- |
| Insertion | O(1) | O(n) |
| Search | O(1) | O(n) |
| Deletion | O(1) | O(n) |

---

## Advantages

- **Very fast average case** (`O(1)` operations)
- **Efficient memory usage** compared to trees for some cases
- **Flexible collision handling methods**

## Disadvantages

- **Collisions** are unavoidable
- **Bad hash functions** lead to poor performance
- **Not ordered** (unlike BSTs)
- **Resizing/Rehashing** can be expensive

---

## Real-World Use Cases

1. **Databases** → Indexing for fast record lookup (primary key → record address).
2. **Compilers** → Symbol tables for variables/functions.
3. **Operating Systems** → Page tables, process management.
4. **Cryptography** → Password hashing, digital signatures, data integrity checks.
5. **Caching** → Quick retrieval of frequently used data.
6. **Networking** → IP routing tables, MAC address lookups.
7. **Search Engines** → Storing and accessing keyword mappings efficiently.
8. **Blockchain** → Hashing ensures immutability and verification of blocks.

---

## Comparison (Hash Table vs Other Structures)

| Structure | Search | Insert | Delete | Ordered? | Notes |
| --- | --- | --- | --- | --- | --- |
| Array | O(n) | O(1) | O(n) |  Yes | Sequential storage |
| Linked List | O(n) | O(1) | O(1) |  Yes | Good for dynamic memory |
| BST (Balanced) | O(log n) | O(log n) | O(log n) |  Yes | Sorted storage |
| **Hash Table** | **O(1)** | **O(1)** | **O(1)** |  No | Best for fast lookups |

---

## Example Implementation in C++ (Chaining)

```cpp
#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int size;
    list<int>* table;

public:
    HashTable(int size) {
        this->size = size;
        table = new list<int>[size];
    }

    int hashFunction(int key) {
        return key % size; // simple division method
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (auto x : table[i]) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    ht.remove(15);
    ht.display();
}

```

---

## Look Up Summary

- Hashing = **direct access technique** for faster lookup.
- Load factor determines efficiency.
- Collisions handled by **chaining** or **probing**.
- Unlike linked lists or arrays, hashing **does not preserve order**.
- Hash tables are ideal for **large datasets** where searching speed matters more than order.
- **Real-world analogy**:
    - Imagine a **library with books**. Instead of searching each shelf (linear search), books are placed in racks based on their **first letter (hash function)**. Even if two books have the same starting letter (collision), they’re stored on the same rack (chaining).