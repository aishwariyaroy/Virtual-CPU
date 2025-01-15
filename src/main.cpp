#include <iostream>
#include <string>
#include "ALU.h"
#include "ControlUnit.h"
#include "Registers.h"
#include "Memory.h"
#include "InstructionDecoder.h"

// Week 3 Logic: Basic Fetch-Execute Cycle
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

// Week 4 Logic: Fetch-Decode-Execute Cycle
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

// Week 5 Logic: Advanced Fetch-Decode-Execute with Opcode and Operands
void runWeek5Logic(Memory& memory, ALU& alu, Register& reg, InstructionDecoder& decoder, ControlUnit& controlUnit) {
    int programCounter = 0;
    int cycleCount = 0;

    std::cout << "\nRunning Week 5 Logic...\n";

    while (programCounter < 8) {  // Assuming there are 8 instructions
        // Fetch phase
        int instruction = memory.fetchInstruction(programCounter);
        std::cout << "Cycle " << cycleCount++ << " - Fetch: Instruction at PC " << programCounter << " = " << instruction << std::endl;

        // Decode phase
        decoder.decode(instruction);

        // Retrieve opcode and operands
        int opcode = decoder.getOpcode();
        int operand1 = decoder.getOperand1();
        int operand2 = decoder.getOperand2();
        int destination = decoder.getDestination();

        // Execute phase based on opcode
        switch (opcode) {
            case 0x01: {  // Add
                int result = alu.add(reg.get(operand1), reg.get(operand2));
                reg.set(destination, result);
                std::cout << "Execute: Add R" << operand1 << " + R" << operand2 << " = " << result << ", store in R" << destination << std::endl;
                break;
            }
            case 0x02: {  // Subtract
                int result = alu.subtract(reg.get(operand1), reg.get(operand2));
                reg.set(destination, result);
                std::cout << "Execute: Subtract R" << operand2 << " from R" << operand1 << " = " << result << ", store in R" << destination << std::endl;
                break;
            }
            case 0x03: {  // Bitwise NOT
                int result = alu.bitwiseNot(reg.get(operand1));
                reg.set(destination, result);
                std::cout << "Execute: Bitwise NOT R" << operand1 << " = " << result << ", store in R" << destination << std::endl;
                break;
            }
            default:
                std::cout << "Execute: No operation for opcode " << opcode << std::endl;
                break;
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

    // Initialize memory with example instructions
    memory.setInstruction(0, 0x01020304);  // Example: Opcode=0x01, operand1=0x02, operand2=0x03, destination=0x04
    memory.setInstruction(1, 0x02030402);  // Example: Opcode=0x02, operand1=0x03, operand2=0x04, destination=0x02
    memory.setInstruction(2, 0x03020101);  // Example: Opcode=0x03, operand1=0x02, operand2=0x01, destination=0x01
    memory.setInstruction(3, 0x00000000);  // No-op
    memory.setInstruction(4, 0x01010101);  // Add operation
    memory.setInstruction(5, 0x02020202);  // Subtract operation
    memory.setInstruction(6, 0x03030303);  // Bitwise NOT operation
    memory.setInstruction(7, 0x00000000);  // No-op

    // Initialize registers (e.g., 4 registers)
    Register reg(4);

    // ALU setup
    ALU alu;

    // Control Unit setup
    ControlUnit controlUnit;

    // Instruction Decoder setup
    InstructionDecoder decoder;

    // User selection for Week 3, 4, or 5 logic
    int choice;

    // Output prompt
    std::cout << "Select the mode to run:\n";
    std::cout << "1. Week 3 Logic (Basic Fetch-Execute)\n";
    std::cout << "2. Week 4 Logic (Fetch-Decode-Execute)\n";
    std::cout << "3. Week 5 Logic (Advanced Fetch-Decode-Execute with Opcode)\n";
    std::cout << "Enter your choice: ";

    // Input choice from user
    std::cin >> choice;

    // Check if input failed
    if (std::cin.fail()) {
        std::cout << "Invalid input detected! Exiting program.\n";
        return -1;
    }

    // Handle the user's choice
    if (choice == 1) {
        runWeek3Logic(memory, alu, reg);
    } else if (choice == 2) {
        runWeek4Logic(memory, alu, reg, decoder);
    } else if (choice == 3) {
        runWeek5Logic(memory, alu, reg, decoder, controlUnit);
    } else {
        std::cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
