#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <iostream>
#include <stdexcept>

class Memory {
private:
    std::vector<int> dataMemory;  // Stores data memory (RAM)
    std::vector<int> instructionMemory;  // Stores instruction memory (program code)

public:
    // Constructor to initialize memory sizes
    Memory(int dataSize, int instructionSize) {
        dataMemory.resize(dataSize, 0);        // Initialize data memory with zeros
        instructionMemory.resize(instructionSize, 0);  // Initialize instruction memory with zeros
    }

    // Set a value to the data memory at a specific index
    void setData(int index, int value) {
        if (index >= 0 && index < dataMemory.size()) {
            dataMemory[index] = value;
        } else {
            std::cerr << "Error: Data memory index out of bounds" << std::endl;
        }
    }

    // Get a value from the data memory at a specific index
    int getData(int index) const {
        if (index >= 0 && index < dataMemory.size()) {
            return dataMemory[index];
        }
        std::cerr << "Error: Data memory index out of bounds" << std::endl;
        return 0;  // Default value for invalid index
    }

    // Set a value to the instruction memory at a specific index
    void setInstruction(int index, int value) {
        if (index >= 0 && index < instructionMemory.size()) {
            instructionMemory[index] = value;
        } else {
            std::cerr << "Error: Instruction memory index out of bounds" << std::endl;
        }
    }

    // Get an instruction from instruction memory at a specific index
    int getInstruction(int index) const {
        if (index >= 0 && index < instructionMemory.size()) {
            return instructionMemory[index];
        }
        std::cerr << "Error: Instruction memory index out of bounds" << std::endl;
        return 0;  // Default value for invalid index
    }

    // Fetch the instruction from instruction memory using the program counter
    int fetchInstruction(int programCounter) const {
        if (programCounter >= 0 && programCounter < instructionMemory.size()) {
            return instructionMemory[programCounter];
        }
        std::cerr << "Error: Invalid program counter" << std::endl;
        return 0;  // Default value for invalid program counter
    }

    // Print the current state of the data memory
    void printDataMemory() const {
        std::cout << "Data Memory:" << std::endl;
        for (size_t i = 0; i < dataMemory.size(); ++i) {
            std::cout << "Data[" << i << "]: " << dataMemory[i] << std::endl;
        }
    }

    // Print the current state of the instruction memory
    void printInstructionMemory() const {
        std::cout << "Instruction Memory:" << std::endl;
        for (size_t i = 0; i < instructionMemory.size(); ++i) {
            std::cout << "Instruction[" << i << "]: " << instructionMemory[i] << std::endl;
        }
    }
};

#endif  // MEMORY_H
