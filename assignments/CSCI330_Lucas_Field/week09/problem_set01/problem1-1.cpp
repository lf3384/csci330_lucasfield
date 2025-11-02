#include <cstdio>
#include <iostream>

double add(double a, double b) { return a + b; }

double subtract(double a, double b) { return a - b; }

double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
  if (b == 0) {
    std::cout << "Error: Division by zero!\n";
    return 0;
  }
  return a / b;
}

int main() {
  double (*operations[])(double, double) = {add, subtract, multiply, divide};
  const char* op_names[] = {"Add", "Subtract", "Multiply", "Divide"};
  const char* op_symbols[] = {"+", "-", "*", "/"};  // Add this array

  double a, b;
  int choice;

  std::cout << "Enter two numbers: ";
  std::cin >> a >> b;

  std::cout << "\nSelect operation:\n";
  for (int i = 0; i < 4; i++) {
    std::cout << i + 1 << ". " << op_names[i] << "\n";
  }
  std::cout << "Choice: ";
  std::cin >> choice;

  if (choice < 1 || choice > 4) {
    std::cout << "Invalid choice!\n";
    return 1;
  }

  double result = operations[choice - 1](a, b);

  if (choice != 4 || b != 0) {
    std::cout << a << " " << op_symbols[choice - 1] << " " << b << " = "
              << result << "\n";
  }

  return 0;
}