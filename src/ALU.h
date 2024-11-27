#ifndef ALU_H
#define ALU_H

class ALU {
public:
    int add(int a, int b) {
        return a + b;
    }

    int bitwiseNot(int a) {
        return ~a;
    }
};

#endif
