#include <cstdio>  // For FILE, fopen, fclose, etc.
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class FileManager {
 private:
  std::unique_ptr<FILE, decltype(&std::fclose)> file;

 public:
  FileManager(const std::string& filename, const std::string& mode)
      : file(std::fopen(filename.c_str(), mode.c_str()), &std::fclose) {
    if (!file) {
      std::cerr << "Failed to open file: " << filename << std::endl;
    }
  }

  bool write(const std::string& data) {
    if (!is_open()) {
      return false;
    }

    size_t written =
        std::fwrite(data.c_str(), sizeof(char), data.size(), file.get());
    return written == data.size();
  }

  std::string read_line() {
    if (!is_open()) {
      return "";
    }

    char buffer[1024];
    if (std::fgets(buffer, sizeof(buffer), file.get()) != nullptr) {
      std::string line(buffer);
      if (!line.empty() && line.back() == '\n') {
        line.pop_back();
      }
      return line;
    }

    return "";
  }

  bool is_open() const { return file != nullptr; }
};

int main() {
  {
    FileManager writer("test.txt", "w");
    if (writer.is_open()) {
      writer.write("Hello, Smart Pointers!\n");
      writer.write("RAII is awesome!\n");
    }
  }  // File automatically closed here

  {
    FileManager reader("test.txt", "r");
    if (reader.is_open()) {
      std::cout << "Line 1: " << reader.read_line();
      std::cout << "Line 2: " << reader.read_line();
    }
  }  // File automatically closed here

  return 0;
}