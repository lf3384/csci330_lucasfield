1. Problem 2-1
Starter Code:
```cpp
#include <iostream>
#include <stdexcept>

double safe_divide(double numerator, double denominator) {
    // TODO: Implement with proper exception throwing
}

int main() {
    double a, b;
    char operation;

    while (true) {
        std::cout << "Enter calculation (a op b) or 'q' to quit: ";

        if (!(std::cin >> a >> operation >> b)) {
            if (std::cin.eof()) break;
            // TODO: Handle invalid input
        }

        try {
            // TODO: Implement calculator with exception handling
        } catch (/* TODO: Add appropriate catch blocks */) {
            // TODO: Handle specific exceptions
        }
    }

    return 0;
}
```
Implemented:
```cpp
  if (denominator == 0.0) {
    throw std::runtime_error("Division by zero error");
  }
  return numerator / denominator;

  std::istringstream iss(input);
    if (!(iss >> a >> operation >> b)) {
      // Handle invalid input
      std::cout << "Invalid input. Please enter numbers and an operator." << std::endl;
      continue;

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
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
8/problem_set02$ ./problem2-1
Simple Calculator (enter 'q' to quit)
Enter calculation (a or b) or 'q' to quit: 2 + 4
Result: 6
Enter calculation (a or b) or 'q' to quit: 4 / 2
Result: 2
Enter calculation (a or b) or 'q' to quit: 4 * 2
Result: 8
Enter calculation (a or b) or 'q' to quit: 4 -2
Result: 2
Enter calculation (a or b) or 'q' to quit: 1
Invalid input. Please enter numbers and an operator.
Enter calculation (a or b) or 'q' to quit: q
Calculator closed.
```

2. Problem 2-2
Starter Code:
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class FileProcessor {
private:
    std::ifstream file;
    std::string filename;

public:
    // TODO: Constructor - acquire resource (open file)
    FileProcessor(const std::string& filename) {
        // TODO: Open file and handle errors
    }

    // TODO: Destructor - release resource (close file)
    ~FileProcessor() {
        // TODO: Ensure file is closed
    }

    // TODO: Delete copy constructor and assignment (RAII best practice)

    int count_lines() {
        // TODO: Count lines in file
        // TODO: Reset file position after counting
    }

    int count_words() {
        // TODO: Count words in file
    }

    int count_characters() {
        // TODO: Count characters in file
    }
};

// Test function that demonstrates RAII even with exceptions
void test_file_processing(const std::string& filename) {
    try {
        FileProcessor processor(filename);

        std::cout << "Lines: " << processor.count_lines() << std::endl;
        std::cout << "Words: " << processor.count_words() << std::endl;
        std::cout << "Characters: " << processor.count_characters() << std::endl;

        // Simulate an exception
        if (processor.count_lines() > 100) {
            throw std::runtime_error("File too large!");
        }

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        // File should still be properly closed due to RAII
    }
}

int main() {
    // TODO: Create a test file or use existing file
    // TODO: Test with valid and invalid filenames
    // TODO: Demonstrate RAII behavior

    return 0;
}
```
Implemented:
```cpp
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class FileProcessor {
 private:
  std::ifstream file;
  std::string filename;

 public:
  // TODO: Constructor - acquire resource (open file)
  FileProcessor(const std::string& fname) : filename(fname) {
    file.open(filename);
    if (!file.is_open()) {
      throw std::runtime_error("Failed to open file: " + filename);
    }
  }

  // TODO: Destructor - release resource (close file)
  ~FileProcessor() {
    if (file.is_open()) {
      file.close();
      std::cout << "File closed: " << filename << std::endl;
    }
  }

  FileProcessor(const FileProcessor&) = delete;
  FileProcessor& operator=(const FileProcessor&) = delete;

  int count_lines() {
    int count = 0;
    std::string line;

    file.clear();
    file.seekg(0);

    while (std::getline(file, line)) {
      count++;
    }

    file.clear();
    file.seekg(0);

    return count;
  }

  int count_words() {
    int count = 0;
    std::string word;


    file.clear();
    file.seekg(0);

    while (file >> word) {
      count++;
    }


    file.clear();
    file.seekg(0);

    return count;
  }

  int count_characters() {
    int count = 0;
    char ch;


    file.clear();
    file.seekg(0);

    while (file.get(ch)) {
      count++;
    }


    file.clear();
    file.seekg(0);

    return count;
  }
};

// Test function that demonstrates RAII even with exceptions
void test_file_processing(const std::string& filename) {
  try {
    FileProcessor processor(filename);

    std::cout << "Lines: " << processor.count_lines() << std::endl;
    std::cout << "Words: " << processor.count_words() << std::endl;
    std::cout << "Characters: " << processor.count_characters() << std::endl;

    // Simulate an exception
    if (processor.count_lines() > 100) {
      throw std::runtime_error("File too large!");
    }

  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

int main() {
  std::cout << "Creating test file..." << std::endl;
  {
    std::ofstream test_file("test.txt");
    test_file << "Hello World!\n";
    test_file << "This is a test file.\n";
    test_file << "It has multiple lines.\n";
  }

  std::cout << "\n--- Testing with valid file ---" << std::endl;
  test_file_processing("test.txt");

  std::cout << "\n--- Testing with invalid file ---" << std::endl;
  test_file_processing("nonexistent.txt");

  std::cout << "\n--- Demonstrating RAII behavior ---" << std::endl;
  try {
    FileProcessor proc("test.txt");
    std::cout << "File opened successfully" << std::endl;
    std::cout << "Lines: " << proc.count_lines() << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << "Scope ended - destructor called automatically" << std::endl;

  return 0;
}

```
Output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
8/problem_set02$ ./problem2-2
Creating test file...

--- Testing with valid file ---
Lines: 3
Words: 11
Characters: 57
File closed: test.txt

--- Testing with invalid file ---
Error: Failed to open file: nonexistent.txt

--- Demonstrating RAII behavior ---
File opened successfully
Lines: 3
File closed: test.txt
```