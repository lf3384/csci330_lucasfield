#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

double safe_divide(double numerator, double denominator) {
  if (denominator == 0.0) {
    throw std::runtime_error("Division by zero error");
  }
  return numerator / denominator;
}

int main() {
  double a, b;
  char operation;

  std::cout << "Simple Calculator (enter 'q' to quit)" << std::endl;

  while (true) {
    std::cout << "Enter calculation (a or b) or 'q' to quit: ";

    // Check for 'q' to quit
    std::string input;
    std::getline(std::cin, input);

    if (input == "q" || input == "Q") {
      break;
    }

    std::istringstream iss(input);
    if (!(iss >> a >> operation >> b)) {
      // Handle invalid input
      std::cout << "Invalid input. Please enter numbers and an operator."
                << std::endl;
      continue;
    }

    try {
      double result;

      // Implement calculator with exception handling
      switch (operation) {
        case '+':
          result = a + b;
          std::cout << "Result: " << result << std::endl;
          break;
        case '-':
          result = a - b;
          std::cout << "Result: " << result << std::endl;
          break;
        case '*':
          result = a * b;
          std::cout << "Result: " << result << std::endl;
          break;
        case '/':
          result = safe_divide(a, b);
          std::cout << "Result: " << result << std::endl;
          break;
        default:
          throw std::invalid_argument("Unknown operator");
      }

    } catch (const std::runtime_error& e) {
      // Handle division by zero
      std::cout << "Error: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
      // Handle invalid operator
      std::cout << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
      // Catch any other exceptions
      std::cout << "Unexpected error: " << e.what() << std::endl;
    }
  }

  std::cout << "Calculator closed." << std::endl;
  return 0;
}
