```markdown
# **Register Documentation**

## **Overview**
Registers are essential components of the Virtual CPU, providing fast, temporary storage for operands, results, and intermediate values during execution.

---

## **Details**
1. **General-Purpose Registers**  
   - **R0, R1, R2, R3**: Four registers for storing integer values.
   - **Width**: Each register stores one integer.  
   - **Initialization**: All registers start at `0`.

2. **Functions**  
   - **Arithmetic**: Used in instructions like `ADD` and `SUB`.
   - **Logical**: Supports operations like `NOT`.  
   - **Efficiency**: Faster access than main memory.

---

## **Example**
- **Before Execution**: `R0=0, R1=0, R2=1, R3=2`
- **Instruction**: `ADD R0, R2, R3`  
- **After Execution**: `R0=3, R1=0, R2=1, R3=2`

---

## **Benefits**
- **Speed**: Quicker than memory access.  
- **Flexibility**: General-purpose use.  
- **Efficiency**: Reduces memory dependency.