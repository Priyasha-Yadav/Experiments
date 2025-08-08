# 🔁 Doubly Linked List


## 1. What is a Doubly Linked List?

A **doubly linked list (DLL)** is a type of linked list where each node contains **three parts**:
- **Data**: the value stored in the node
- **Pointer to the next node**
- **Pointer to the previous node**

This allows **bidirectional traversal** of the list.


---

## 2. How is a Doubly Linked List Different from a Singly Linked List?

| Feature                   | Singly Linked List                  | Doubly Linked List                    |
|---------------------------|-------------------------------------|--------------------------------------|
| Direction of Traversal    | One direction (forward only)        | Two directions (forward & backward)  |
| Node Structure            | Data + Next pointer                 | Data + Next + Prev pointers          |
| Memory Usage              | Less (1 pointer per node)           | More (2 pointers per node)           |
| Reverse Traversal         | Not possible directly               | Possible                              |
| Deletion Efficiency       | Less efficient (need previous node) | More efficient (direct access to prev) |

---
```
+--------+----------+--------+
| Prev | Data | Next |
+--------+----------+--------+
```

## 3. Advantages of Using a Doubly Linked List

- ✅ **Bidirectional traversal**: Can move both forward and backward
- ✅ **Efficient deletion**: Can delete a node without needing the previous node explicitly
- ✅ **Easy to implement certain algorithms** (e.g., undo/redo, browser history, etc.)
- ✅ **More flexible** than singly linked lists in insertion and deletion

---

## 4. Disadvantages of a Doubly Linked List

- ❌ **More memory overhead**: Each node stores two pointers
- ❌ **Slightly more complex operations**: Must manage two pointers per node
- ❌ **Extra time and logic** required to maintain both `next` and `prev` links

---

## 5. Typical Operations Performed on a Doubly Linked List

- **Traversal (Forward and Backward)**
- **Insertion**
  - At the head
  - At the tail
  - In the middle (after/before a given node)
- **Deletion**
  - From the head
  - From the tail
  - A specific node
- **Searching** for an element
- **Reversing** the list

---

## 6. When Would You Prefer a Doubly Linked List Over a Singly Linked List?

Choose a **doubly linked list** when:

- You need to **traverse in both directions**
- You need to **delete nodes efficiently**, especially when you have a reference to the node but not its predecessor
- You're implementing **complex data structures** like:
  - Deques
  - Navigation systems (e.g., web browser history)
  - Undo/redo features
  - LRU caches

