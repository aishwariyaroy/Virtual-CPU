#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include <string>

class ControlUnit {
private:
    int programCounter;
    std::string instruction;

public:
    ControlUnit() : programCounter(0), instruction("") {}

    void setProgramCounter(int pc) {
        programCounter = pc;
    }

    int getProgramCounter() const {
        return programCounter;
    }

    void setInstruction(const std::string& instr) {
        instruction = instr;
    }

    std::string getInstruction() const {
        return instruction;
    }
};

#endif
