#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Функция для умножения всех операндов
double multiplyOperands(const std::vector<double>& operands) {
    double result = 1.0;
    for (double operand : operands) {
        result *= operand;
    }
    return result;
}

// Функция для деления первого операнда на остальные
double divideOperands(const std::vector<double>& operands) {
    if (operands.size() < 2) {
        std::cerr << "Error: Division requires at least two operands." << std::endl;
        return 0.0;
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] != 0) {
            result /= operands[i];
        } else {
            std::cerr << "Error: Division by zero." << std::endl;
            return 0.0;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 6) {
        std::cout << "Usage: calculator <operation> <operand1> <operand2> [operand3] [operand4]" << std::endl;
        std::cout << "Supported operations: multiply, divide" << std::endl;
        return 1;
    }

    std::string operation = argv[1];
    std::vector<double> operands;
    for (int i = 2; i < argc; ++i) {
        double operand;
        std::istringstream iss(argv[i]);
        if (!(iss >> operand)) {
            std::cerr << "Error: Invalid operand '" << argv[i] << "'" << std::endl;
            return 1;
        }
        operands.push_back(operand);
    }

    if (operation == "multiply") {
        if (operands.size() < 2 || operands.size() > 4) {
            std::cerr << "Error: For multiplication, the number of operands should be between 2 and 4." << std::endl;
            return 1;
        }
        double result = multiplyOperands(operands);
        std::cout << "Result: " << result << std::endl;
    } else if (operation == "divide") {
        if (operands.size() < 2 || operands.size() > 4) {
            std::cerr << "Error: For division, the number of operands should be between 2 and 4." << std::endl;
            return 1;
        }
        double result = divideOperands(operands);
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Error: Unsupported operation '" << operation << "'" << std::endl;
        return 1;
    }

    return 0;
}
