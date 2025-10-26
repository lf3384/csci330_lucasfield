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

    // Reset to beginning of file
    file.clear();
    file.seekg(0);

    while (file >> word) {
      count++;
    }

    // Reset file position after counting
    file.clear();
    file.seekg(0);

    return count;
  }

  int count_characters() {
    int count = 0;
    char ch;

    // Reset to beginning of file
    file.clear();
    file.seekg(0);

    while (file.get(ch)) {
      count++;
    }

    // Reset file position after counting
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
