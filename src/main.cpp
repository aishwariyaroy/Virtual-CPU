#include <iostream>
#include <string>
#include "ALU.h"
#include "Control_Unit.h"
#include "Register.h"
#include "Memory.h"
#include "InstructionDecoder.h"

int main() {
    // Memory setup: 4 data memory locations, 8 instruction memory slots
    Memory memory(4, 8);

    // Initialize memory with example instructions (for illustration)
    memory.setInstruction(0, 0x00000001);  // Example instruction 1
    memory.setInstruction(1, 0x00000002);  // Example instruction 2
    memory.setInstruction(2, 0x00000003);  // Example instruction 3
    memory.setInstruction(3, 0x00000004);  // Example instruction 4
    memory.setInstruction(4, 0x00000005);  // Example instruction 5
    memory.setInstruction(5, 0x00000006);  // Example instruction 6
    memory.setInstruction(6, 0x00000007);  // Example instruction 7
    memory.setInstruction(7, 0x00000008);  // Example instruction 8

    // Initialize registers (e.g., 4 registers)
    Register reg(4);

    // ALU setup
    ALU alu;

    // Control Unit setup
    ControlUnit controlUnit;

    // Instruction Decoder setup
    InstructionDecoder decoder;

    int programCounter = 0;  // Start from the first instruction
    int cycleCount = 0;      // Keep track of the cycles

    // Begin the fetch-decode-execute cycle
    while (programCounter < 8) {  // Assuming there are 8 instructions
        // Fetch phase: Retrieve the instruction at program counter
        int instruction = memory.fetchInstruction(programCounter);
        std::cout << "Cycle " << cycleCount++ << " - Fetch: Instruction at PC " << programCounter << " = " << instruction << std::endl;

        // Decode phase: Decode the instruction using the Instruction Decoder
        decoder.decode(instruction);

        // Execute phase: Execute the instruction using the ALU and registers
        // Example: Perform addition using the ALU, update register values
        if (instruction == 0x00000001) {  // Example: Add registers 0 and 1, store in register 2
            int result = alu.add(reg.get(0), reg.get(1));
            reg.set(2, result);
            std::cout << "Execute: Add R0 + R1 = " << result << ", store in R2" << std::endl;
        } else if (instruction == 0x00000002) {  // Example: Bitwise NOT on register 1, store in register 3
            int result = alu.bitwiseNot(reg.get(1));
            reg.set(3, result);
            std::cout << "Execute: Bitwise NOT on R1 = " << result << ", store in R3" << std::endl;
        } else {
            std::cout << "Execute: No operation for instruction " << instruction << std::endl;
        }

        // Update program counter
        programCounter++;
        std::cout << std::endl;

        // Print register states after each cycle
        reg.print();
    }

    return 0;
}
