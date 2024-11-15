# Instruction Set for Virtual CPU

This guide details the instruction set and format used by the virtual CPU to execute core operations.

---

## Instruction Structure

Each instruction includes:
- **Opcode**: Defines the operation type (e.g., ADD, LOAD).
- **Operands**: Specifies the registers or memory addresses involved in the operation.

---

## Instructions and Formats

### 1. **ADD** - Addition
   - **Format**: `ADD R1, R2, R3`
   - **Purpose**: Adds values in `R2` and `R3`, storing the result in `R1`.
   - **Opcode**: `0001`
   - **Encoding Example**: `ADD R1, R2, R3` → `0001 01 10 11`

### 2. **SUB** - Subtraction
   - **Format**: `SUB R1, R2, R3`
   - **Purpose**: Subtracts value in `R3` from `R2`, with the result in `R1`.
   - **Opcode**: `0010`
   - **Encoding Example**: `SUB R1, R2, R3` → `0010 01 10 11`

### 3. **LOAD** - Load from Memory
   - **Format**: `LOAD R1, Address`
   - **Purpose**: Loads data from a specific memory address into `R1`.
   - **Opcode**: `0011`
   - **Encoding Example**: `LOAD R1, 0x0A` → `0011 01 00001010`

### 4. **STORE** - Store to Memory
   - **Format**: `STORE R1, Address`
   - **Purpose**: Saves data from `R1` to a specified memory address.
   - **Opcode**: `0100`
   - **Encoding Example**: `STORE R1, 0x0A` → `0100 01 00001010`

### 5. **JMP** - Jump to Address
   - **Format**: `JMP Address`
   - **Purpose**: Redirects the program counter to the given address.
   - **Opcode**: `0101`
   - **Encoding Example**: `JMP 0x0A` → `0101 00001010`

### 6. **CMP** - Compare
   - **Format**: `CMP R1, R2`
   - **Purpose**: Compares values in `R1` and `R2`, setting the status flags based on the result.
   - **Opcode**: `0110`
   - **Encoding Example**: `CMP R1, R2` → `0110 01 10`

### 7. **AND** - Logical AND
   - **Format**: `AND R1, R2, R3`
   - **Purpose**: Executes a bitwise AND on `R2` and `R3`, storing the output in `R1`.
   - **Opcode**: `0111`
   - **Encoding Example**: `AND R1, R2, R3` → `0111 01 10 11`

### 8. **OR** - Logical OR
   - **Format**: `OR R1, R2, R3`
   - **Purpose**: Performs a bitwise OR on `R2` and `R3`, saving the result in `R1`.
   - **Opcode**: `1000`
   - **Encoding Example**: `OR R1, R2, R3` → `1000 01 10 11`

### 9. **NOT** - Logical NOT
   - **Format**: `NOT R1`
   - **Purpose**: Flips all bits in `R1`, storing the result in `R1`.
   - **Opcode**: `1001`
   - **Encoding Example**: `NOT R1` → `1001 01`

### 10. **MOV** - Move Data
   - **Format**: `MOV R1, R2`
   - **Purpose**: Transfers data from `R2` to `R1`.
   - **Opcode**: `1010`
   - **Encoding Example**: `MOV R1, R2` → `1010 01 10`

### 11. **NOP** - No Operation
   - **Format**: `NOP`
   - **Purpose**: Does nothing; used to insert pauses or timi
