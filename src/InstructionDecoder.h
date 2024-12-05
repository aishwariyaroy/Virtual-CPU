#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include <iostream>
#include <string>

class InstructionDecoder {
public:
    void decode(int instruction) {
        // Basic decoding logic (for illustration purposes)
        int opcode = (instruction >> 24) & 0xFF;  // Extract the opcode (top 8 bits)
        int operand1 = (instruction >> 16) & 0xFF;  // Extract the first operand (next 8 bits)
        int operand2 = (instruction >> 8) & 0xFF;   // Extract the second operand (next 8 bits)
        int result = instruction & 0xFF;             // Extract the result (last 8 bits)

        // For simplicity, print out the decoded instruction
        std::cout << "Decoded Instruction: Opcode = " << opcode
                  << ", Operand1 = " << operand1
                  << ", Operand2 = " << operand2
                  << ", Result = " << result << std::endl;

        // Add more decoding logic here if needed
    }
};

#endif
