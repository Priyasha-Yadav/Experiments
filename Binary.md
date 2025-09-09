# Integer Representation in Memory

This document explains **how integers are stored in memory**, using an example in C/C++:

```c
int num = 10;
```

We’ll explore:

1. Binary conversion of the integer
2. Memory allocation on a 32-bit system
3. How **positive** numbers are stored
4. How **negative** numbers are stored using **Two's Complement**
5. How the number looks in memory (byte layout)

---

## 1. Decimal to Binary Conversion

- Decimal `10` → Binary form:

```
10 (decimal) = 1010 (binary)
```

- This is the *raw binary representation* of the number.
- However, computers store integers in **fixed-size blocks of memory**, not just the minimal number of bits.

---

## 2. Memory Allocation

- On a **32-bit system**:
    - An `int` typically occupies **4 bytes = 32 bits**.
- Therefore, the number must be represented using **32 bits**.

---

## 3. Storing Positive Numbers

- For `num = 10`:

```
Binary (unpadded):   1010
32-bit representation: 00000000 00000000 00000000 00001010

```

- Leading zeros are added to fill the remaining bits.

So in memory (in binary):

```
00000000 00000000 00000000 00001010

```

---

## 4. Storing Negative Numbers (Two’s Complement)

Computers do not store a **separate sign bit**. Instead, they use **two’s complement representation** to handle negative values.

### Steps for Two’s Complement:

To store `-10`:

1. **Write +10 in binary (32 bits):**

```
00000000 00000000 00000000 00001010

```

1. **Find the One’s Complement** (invert all bits):

```
11111111 11111111 11111111 11110101

```

1. **Add 1 to the One’s Complement:**

```
11111111 11111111 11111111 11110101
+                                    1
------------------------------------
11111111 11111111 11111111 11110110

```

This final result is the **Two’s Complement representation of -10**.

---

## 5. Memory Layout in RAM

When stored in memory, integers occupy **4 bytes**.

Each byte has its own **address**, and how the bytes are arranged depends on the system’s **endianness**:

- **Big Endian:** Most Significant Byte (MSB) stored first (lowest address).
- **Little Endian:** Least Significant Byte (LSB) stored first (lowest address).
    - Most modern PCs use **Little Endian** (Intel, AMD).

### Example: `num = 10`

32-bit binary representation:

```
00000000 00000000 00000000 00001010
```

In **hexadecimal**:

```
0x0000000A
```

### Memory Layout (Little Endian)

| Address | Byte (Hex) |
| --- | --- |
| 0x1000 | 0A |
| 0x1001 | 00 |
| 0x1002 | 00 |
| 0x1003 | 00 |

So in RAM (lowest address on left):

```
[0A][00][00][00]
```

### Memory Layout (Big Endian)

| Address | Byte (Hex) |
| --- | --- |
| 0x1000 | 00 |
| 0x1001 | 00 |
| 0x1002 | 00 |
| 0x1003 | 0A |

So in RAM:

```
[00][00][00][0A]
```

---

## 6. Why Two’s Complement?

- Single representation for `0` (unlike Sign-Magnitude or One’s Complement methods).
- Arithmetic operations (addition, subtraction) work uniformly without extra rules.
- Efficient for hardware implementation.

---

### 🔄 Reverting a Two’s Complement Number

If you have a number stored in **two’s complement** (e.g., `-10`), and you want to get back its **positive form**, here’s the process:

### Example: `10` in 32-bit

```
11111111 11111111 11111111 11110110
```

---

### Step 1: Take the One’s Complement

Invert all the bits:

```
00000000 00000000 00000000 00001001
```

---

### Step 2: Add 1

Now add `1`:

```
00000000 00000000 00000000 00001001
+                                    1
------------------------------------
00000000 00000000 00000000 00001010
```

---

### Final Result

```
00000000 00000000 00000000 00001010 = +10
```

## 🔑 Key Takeaways

- Integers are stored in **binary**, padded to match the system’s word size (e.g., 32 bits).
- Positive numbers are stored as-is with leading zeros.
- Negative numbers use **Two’s Complement** (invert bits + add 1).
- Memory layout depends on **endianness** (Little vs Big Endian).
- To **negate a number** in two’s complement (switch from positive to negative or vice versa):
    
    **Invert the bits + Add 1**.
    

This works both ways:

- `+10 → -10` (two’s complement)
- `10 → +10` (two’s complement again)