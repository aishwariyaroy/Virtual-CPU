#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>
#include <string>

class InstructionMemory {
private:
    std::vector<std::string> instructions;

public:
    InstructionMemory(const std::vector<std::string>& program);
    std::string fetchInstruction(int programCounter) const;
};

#endif // INSTRUCTION_MEMORY_H
