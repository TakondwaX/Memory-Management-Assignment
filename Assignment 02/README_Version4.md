# C++ Pointer and Function Pointer Examples

A compact set of C++ examples showing **array indexing**, **pointer arithmetic**, and **function pointers**. Each section includes the code and the expected output.

---

## Contents
1. Array indexing vs. pointer arithmetic  
2. Pointer indexing vs. array indexing  
3. Pointer offset with a negative index  
4. Call-by-reference with arrays (add 100 to each element)  
5. Calling functions and printing their addresses  
6. Using a function name vs. a function pointer  
7. Passing a function pointer as a parameter  
8. Returning a function pointer from a function  

---

## 1) Array indexing vs. pointer arithmetic

```cpp
#include <iostream>

int main() {
    int arr[3] = {7, 14, 21};

    std::cout << arr[2] << "\n\n";
    std::cout << *(arr + 2) << "\n\n";

    return 0;
}
```

**Result:** `21`

---

## 2) Pointer indexing vs. array indexing

```cpp
#include <iostream>

int main() {
    int arr[3] = {7, 14, 21};
    int* ptr = arr;

    std::cout << ptr[1] << "\n\n";
    std::cout << arr[1] << "\n\n";

    return 0;
}
```

**Result:** `14`

---

## 3) Pointer offset with negative index

```cpp
#include <iostream>

int main() {
    char tmp[5] = {1, 2, 3, 4, 5};
    char* arr = tmp + 4;

    std::cout << static_cast<int>(arr[-2]) << "\n\n";

    return 0;
}
```

**Result:** `3`

> `arr` points to `tmp[4]`, so `arr[-2]` accesses `tmp[2]`.

---

## 4) Call-by-reference with arrays (add 100 to each element)

```cpp
#include <iostream>

void addNumber(int* ptr) {
    for (int i = 0; i < 10; ++i) {
        ptr[i] += 100;
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << ">> Before function call <<\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << (i == 9 ? '\n' : ' ');
    }
    std::cout << "\n";

    addNumber(arr);

    std::cout << ">> After function call <<\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << (i == 9 ? '\n' : ' ');
    }
    std::cout << "\n";

    return 0;
}
```

**Result:**  
Before: `1 2 3 4 5 6 7 8 9 10`  
After: `101 102 103 104 105 106 107 108 109 110`

---

# Function Pointer Examples

---

## 5) Calling functions and printing their addresses

```cpp
#include <iostream>

void funcOne() {
    std::cout << "funcOne was called!\n";
}

void funcTwo() {
    std::cout << "funcTwo was called!\n";
}

int main() {
    funcOne();
    funcTwo();

    std::cout << "Address of funcOne : " << reinterpret_cast<void*>(funcOne) << "\n";
    std::cout << "Address of funcTwo : " << reinterpret_cast<void*>(funcTwo) << "\n";

    return 0;
}
```

**Result (example):**
```
funcOne was called!
funcTwo was called!
Address of funcOne : 0x...
Address of funcTwo : 0x...
```

> Addresses vary by run/system.

---

## 6) Using a function name vs. a function pointer

```cpp
#include <iostream>

int adder(int n1, int n2) {
    return n1 + n2;
}

int main() {
    int (*fPtr)(int, int) = adder;

    std::cout << "Using a name of function : " << adder(10, 20) << "\n";
    std::cout << "Using a function pointer : " << fPtr(10, 20) << "\n";

    return 0;
}
```

**Result:** `30` for both calls

---

## 7) Passing a function pointer as a parameter

```cpp
#include <iostream>

int adder(int n1, int n2) {
    std::cout << "Adder was called: ";
    return n1 + n2;
}

int divider(int n1, int n2) {
    std::cout << "Divider was called: ";
    return n1 / n2;
}

void printResult(int n1, int n2, int (*fPtr)(int, int)) {
    std::cout << fPtr(n1, n2) << "\n";
}

int main() {
    int num1 = 10;
    int num2 = 5;

    printResult(num1, num2, adder);
    printResult(num1, num2, divider);

    return 0;
}
```

**Result:**
```
Adder was called: 15
Divider was called: 2
```

---

## 8) Returning a function pointer from a function

```cpp
#include <iostream>

void func1() {
    std::cout << "func1 was called!\n";
}

void func2() {
    std::cout << "func2 was called!\n";
}

void (*whatFunction(int sel))() {
    if (sel == 1) return func1;
    if (sel == 2) return func2;
    return nullptr;
}

int main() {
    void (*fPtr)();

    fPtr = whatFunction(1);
    if (fPtr) fPtr();

    fPtr = whatFunction(2);
    if (fPtr) fPtr();

    std::cout << "\n";
    return 0;
}
```

**Result:**
```
func1 was called!
func2 was called!
```