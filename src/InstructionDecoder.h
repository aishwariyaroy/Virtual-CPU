#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include <string>
#include <iostream>
#include <sstream>

class InstructionDecoder {
public:
    // Constructor
    InstructionDecoder() {}

    // Decodes the instruction and executes the operation
    void decodeAndExecute(const std::string& instruction, 
                           int* registers, 
                           int& programCounter, 
                           const std::string& currentInstruction) {
        std::stringstream ss(instruction);
        std::string operation;
        int operand1, operand2, resultReg;

        ss >> operation;

        // Decode and execute the instruction
        if (operation == "ADD") {
            ss >> operand1 >> operand2 >> resultReg;
            // Perform ADD: registers[operand1] + registers[operand2] -> registers[resultReg]
            registers[resultReg] = registers[operand1] + registers[operand2];
            std::cout << "ADD: R" << operand1 << " + R" << operand2 << " = R" << resultReg << std::endl;
        } 
        else if (operation == "NOT") {
            ss >> operand1 >> resultReg;
            // Perform NOT: ~registers[operand1] -> registers[resultReg]
            registers[resultReg] = ~registers[operand1];
            std::cout << "NOT: ~R" << operand1 << " = R" << resultReg << std::endl;
        } 
        else {
            // Handle unknown instructions
            std::cerr << "Unknown instruction: " << operation << std::endl;
        }

        // Update program counter (e.g., for the next instruction)
        programCounter++;
    }

    // Fetch and display the current instruction being processed
    void printCurrentInstruction(const std::string& currentInstruction) const {
        std::cout << "Current Instruction: " << currentInstruction << std::endl;
    }

    // Print the current state of the registers
    void printRegisters(const int* registers, int numRegisters) const {
        for (int i = 0; i < numRegisters; ++i) {
            std::cout << "R" << i << ": " << registers[i] << std::endl;
        }
    }
};

#endif
