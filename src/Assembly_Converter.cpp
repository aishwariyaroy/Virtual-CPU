#include <iostream>
#include <unordered_map>
#include <sstream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

// Define opcodes and register mappings
unordered_map<string, string> opcodes = {
    {"ADD", "0001"}, {"SUB", "0010"}, {"LOAD", "0011"},
    {"STORE", "0100"}, {"JMP", "0101"}, {"CMP", "0110"},
    {"AND", "0111"}, {"OR", "1000"}, {"NOT", "1001"},
    {"MOV", "1010"}, {"NOP", "1011"}
};

unordered_map<string, string> registers = {
    {"R1", "01"}, {"R2", "10"}, {"R3", "11"}
};

// Convert a hexadecimal address to 8-bit binary string
string hexToBinary8(const string &hexAddress) {
    int value = stoi(hexAddress, nullptr, 16);
    return bitset<8>(value).to_string();
}

// Convert a single line of assembly code to machine code
string convertToMachineCode(const string &line) {
    stringstream ss(line);
    string instruction, op1, op2, op3;
    
    ss >> instruction >> op1;

    // Start with opcode
    string machineCode = opcodes[instruction];

    if (instruction == "NOP") {
        return machineCode; // NOP has no operands
    }

    // Process different instruction formats
    if (instruction == "ADD" || instruction == "SUB" || instruction == "AND" || instruction == "OR") {
        ss >> op2 >> op3;
        machineCode += registers[op1] + registers[op2] + registers[op3];
    } else if (instruction == "NOT") {
        machineCode += registers[op1];
    } else if (instruction == "MOV" || instruction == "CMP") {
        ss >> op2;
        machineCode += registers[op1] + registers[op2];
    } else if (instruction == "LOAD" || instruction == "STORE") {
        ss >> op2;
        machineCode += registers[op1] + hexToBinary8(op2);
    } else if (instruction == "JMP") {
        machineCode += hexToBinary8(op1);
    }

    return machineCode;
}

int main() {
    vector<string> assemblyCode;
    string line;

    cout << "Enter assembly code line by line (type END to finish):" << endl;

    // Read assembly code lines
    while (getline(cin, line)) {
        if (line == "END") break;
        assemblyCode.push_back(line);
    }

    cout << "\nMachine Code Output:\n";
    for (const string &codeLine : assemblyCode) {
        cout << convertToMachineCode(codeLine) << endl;
    }

    return 0;
}
