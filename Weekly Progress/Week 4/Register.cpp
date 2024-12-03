#include "Register.h"
#include <iostream>

Registers::Registers(int size) : reg(size, 0) {}

void Registers::setValue(int index, int value) {
    reg[index] = value;
}

int Registers::getValue(int index) const {
    return reg[index];
}

void Registers::printRegisters() const {
    for (size_t i = 0; i < reg.size(); ++i) {
        std::cout << "R" << i << ": " << reg[i] << " ";
    }
    std::cout << std::endl;
}
