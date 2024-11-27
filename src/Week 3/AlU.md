# **Building the ALU (Arithmetic Logic Unit) Documentation**

## **What is an ALU?**
The Arithmetic Logic Unit (ALU) is the part of the CPU that handles basic math (like adding and subtracting) and logic (like AND and OR operations). It’s the brain of your CPU for calculations.

---

## **What Will the ALU Do?**
Our ALU will:
- Perform **arithmetic**: 
  - Addition (`ADD`)
  - Subtraction (`SUB`)
- Perform **logic**:
  - AND (`AND`)
  - OR (`OR`)
  - NOT (`NOT`)

---

## **How Does the ALU Work?**
1. **Input**: The ALU gets two numbers (`A` and `B`) and an operation (`opcode`).
2. **Process**: Based on the operation (`opcode`), the ALU performs the correct calculation.
3. **Output**: The ALU gives back the result.

---

## **How to Write It in Code?**

### **Step 1: Create the ALU Function**
This function takes:
- Two numbers (`A` and `B`)
- The operation (`opcode`)

It calculates the result and returns it.

### **Step 2: Check the Operation**
The ALU will:
- Add if the opcode is `ADD`
- Subtract if the opcode is `SUB`
- Perform logical operations like AND, OR, or NOT.

---

## **Simple ALU Code**
Here’s the code in C++:

```cpp
#include <iostream>
#include <string>
using namespace std;

// ALU Function
int ALU(int A, int B, string opcode) {
    if (opcode == "ADD") {
        return A + B; // Addition
    } else if (opcode == "SUB") {
        return A - B; // Subtraction
    } else if (opcode == "AND") {
        return A & B; // Logical AND
    } else if (opcode == "OR") {
        return A | B; // Logical OR
    } else if (opcode == "NOT") {
        return ~A;    // Logical NOT
    } else {
        cout << "Invalid operation!" << endl;
        return 0;
    }
}

// Example Usage
int main() {
    int A = 5, B = 3;
    cout << "ADD: " << ALU(A, B, "ADD") << endl; // Output: 8
    cout << "SUB: " << ALU(A, B, "SUB") << endl; // Output: 2
    cout << "AND: " << ALU(A, B, "AND") << endl; // Output: 1
    cout << "OR: " << ALU(A, B, "OR") << endl;   // Output: 7
    cout << "NOT: " << ALU(A, 0, "NOT") << endl; // Output: -6
    return 0;
}
```

---

## **Steps to Test It**

1. **Create a File**: 
   Save the code in a file called `ALU.cpp`.

2. **Compile the Code**: 
   Open a terminal and run:
   ```bash
   g++ ALU.cpp -o ALU
   ```

3. **Run the Program**:
   ```bash
   ./ALU
   ```

4. **Check the Output**:
   You should see:
   ```
   ADD: 8
   SUB: 2
   AND: 1
   OR: 7
   NOT: -6
   ```

---

## **What’s Next?**
- Add new operations like `MUL` (Multiplication) or `DIV` (Division).
- Test the ALU with different inputs to ensure it works correctly.
