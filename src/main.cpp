#include <iostream>
#include <string>
#include "ALU.h"
#include "ControlUnit.h"
#include "Registers.h"
#include "Memory.h"
#include "InstructionDecoder.h"

void runWeek3Logic(Memory& memory, ALU& alu, Register& reg) {
    int programCounter = 0;
    int cycleCount = 0;

    std::cout << "\nRunning Week 3 Logic...\n";

    while (programCounter < 2) {  // Simpler example with only 2 instructions
        // Fetch phase
        int instruction = memory.fetchInstruction(programCounter);
        std::cout << "Cycle " << cycleCount++ << " - Fetch: Instruction at PC " << programCounter << " = " << instruction << std::endl;

        // Execute phase
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

        // Print register states
        reg.print();
    }
}

void runWeek4Logic(Memory& memory, ALU& alu, Register& reg, InstructionDecoder& decoder) {
    int programCounter = 0;
    int cycleCount = 0;

    std::cout << "\nRunning Week 4 Logic...\n";

    while (programCounter < 8) {  // Assuming there are 8 instructions
        // Fetch phase
        int instruction = memory.fetchInstruction(programCounter);
        std::cout << "Cycle " << cycleCount++ << " - Fetch: Instruction at PC " << programCounter << " = " << instruction << std::endl;

        // Decode phase
        decoder.decode(instruction);

        // Execute phase
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

        // Print register states
        reg.print();
    }
}

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

    // User selection for Week 3 or Week 4 logic
    int choice;

    // Output prompt
    std::cout << "Select the mode to run:\n";
    std::cout << "1. Week 3 Logic (Basic Fetch-Execute)\n";
    std::cout << "2. Week 4 Logic (Fetch-Decode-Execute)\n";
    std::cout << "Enter your choice: ";

    // Input choice from user
    std::cin >> choice;

    // Check if input failed
    if(std::cin.fail()) {
        std::cout << "Invalid input detected! Exiting program.\n";
        return -1;
    }

    // Handle the user's choice
    if (choice == 1) {
        runWeek3Logic(memory, alu, reg);
    } else if (choice == 2) {
        runWeek4Logic(memory, alu, reg, decoder);
    } else {
        std::cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
