```markdown
# **Main Program Documentation**

## **Overview**
The main program serves as the entry point to demonstrate the functionalities of the **Virtual CPU Control Unit**. It integrates the components like the **ControlUnit** to simulate the flow of a CPU's instruction execution process. This program allows you to load instructions, update the program counter, and track the execution flow.

---

## **Features**
1. Initializes the **ControlUnit**.
2. Loads instructions into the control unit.
3. Demonstrates the flow of instruction execution by incrementing the **Program Counter**.
4. Displays the current state of the **Program Counter** and **Instruction Register**.

---

## **Components Used**
### 1. **ControlUnit Class**
Handles the program counter and instruction register operations.

### 2. **Instructions**
A set of predefined assembly-like instructions to simulate a program.

---

## **Program Flow**
1. **Initialize the Control Unit**  
   - A `ControlUnit` object is created.
2. **Load and Execute Instructions**  
   - A list of predefined instructions is iterated through.
   - Each instruction is loaded into the **Instruction Register**.
   - The **Program Counter** is incremented after each instruction.
3. **Display Execution State**  
   - The state of the program counter and instruction register is printed for each instruction.

## **Expected Output**
```plaintext
Program Counter: 0
Instruction Register: LOAD R1, 0x10
----------------------
Program Counter: 1
Instruction Register: ADD R1, R2, R3
----------------------
Program Counter: 2
Instruction Register: STORE R1, 0x20
----------------------
Program Counter: 3
Instruction Register: JMP 0x05
----------------------
Program Counter: 4
Instruction Register: NOP
----------------------
```

---

## **How to Run the Program**
1. **Set Up Environment**  
   - Ensure you have a C++ compiler (e.g., g++) installed.
2. **Create a File**  
   - Save the program in a file named `main.cpp`.
3. **Compile the Program**  
   ```bash
   g++ main.cpp -o main
   ```
4. **Run the Program**  
   ```bash
   ./main
   ```

---

## **Explanation**
1. **Instruction Loading**: Each instruction from the `instructions` list is loaded into the control unit using `setInstruction`.
2. **Program Counter Update**: The program counter is updated after every instruction using `incrementProgramCounter`.
3. **State Printing**: The program counter and instruction register are displayed using the `print` function.
4. **Iteration**: The process continues until all instructions are executed.
