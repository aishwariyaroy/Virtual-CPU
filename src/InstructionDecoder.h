#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

class InstructionDecoder {
private:
    int opcode;
    int operand1;
    int operand2;
    int destination;

public:
    InstructionDecoder() : opcode(0), operand1(0), operand2(0), destination(0) {}

    void decode(int instruction) {
        opcode = (instruction >> 24) & 0xFF;         // Extract the first 8 bits as opcode
        operand1 = (instruction >> 16) & 0xFF;      // Extract the next 8 bits as operand1
        operand2 = (instruction >> 8) & 0xFF;       // Extract the next 8 bits as operand2
        destination = instruction & 0xFF;           // Extract the last 8 bits as destination
    }

    int getOpcode() const { return opcode; }
    int getOperand1() const { return operand1; }
    int getOperand2() const { return operand2; }
    int getDestination() const { return destination; }
};

#endif // INSTRUCTION_DECODER_H
