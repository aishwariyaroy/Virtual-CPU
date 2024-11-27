# **Main Program Documentation**

## **Overview**
The `main.cpp` file demonstrates the integration and simulation of a simple processor comprising an **ALU**, **Registers**, and a **Control Unit**. It processes a set of instructions and simulates their execution step-by-step.

---

## **Key Components**
1. **ALU (Arithmetic Logic Unit)**  
   - Performs arithmetic and logical operations.  
2. **Registers**  
   - Stores intermediate and final results.  
3. **Control Unit**  
   - Manages program control flow and tracks the currently executing instruction.  

---

## **Instruction Set**
1. **ADD r1 r2 r3**  
   - Adds the values in registers `r2` and `r3`, then stores the result in `r1`.
2. **SUB r1 r2 r3**  
   - Subtracts the value in `r3` from `r2`, then stores the result in `r1`.
3. **NOT r1**  
   - Performs a bitwise NOT operation on the value in `r1`.
4. **NOP**  
   - No operation; simply increments the program counter.

---

## **Workflow**
1. **Instruction Parsing**  
   - Instructions are read and parsed from a vector of strings representing a program.  
2. **Execution**  
   - **Control Unit**: Loads the instruction into the instruction register.  
   - **ALU**: Executes the specified operation.  
   - **Registers**: Updates with the result of the ALU operation.  
3. **State Updates**  
   - The program counter is incremented after each instruction.  
   - The current state of the registers and program counter is printed for each step.  

---

## **Example Output**
### Initial Conditions:
- **Registers**: All initialized to default values.  
- **Program Counter**: Starts at `0`.  

### Execution Simulation:  
1. **Instruction:** `ADD R0, R1, R2`  
   - **Program Counter (PC):** `0`  
   - **Instruction Register (IR):** `ADD 0 1 2`  
   - **Registers:** `R0=2, R1=1, R2=1, R3=1`  

2. **Instruction:** `SUB R1, R2, R3`  
   - **PC:** `1`  
   - **IR:** `SUB 1 2 3`  
   - **Registers:** `R0=2, R1=0, R2=1, R3=1`  

3. **Instruction:** `NOT R0`  
   - **PC:** `2`  
   - **IR:** `NOT 0`  
   - **Registers:** `R0=-3, R1=0, R2=1, R3=1`  

4. **Instruction:** `NOP`  
   - **PC:** `3`  
   - **IR:** `NOP`  
   - **Registers:** `R0=-3, R1=0, R2=1, R3=1`  

---

## **Conclusion**
This program effectively simulates a basic CPU operation by integrating an ALU, control unit, and registers. It demonstrates the execution of a simple instruction set and the progression of the program counter, enabling a step-by-step understanding of processor behavior.
```