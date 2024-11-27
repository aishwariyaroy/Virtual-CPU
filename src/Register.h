#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>

class Register {
private:
    std::vector<int> registers;

public:
    // Constructor to initialize the registers
    Register(size_t count = 4) {
        registers.resize(count, 0); // Default: 4 registers initialized to 0
    }

    // Get the value of a specific register
    int get(size_t index) const {
        if (index >= registers.size()) {
            throw std::out_of_range("Register index out of range");
        }
        return registers[index];
    }

    // Set the value of a specific register
    void set(size_t index, int value) {
        if (index >= registers.size()) {
            throw std::out_of_range("Register index out of range");
        }
        registers[index] = value;
    }

    // Print the current state of all registers
    void print() const {
        for (size_t i = 0; i < registers.size(); ++i) {
            std::cout << "R" << i << "=" << registers[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // REGISTER_H
