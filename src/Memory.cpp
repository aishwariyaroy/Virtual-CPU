#include "Memory.h"

// Constructor to initialize memory sizes and set up segmentation
Memory::Memory(int dataSize, int instructionSize)
    : dataSegmentStart(0), instructionSegmentStart(dataSize) {
    dataMemory.resize(dataSize, 0);             // Initialize data memory with zeros
    instructionMemory.resize(instructionSize, 0); // Initialize instruction memory with zeros
    memorySize = dataSize + instructionSize;   // Total memory size
}

// Set a value in the data memory
void Memory::setData(int index, int value) {
    if (index >= 0 && index < dataMemory.size()) {
        dataMemory[index] = value;
    } else {
        std::cerr << "Error: Data memory index out of bounds" << std::endl;
    }
}

// Get a value from the data memory
int Memory::getData(int index) const {
    if (index >= 0 && index < dataMemory.size()) {
        return dataMemory[index];
    }
    std::cerr << "Error: Data memory index out of bounds" << std::endl;
    return 0;
}

// Set a value in the instruction memory
void Memory::setInstruction(int index, int value) {
    if (index >= 0 && index < instructionMemory.size()) {
        instructionMemory[index] = value;
    } else {
        std::cerr << "Error: Instruction memory index out of bounds" << std::endl;
    }
}

// Get a value from the instruction memory
int Memory::getInstruction(int index) const {
    if (index >= 0 && index < instructionMemory.size()) {
        return instructionMemory[index];
    }
    std::cerr << "Error: Instruction memory index out of bounds" << std::endl;
    return 0;
}

// Fetch the instruction from instruction memory using the program counter
int Memory::fetchInstruction(int programCounter) const {
    if (programCounter >= 0 && programCounter < instructionMemory.size()) {
        return instructionMemory[programCounter];
    }
    std::cerr << "Error: Invalid program counter" << std::endl;
    return 0;
}

// Write a value to memory with address mapping
void Memory::writeMemory(int address, int value) {
    if (address >= dataSegmentStart && address < dataSegmentStart + dataMemory.size()) {
        dataMemory[address - dataSegmentStart] = value; // Write to data memory
    } else if (address >= instructionSegmentStart && address < instructionSegmentStart + instructionMemory.size()) {
        instructionMemory[address - instructionSegmentStart] = value; // Write to instruction memory
    } else {
        std::cerr << "Error: Memory address out of bounds" << std::endl;
    }
}

// Read a value from memory with address mapping
int Memory::readMemory(int address) const {
    if (address >= dataSegmentStart && address < dataSegmentStart + dataMemory.size()) {
        return dataMemory[address - dataSegmentStart]; // Read from data memory
    } else if (address >= instructionSegmentStart && address < instructionSegmentStart + instructionMemory.size()) {
        return instructionMemory[address - instructionSegmentStart]; // Read from instruction memory
    }
    std::cerr << "Error: Memory address out of bounds" << std::endl;
    return 0;
}

// Print the current state of the data memory
void Memory::printDataMemory() const {
    std::cout << "Data Memory:" << std::endl;
    for (size_t i = 0; i < dataMemory.size(); ++i) {
        std::cout << "Data[" << i << "]: " << dataMemory[i] << std::endl;
    }
}

// Print the current state of the instruction memory
void Memory::printInstructionMemory() const {
    std::cout << "Instruction Memory:" << std::endl;
    for (size_t i = 0; i < instructionMemory.size(); ++i) {
        std::cout << "Instruction[" << i << "]: " << instructionMemory[i] << std::endl;
    }
}
