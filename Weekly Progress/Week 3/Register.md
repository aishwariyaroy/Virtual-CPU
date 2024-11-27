# **Register Documentation**

## **Overview**
Registers are key components of the Virtual CPU, enabling fast, temporary data storage for operations and results.

---

## **Details**
### General-Purpose Registers
- **R0, R1, R2, R3**: Used for storing integers.  
- **Initial Value**: All registers are initialized to `0`.  
- **Width**: Each register holds one integer.

---

## **Usage**
- **Arithmetic Operations**: `ADD`, `SUB`, etc.  
- **Logical Operations**: `NOT`, etc.  
- **Example**:  
  - **Before**: `R0=0, R1=0, R2=1, R3=2`  
  - **Instruction**: `ADD R0, R2, R3`  
  - **After**: `R0=3, R1=0, R2=1, R3=2`

---

## **Benefits**
- **Speed**: Faster than accessing main memory.  
- **Efficiency**: Reduces memory dependency.  
- **Flexibility**: Supports a variety of operations.

Registers are critical for the efficient functioning of the Virtual CPU.
```