#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ControlUnit {
private:
    int programCounter;
    string instructionRegister;

public:
    ControlUnit() : programCounter(0), instructionRegister("") {}

    void setProgramCounter(int value) {
        programCounter = value;
    }

    int getProgramCounter() const {
        return programCounter;
    }

    void incrementProgramCounter() {
        programCounter++;
    }

    void setInstruction(const string& instruction) {
        instructionRegister = instruction;
    }

    string getInstruction() const {
        return instructionRegister;
    }

    void print() const {
        cout << "Program Counter: " << programCounter << endl;
        cout << "Instruction Register: " << instructionRegister << endl;
    }
};

int main() {
    // Step 1: Initialize the Control Unit
    ControlUnit controlUnit;

    // Step 2: Define a list of instructions
    vector<string> instructions = {
        "LOAD R1, 0x10",
        "ADD R1, R2, R3",
        "STORE R1, 0x20",
        "JMP 0x05",
        "NOP"
    };

    // Step 3: Execute each instruction
    for (const string& instruction : instructions) {
        controlUnit.setInstruction(instruction);
        controlUnit.print();
        controlUnit.incrementProgramCounter();
        cout << "----------------------" << endl;
    }

    return 0;
}