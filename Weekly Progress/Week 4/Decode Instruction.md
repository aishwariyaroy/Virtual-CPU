# Instruction Decoding - Week 4

---

## Purpose
Instruction decoding is a critical step in the Fetch-Decode-Execute cycle of a CPU. During this stage, the fetched binary instruction is interpreted to identify the operation to be performed (opcode) and the registers or memory locations involved.

---

## Instruction Format
Each instruction in our virtual CPU is represented as a 16-bit binary value. The breakdown of the instruction format is as follows:

| Bits   | Field Name | Description                                 |
|--------|------------|---------------------------------------------|
| 15-12  | Opcode     | Specifies the operation (e.g., ADD, SUB).  |
| 11-8   | Reg1       | Destination register.                      |
| 7-4    | Reg2       | First source register.                     |
| 3-0    | Reg3       | Second source register.                    |

---

## Decoding Process

1. **Fetch the Instruction:**
   - The `InstructionMemory` provides the instruction stored at the current program counter (PC).

2. **Extract Opcode and Operands:**
   - The binary instruction is divided into its respective fields:
     - **Opcode:** Determines the operation (e.g., ADD or SUB).
     - **Reg1:** Register where the result will be stored.
     - **Reg2:** First operand's register.
     - **Reg3:** Second operand's register.

3. **Interpret Fields:**
   - The `ControlUnit` is responsible for decoding the instruction and extracting the required fields. For example:
     - `Opcode = (instruction >> 12) & 0xF;`
     - `Reg1 = (instruction >> 8) & 0xF;`
     - `Reg2 = (instruction >> 4) & 0xF;`
     - `Reg3 = instruction & 0xF;`

4. **Send Fields to Execution:**
   - After decoding, the opcode and register indices are sent to the `ALU` or other execution units.

---

## Example Instruction Decoding

Consider the instruction: `0b0001001100010000`

- **Binary Representation:** `0001 0011 0001 0000`
- **Fields:**
  - **Opcode:** `0001` → 1 (ADD operation)
  - **Reg1:** `0011` → 3 (Result stored in R3)
  - **Reg2:** `0001` → 1 (First operand from R1)
  - **Reg3:** `0000` → 0 (Second operand from R0)

**Decoded Instruction:** `ADD R3, R1, R0`

---

## Code Implementation

Below is an example of the decoding implementation in the `ControlUnit`:

```cpp
void ControlUnit::decodeInstruction(int instruction, int &opcode, int &reg1, int &reg2, int &reg3) {
    opcode = (instruction >> 12) & 0xF;  // Extract bits 15-12
    reg1 = (instruction >> 8) & 0xF;     // Extract bits 11-8
    reg2 = (instruction >> 4) & 0xF;     // Extract bits 7-4
    reg3 = instruction & 0xF;            // Extract bits 3-0
}
