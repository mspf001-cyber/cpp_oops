# DSC-04: Object Oriented Programming with C++
### BSc (Hons) Computer Science — Practical File

---

## Course Info

| Field | Details |
|---|---|
| Course Code | DSC-04 |
| Credits | 4 (3L + 0T + 1P) |
| Standard | C++17 |
| Compiler | g++ (GCC) |

---

## Compiling & Running

```bash
# Compile any practical
g++ -std=c++17 -o practical1 practical1.cpp

# Run it
./practical1

# For programs using command line arguments (Practical 1, 3)
./practical1 10
./practical3 Hello World
```

---

## Practicals

| File | Topic | Key Concepts |
|---|---|---|
| `practical1.cpp` | Series Sum (CLI args) | Command line args, loops, alternating series |
| `practical2.cpp` | Remove Duplicates from Array | Nested loops, linear search |
| `practical3.cpp` | Alphabet Occurrence Count (CLI) | CLI args, arrays, `tolower()` |
| `practical4.cpp` | String Manipulation (menu-driven) | Pointers, char arrays, manual string ops |
| `practical5.cpp` | Merge Two Sorted Arrays | Two-pointer merge |
| `practical6.cpp` | Binary Search | Recursion, iteration |
| `practical7.cpp` | GCD of Two Numbers | Euclidean algorithm, recursion |
| `practical8.cpp` | Matrix Class | Classes, exception handling, operator logic |
| `practical9.cpp` | Inheritance: Person→Student/Employee | Inheritance, virtual functions, runtime polymorphism |
| `practical10.cpp` | Triangle Class | Exception handling, function overloading, Heron's formula |
| `practical11.cpp` | Student File I/O | Binary file I/O, `fstream`, `reinterpret_cast` |
| `practical12.cpp` | Copy File (Remove Whitespace) | Text file I/O, `isspace()` |

---

## Practical Details

### Practical 1 — Series Sum
Computes the alternating harmonic series:
```
S = 1 - 1/2 + 1/3 - 1/4 + ... (n terms)
```
If `n` is not passed as CLI argument, the program prompts for it.

### Practical 2 — Remove Duplicates
Takes an integer array as input and prints a new array with all duplicate elements removed, preserving original order.

### Practical 3 — Alphabet Count
Counts occurrences of each alphabet in text passed as CLI arguments. Output is a table showing only alphabets that appear at least once.

### Practical 4 — String Manipulation (7 operations)
All operations implemented manually without `<cstring>` built-ins:
- **a.** Print memory address of each character
- **b.** Concatenate two strings
- **c.** Compare two strings (returns equal / s1<s2 / s1>s2)
- **d.** String length using pointer arithmetic
- **e.** Convert lowercase to uppercase
- **f.** Reverse a string in-place
- **g.** Insert a string into another at a given index

### Practical 5 — Merge Sorted Arrays
Merges two user-provided sorted arrays into a single sorted array using the standard two-pointer merge technique.

### Practical 6 — Binary Search
Searches for an element in a sorted array using:
- Recursive binary search
- Iterative binary search

Both results displayed side by side.

### Practical 7 — GCD
Calculates GCD using the Euclidean algorithm in:
- Recursive form
- Iterative form

### Practical 8 — Matrix Operations
`Matrix` class with internal 10×10 grid:
- **Sum:** throws `invalid_argument` if dimensions don't match
- **Product:** throws `invalid_argument` if cols(A) ≠ rows(B)
- **Transpose:** always valid
All exceptions thrown by class methods and caught in `main()`.

### Practical 9 — Inheritance & Runtime Polymorphism
Class hierarchy:
```
Person (base)
├── Student  (name, course, marks, year)
└── Employee (name, department, salary)
```
Each class overrides `display()`. Array of `Person*` pointers demonstrates vtable-based runtime dispatch.

### Practical 10 — Triangle Class
- Validates: all sides > 0 AND triangle inequality holds (throws `invalid_argument` otherwise)
- `area()` — Heron's formula for any triangle
- `area(base, height)` — overloaded for right-angled triangle

### Practical 11 — Student File I/O
Stores 5 `Student` objects into a binary file (`students.dat`) and reads them back, displaying all records.

### Practical 12 — File Copy (No Whitespace)
Reads a source text file character by character and writes only non-whitespace characters to the destination file. Reports count of characters written and whitespace removed.

---

## Recommended Books

1. Stephen Prata — *C++ Primer Plus*, 6th Ed., Pearson India, 2015
2. E. Balagurusamy — *Object Oriented Programming with C++*, 8th Ed., McGraw-Hill, 2020
3. D.S. Malik — *C++ Programming: From Problem Analysis to Program Design*, 6th Ed., Cengage, 2013
