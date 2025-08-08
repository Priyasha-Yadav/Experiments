# 📚 Linked List Overview


## 1. What is a Linked List?

A **linked list** is a linear data structure where elements (called **nodes**) are stored non-contiguously in memory. Each node contains:
- **Data**: the actual value
- **Pointer/Reference**: to the next node (and optionally the previous node)

---

## 2. How is a Linked List Different from an Array?

| Feature             | **Array**                             | **Linked List**                         |
|---------------------|----------------------------------------|------------------------------------------|
| Memory Allocation   | Contiguous                            | Non-contiguous                           |
| Size                | Fixed (unless dynamically resized)     | Dynamic                                  |
| Access Time         | O(1) random access                    | O(n) traversal                           |
| Insertion/Deletion  | Costly (due to shifting)              | Efficient (pointer adjustment)           |
| Memory Efficiency   | Possible wastage                      | Overhead due to pointers                 |


## 3. Types of Linked Lists

1. **Singly Linked List**  
   - Each node points to the next node only.

2. **Doubly Linked List**  
   - Each node points to both next and previous nodes.

3. **Circular Linked List**  
   - Last node points back to the first node.  
   - Can be **singly** or **doubly** circular.


## 4. Advantages and Disadvantages of Linked Lists

### ✅ Advantages
- Dynamic sizing
- Efficient insertions/deletions (especially at beginning/middle)
- No need for pre-allocation

### ❌ Disadvantages
- No random access (must traverse)
- Extra memory for pointers
- Poor cache performance


## 5. What is a Node in a Linked List?

A **node** is the building block of a linked list:


- **Data**: stores the actual value
- **Pointer(s)**:
  - `Next` (in singly linked lists)
  - `Next` and `Prev` (in doubly linked lists)

---
```
+------+------------+
| Data | Pointer(s) |
+------+------------+
```
## 6. Time Complexity of Insertion and Deletion

| Operation           | Time Complexity |
|---------------------|------------------|
| Insertion at head   | O(1)             |
| Insertion at tail   | O(n) (O(1) if tail pointer used) |
| Insertion in middle | O(n)             |
| Deletion at head    | O(1)             |
| Deletion at tail    | O(n) (O(1) in doubly linked list with tail pointer) |
| Deletion in middle  | O(n)             |

