#include <iostream>

int main() {
    double num1, num2;
    char operation;

    // Prompt user for input
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform calculation based on the chosen operation
    switch(operation) {
        case '+':
            std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
            break;
        case '/':
            // Check if the denominator is not zero
            if (num2 != 0)
                std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
            else
                std::cout << "Error: Division by zero is not allowed.\n";
            break;
        default:
            std::cout << "Error: Invalid operation selected.\n";
    }

    return 0;
}

