#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(const std::vector<std::string>& program) 
    : instructions(program) {}

std::string InstructionMemory::fetchInstruction(int programCounter) const {
    return instructions[programCounter];
}
