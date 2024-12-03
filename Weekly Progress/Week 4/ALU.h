#ifndef ALU_H
#define ALU_H

#include <string>
class ALU {
public:
    int performOperation(const std::string& opcode, int operand1, int operand2);
};

#endif // ALU_H
