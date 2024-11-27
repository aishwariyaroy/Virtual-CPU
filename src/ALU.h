#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <stdexcept>

class ALU {
public:
    // Perform addition
    int add(int operand1, int operand2) {
        return operand1 + operand2;
    }

    // Perform subtraction
    int subtract(int operand1, int operand2) {
        return operand1 - operand2;
    }

    // Perform bitwise NOT
    int bitwiseNot(int operand) {
        return ~operand;
    }

    // Perform bitwise AND
    int bitwiseAnd(int operand1, int operand2) {
        return operand1 & operand2;
    }

    // Perform bitwise OR
    int bitwiseOr(int operand1, int operand2) {
        return operand1 | operand2;
    }

    // Execute an ALU operation based on the opcode
    int execute(const std::string& operation, int operand1, int operand2 = 0) {
        if (operation == "ADD") {
            return add(operand1, operand2);
        } else if (operation == "SUB") {
            return subtract(operand1, operand2);
        } else if (operation == "NOT") {
            return bitwiseNot(operand1);
        } else if (operation == "AND") {
            return bitwiseAnd(operand1, operand2);
        } else if (operation == "OR") {
            return bitwiseOr(operand1, operand2);
        } else {
            throw std::invalid_argument("Invalid ALU operation: " + operation);
        }
    }
};

#endif // ALU_H
