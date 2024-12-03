#include <iostream>
#include <sstream>
#include "ALU.h"
#include "Register.h"
#include "Control_Unit.h"
#include "InstructionMemory.h"

int main() {
    // Initialize components
    ALU alu;
    Registers registers(4); // 4 registers: R0, R1, R2, R3
    ControlUnit controlUnit;

    // Define a simple program
    std::vector<std::string> program = {
        "LOAD R0 5", "LOAD R1 10", "ADD R2 R0 R1", "NOP"
    };
    InstructionMemory memory(program);

    // Simulate Fetch-Decode-Execute
    while (controlUnit.getProgramCounter() < program.size()) {
        // Fetch
        std::string instruction = memory.fetchInstruction(controlUnit.getProgramCounter());
        controlUnit.fetchInstruction(instruction);

        // Decode and Execute
        std::string opcode, reg1, reg2, reg3;
        std::istringstream iss(instruction);
        iss >> opcode >> reg1;

        if (opcode == "LOAD") {
            int value;
            iss >> value;
            registers.setValue(std::stoi(reg1.substr(1)), value);
        } else if (opcode == "ADD") {
            iss >> reg2 >> reg3;
            int result = alu.performOperation(
                opcode,
                registers.getValue(std::stoi(reg2.substr(1))),
                registers.getValue(std::stoi(reg3.substr(1)))
            );
            registers.setValue(std::stoi(reg1.substr(1)), result);
        } else if (opcode == "NOP") {
            // Do nothing
        }

        // Print state
        controlUnit.printState();
        registers.printRegisters();

        // Increment Program Counter
        controlUnit.incrementProgramCounter();
    }

    return 0;
}
