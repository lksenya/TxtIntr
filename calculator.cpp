#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    // Проверяем, что было передано достаточно аргументов
    if (argc < 3) {
        cout << "Использование: " << argv[0] << " операция операнд1 операнд2 [операнд3 ...]" << endl;
        cout << "Поддерживаемые операции: *, /" << endl;
        return 1;
    }

    // Получаем операцию из первого аргумента
    string operation = argv[1];

    // Получаем операнды из остальных аргументов
    vector<double> operands;
    for (int i = 2; i < argc; i++) {
        double operand = stod(argv[i]);
        operands.push_back(operand);
    }

    // Выполняем операцию
    double result;
    if (operation == "*") {
        result = 1;
        for (double operand : operands) {
            result *= operand;
        }
    } else if (operation == "/") {
        result = operands[0];
        for (int i = 1; i < operands.size(); i++) {
            result /= operands[i];
        }
    } else {
        cout << "Неподдерживаемая операция: " << operation << endl;
        return 1;
    }

    // Выводим результат
    cout << "Результат: " << result << endl;

    return 0;
}
