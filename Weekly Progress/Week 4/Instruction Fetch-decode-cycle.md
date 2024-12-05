# Instruction Fetch-Decode-Execute Cycle

---

## Overview
The **Instruction Fetch-Decode-Execute Cycle** is a critical sequence in CPU operations that processes instructions from memory and executes them. This cycle is repeated continuously to execute a program. The cycle consists of three main stages: **Fetch**, **Decode**, and **Execute**.

---

## Stages of the Cycle

### 1. **Fetch Stage**
   - **Purpose:** Retrieve the instruction from memory.
   - The CPU reads the instruction stored at the memory address indicated by the **Program Counter (PC)**.
   - After fetching, the PC is incremented to point to the next instruction.

   **Code Example:**
   ```cpp
   int instruction = instructionMemory.getInstruction(programCounter);
   programCounter++;
