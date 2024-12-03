#include "Control_Unit.h"
#include <iostream>

ControlUnit::ControlUnit() : programCounter(0), instructionRegister("") {}

void ControlUnit::fetchInstruction(const std::string& instruction) {
    instructionRegister = instruction;
}

void ControlUnit::incrementProgramCounter() {
    programCounter++;
}

int ControlUnit::getProgramCounter() const {
    return programCounter;
}

std::string ControlUnit::getInstruction() const {
    return instructionRegister;
}

void ControlUnit::printState() const {
    std::cout << "PC: " << programCounter << ", IR: " << instructionRegister << std::endl;
}
