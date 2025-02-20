# Virtual CPU Documentation

## Overview
The Virtual CPU is a software-based processor that emulates fundamental CPU functions, such as arithmetic calculations, memory handling, instruction control, and I/O processing. It consists of several key components: an Arithmetic Logic Unit (ALU), Registers, Memory, a Control Unit, and I/O Modules.

## Components

### 1. Arithmetic Logic Unit (ALU)
The ALU executes mathematical and logical computations on input data.

#### Methods
- **`compute(operation, operand1, operand2)`**
  - Performs the given operation on specified operands.
  - **Supported Operations:** `ADD, SUB, MUL, DIV, AND, OR, NOT`
  - **Returns:** Binary string representing the computed result.
  - **Example:**
    ```cpp
    ALU alu;
    std::string result = alu.compute("ADD", 5, 3);
    ```

### 2. Control Unit (CU)
Manages instruction execution by tracking the program counter and control signals.

#### Methods
- **`getCounter()`**: Retrieves the current program counter value.
- **`setCounter(value)`**: Updates the program counter.
- **`incrementCounter()`**: Increases the program counter.
- **`loadInstruction(instruction)`**: Stores the current instruction.
- **`fetchInstruction()`**: Retrieves the stored instruction.

### 3. Registers
Temporary storage for intermediate values used in execution.

#### Methods
- **`read(index)`**: Returns the value of a specific register.
- **`write(index, value)`**: Updates a register with a new value.
- **Example:**
    ```cpp
    Registers registers(4);
    registers.write(0, 10);
    ```

### 4. Memory
Handles data and instruction storage.

#### Methods
- **`store(address, data)`**: Saves data at a specific memory location.
- **`load(address)`**: Retrieves data from a memory location.
- **Example:**
    ```cpp
    Memory memory;
    memory.store(100, 42);
    ```

### 5. I/O Modules
Handles input and output operations.

#### Methods
- **`getInput(input)`**: Captures user input.
- **`displayOutput(output)`**: Shows output.
- **Example:**
    ```cpp
    IODevices io;
    io.displayOutput("Hello World");
    ```

### 6. Instruction Processing
Manages execution via a fetch-decode-execute cycle.

#### Methods
- **`fetch()`**: Retrieves the upcoming instruction.
- **`decode(instruction)`**: Extracts the operation and operands.
- **`execute(operation, operand1, operand2)`**: Executes the given instruction.

### 7. Execution Pipeline
Handles sequential processing of instructions.

#### Methods
- **`parse(input, operation, operand1, operand2)`**: Converts user input into structured instruction elements.
- **`fetchInstruction(controlUnit)`**: Simulates instruction retrieval.
- **`decodeInstruction(instruction, operation, operand1, operand2)`**: Interprets the instruction.
- **`run(operation, operand1, operand2, alu, registers, controlUnit, memory, ioInstructions, ioDevices)`**: Executes the decoded instruction.

## Example Usage
```cpp
#include "VirtualCPU.h"

int main() {
    ALU alu;
    ControlUnit controlUnit;
    Memory memory;
    Pipeline pipeline;
    IODevices ioDevices;
    IOInstructions ioInstructions;
    Registers registers(4);

    while (true) {
        std::string input;
        ioDevices.getInput(input);
        controlUnit.loadInstruction(input);
        pipeline.fetchInstruction(controlUnit);
        
        std::string operation, operand1, operand2;
        pipeline.decodeInstruction(controlUnit.fetchInstruction(), operation, operand1, operand2);
        pipeline.run(operation, operand1, operand2, alu, registers, controlUnit, memory, ioInstructions, ioDevices);
        
        if (operation == "RET") {
            break;
        }
    }
    return 0;
}
```

## Example Execution
Enter input: 5+5
R0=00001010 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a 
Display: Result: 10
PC: 1, ZF: 0
Enter input: ADD(R1+R2)
Invalid instruction format: ADD(R1+R2)
R0=00001010 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a 
Display: Result: 10
PC: 2, ZF: 0
Enter input: R1*R2
R0=00011001 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a [3]=19 
Display: Result: 25
PC: 3, ZF: 0
Enter input: CALL(2)
R0=00011001 R1=00000010 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a [3]=19 
Display: Result: 25
PC: 3, ZF: 0
Enter input: 6-6
R0=00000000 R1=00000110 R2=00000110 R3=00000000 
Memory Content (Hexadecimal):

Display: Result: 0
PC: 1, ZF: 1

## Conclusion
The Virtual CPU effectively simulates processor functions, providing an educational framework for understanding CPU operations. Through ALU computations, memory storage, instruction processing, and I/O management, it ensures efficient handling of user-provided commands.

