#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <iostream>

class Register {
private:
    std::vector<int> registers;

public:
    Register(int size) : registers(size, 0) {}

    void set(int index, int value) {
        if (index >= 0 && index < registers.size()) {
            registers[index] = value;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < registers.size()) {
            return registers[index];
        }
        return 0; // Default value for invalid index
    }

    void print() const {
        for (size_t i = 0; i < registers.size(); ++i) {
            std::cout << "R" << i << ": " << registers[i] << std::endl;
        }
    }
};

#endif
