# Data Structures & Algorithms (DSA) Preparation 🚀

A comprehensive repository containing custom implementations of fundamental data structures and algorithmic patterns in C and Python. This workspace is designed for building computational problem-solving foundations, studying time/space complexity tradeoffs, and practicing coding interview questions.

---

## 💡 Real-world Relevance & Problem Solving

Strong foundations in Data Structures and Algorithms (DSA) are critical to writing high-performance, resource-efficient code. In real-world software engineering, these concepts are directly applied in:
1. **Operating Systems & Memory Management**: Page replacement (Stacks/Queues), heap memory allocation (Heaps/Trees).
2. **Database Systems**: Efficient search, range queries, and indexing (B-Trees, Hash Tables, Matrix operations).
3. **Networking**: Routing algorithms, packets serialization, buffer management (Queues, Graphs).
4. **Data Science & ML**: Multi-dimensional operations, linear transformations, and distance metrics (Matrices, Arrays).

---

## 🛠️ Tech Stack & Dev Environment

* **Primary Language**: C (ANSI C/C99 standard) for low-level memory control and raw performance understanding.
* **Secondary Language**: Python 3.x (primarily for solving LeetCode problems quickly).
* **Compiler**: `gcc` (GNU Compiler Collection).
* **Workspace Settings**: Integrated `.vscode` settings for automating compilation and debugging in Visual Studio Code.

---

## 📂 Repository Structure

The code is categorized logically by data structure or paradigm:

* **`ARRAY`**: General array operations.
  * Reversals, rotations (left/right rotation), insertions, deletions, merging sorted arrays.
  * Moving zeroes to the end, identifying missing numbers, and finding the $1^{\text{st}}, 2^{\text{nd}}, 3^{\text{rd}}$ largest elements.
* **`LINKED LIST`**: Dynamic memory structures.
  * Singly and doubly linked lists (insertions, deletions, conversions from arrays, finding the middle node, removing the $k^{\text{th}}$ element).
* **`HEAP`**: Binary Heaps.
  * Max-Heap and Min-Heap implementations (insertion, get max/min, deletion of max/min, verification checks).
* **`MATRIX`**: 2D grid computations.
  * Matrix addition, scalar multiplication, matrix multiplication, and transposition.
* **`STACK (LIFO)` & `QUEUE (FIFO)`**: Linear helper structures.
  * Array-based and pointer-based implementations.
* **`TREE`**: Hierarchical data structures.
  * Binary Search Tree (BST) operations (insertion, deletion, search, traversals like Inorder, Preorder, Postorder).
* **`SEARCH`**: Searching techniques.
  * Linear Search, Binary Search (iterative and recursive).
* **`LEETCODE`**: Python-based solutions for coding problems (e.g., [238. Product of Array Except Self](file:///D:/vsc/dsa-prep/LEETCODE/238.py)).

---

## 🚀 How to Run the Code

### 1. Compiling and Running C Files
Make sure you have `gcc` installed (via MinGW-w64 on Windows, or through your package manager on macOS/Linux).

To compile a specific file (e.g., [3_array_reversal.c](file:///D:/vsc/dsa-prep/ARRAY/3_array_reversal.c)):
```bash
gcc ARRAY\3_array_reversal.c -o array_reversal.exe
```

To run the compiled executable:
* **Windows**: `.\array_reversal.exe`
* **macOS/Linux**: `./array_reversal`

### 2. Running Python Code
To run Python scripts (e.g., in the `LEETCODE` directory):
```bash
python LEETCODE\238.py
```
