#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include <string>

class ControlUnit {
private:
    int programCounter;
    std::string instructionRegister;

public:
    ControlUnit();
    void fetchInstruction(const std::string& instruction);
    void incrementProgramCounter();
    int getProgramCounter() const;
    std::string getInstruction() const;
    void printState() const;
};

#endif // CONTROL_UNIT_H
