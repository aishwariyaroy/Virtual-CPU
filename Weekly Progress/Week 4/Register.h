#ifndef REGISTER_H
#define REGISTER_H

#include <vector>

class Registers {
private:
    std::vector<int> reg;

public:
    Registers(int size);
    void setValue(int index, int value);
    int getValue(int index) const;
    void printRegisters() const;
};

#endif // REGISTER_H
