# **Control Unit Documentation**

## **Overview**
The `ControlUnit` class is responsible for managing the flow of instruction execution in the virtual CPU. It tracks the current instruction using the **Program Counter (PC)** and stores the instruction being executed in the **Instruction Register (IR)**.

---

## **Private Members**
1. **`int programCounter`**  
   - Stores the index of the current instruction in memory.

2. **`string instructionRegister`**  
   - Holds the current instruction being executed.

---

## **Public Member Functions**

### **1. ControlUnit()**
- **Description**:  
  Initializes the program counter to `0` and clears the instruction register.  

---

### **2. void setProgramCounter(int value)**  
- **Description**:  
  Sets the program counter to a specific value.  

- **Parameters**:  
  - `value`: The new value to assign to the program counter.  

---

### **3. int getProgramCounter() const**  
- **Description**:  
  Retrieves the current value of the program counter.  

- **Return Value**:  
  - The value of the program counter.  

---

### **4. void incrementProgramCounter()**  
- **Description**:  
  Increments the program counter by `1`.  

---

### **5. void setInstruction(const string& instruction)**  
- **Description**:  
  Updates the instruction register with a new instruction.  

- **Parameters**:  
  - `instruction`: The instruction to store in the instruction register.  

---

### **6. string getInstruction() const**  
- **Description**:  
  Retrieves the instruction stored in the instruction register.  

- **Return Value**:  
  - The currently stored instruction.  

---

### **7. void print() const**  
- **Description**:  
  Displays the current values of the program counter and instruction register in a readable 