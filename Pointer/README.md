# C++ Pointer Operations Demo

---

## Overview
This C++ program demonstrates various pointer operations, including pointer initialization, pointer arithmetic, pointer comparison, and pointer-to-pointer concepts. The code includes commented-out sections that showcase different pointer-related functionalities, with the main active code focusing on pointer arithmetic.

---

## Prerequisites
- C++ compiler (e.g., g++, clang++)
- Basic understanding of C++ syntax and pointers

---

## Code Structure
The program is written in C++ and includes the following key components:

1. **Header Files**:
   - `<iostream>`: For input/output operations.
   - `<vector>`: Included but not used in the current code.

2. **Commented-Out Function**:
   ```cpp
   int changeVal(int &ptr) {
       ptr = 20;
   }
   ```
   - A function that modifies a variable's value via a reference parameter (not used in the main program).

3. **Main Function**:
   - The active code demonstrates pointer arithmetic:
     ```cpp
     int a = 10;
     int *ptr1 = &a;
     int *ptr2 = ptr1 + 2;
     ```
     - `ptr1` points to the address of variable `a`.
     - `ptr2` is set to `ptr1 + 2`, which advances the pointer by two integer-sized memory locations.

4. **Commented-Out Sections**:
   - **Pointer Initialization**:
     ```cpp
     int* ptr = &a;
     cout << ptr << endl;
     cout << *ptr << endl;
     ```
     - Shows how to initialize a pointer and dereference it to access the value.
   - **Pointer to Pointer**:
     ```cpp
     int** ptr2 = &ptr;
     cout << ptr2 << endl;
     ```
     - Demonstrates a pointer that stores the address of another pointer.
   - **Null Pointer**:
     ```cpp
     int* ptr3 = NULL;
     cout << ptr3 << endl;
     ```
     - Shows how to declare a null pointer.
   - **Pointer Arithmetic**:
     ```cpp
     int* ptr = &a;
     cout << "Original = " << ptr << endl;
     ptr++;
     cout << "ptr++ = " << ptr << endl;
     ```
     - Illustrates incrementing and decrementing a pointer to move through memory locations.
   - **Pointer Subtraction**:
     ```cpp
     cout << ptr2 - ptr1 << endl;
     ```
     - Calculates the number of elements between two pointers.
   - **Pointer Comparison**:
     ```cpp
     cout << (ptr1 < ptr2) << endl;
     ```
     - Demonstrates comparison operators (`<`, `>`, `<=`, `>=`, `==`) with pointers.

---

## How to Run
1. Save the code in a file named `pointers.cpp`.
2. Compile the program using a C++ compiler:
   ```bash
   g++ pointers.cpp -o pointers
   ```
3. Run the executable:
   ```bash
   ./pointers
   ```

## Output
The active code in `main` does not produce output since it only declares pointers without printing. To see output, uncomment the desired sections (e.g., pointer arithmetic or comparison) and recompile. Example output for pointer arithmetic:
```
Original = 0x7ffee4c0a4ac
ptr++ = 0x7ffee4c0a4b0
ptr++ = 0x7ffee4c0a4b4
ptr-- = 0x7ffee4c0a4b0
ptr-- = 0x7ffee4c0a4ac
```

---

## Notes
- The commented-out sections can be uncommented one at a time to test specific pointer operations.
- Ensure proper understanding of pointer arithmetic, as it depends on the size of the data type (e.g., `int` typically occupies 4 bytes on most systems).
- Be cautious with pointer operations to avoid accessing invalid memory locations.

## License
This project is unlicensed and provided for educational purposes.