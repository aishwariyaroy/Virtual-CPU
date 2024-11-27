#include <iostream>
#include <vector>
#include <string>
#include "Register.h"
#include "ALU.h"
#include "Control_Unit.h"

using namespace std;

int main() {
    // Initialize components
    Register registers(4); // 4 general-purpose registers
    ALU alu;
    ControlUnit controlUnit;

    // Example program with instructions
    vector<string> program = {
        "ADD 0 1 2",  // R0 = R1 + R2
        "SUB 1 2 3",  // R1 = R2 - R3
        "NOT 0",      // R0 = ~R0
        "NOP"         // No operation
    };

    // Initialize registers with sample values
    registers.set(1, 10); // R1 = 10
    registers.set(2, 5);  // R2 = 5
    registers.set(3, 2);  // R3 = 2

    // Execute program
    for (size_t i = 0; i < program.size(); ++i) {
        controlUnit.setProgramCounter(i);
        controlUnit.setInstruction(program[i]);

        // Parse the instruction
        stringstream ss(program[i]);
        string operation;
        int r1, r2, r3;
        ss >> operation;

        // Perform operation
        if (operation == "ADD") {
            ss >> r1 >> r2 >> r3;
            int result = alu.add(registers.get(r2), registers.get(r3));
            registers.set(r1, result);
        } else if (operation == "SUB") {
            ss >> r1 >> r2 >> r3;
            int result = alu.sub(registers.get(r2), registers.get(r3));
            registers.set(r1, result);
        } else if (operation == "NOT") {
            ss >> r1;
            int result = alu.bitwiseNot(registers.get(r1));
            registers.set(r1, result);
        } else if (operation == "NOP") {
            // Do nothing
        }

        // Print state after each instruction
        cout << "PC: " << controlUnit.getProgramCounter()
             << ", IR: " << controlUnit.getInstruction() << endl;
        registers.print();
    }

    return 0;
}
