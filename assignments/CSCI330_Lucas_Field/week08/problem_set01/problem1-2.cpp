#include <iostream>

int main() {
  int size;
  char mode;

  std::cout << "Enter pattern size (1-10): ";
  std::cin >> size;

  std::cout << "Show all rows (a) or odd rows only (o)? ";
  std::cin >> mode;

  // TODO: Validate inputs
  if (size < 1 || size > 10) {
    std::cout << "Invalid size. Must be 1-10." << std::endl;
  }

  if (mode != 'a' && mode != 'o') {
    std::cout << "Invalid mode. Use 'a' or 'o'." << std::endl;
  }
  // TODO: Generate pattern with nested loops
  // TODO: Use continue for odd-only mode
  for (int i = 1; i <= size; ++i) {
    if (mode == 'o' && i % 2 == 0) {
      continue;
    }
    for (int j = 1; j <= i; ++j) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }

  return 0;
}
