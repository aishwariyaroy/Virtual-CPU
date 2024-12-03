#include "ALU.h"
#include <iostream>

int ALU::performOperation(const std::string& opcode, int operand1, int operand2) {
    if (opcode == "ADD") return operand1 + operand2;
    if (opcode == "SUB") return operand1 - operand2;
    if (opcode == "AND") return operand1 & operand2;
    if (opcode == "OR") return operand1 | operand2;
    if (opcode == "NOT") return ~operand1;
    return 0; // Default
}
