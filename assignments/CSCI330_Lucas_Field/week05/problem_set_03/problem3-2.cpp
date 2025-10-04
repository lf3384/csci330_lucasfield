#include <fstream>
#include <iostream>
#include <string>

struct Logger {
  virtual ~Logger() = default;
  virtual void log(const std::string& message) const = 0;

  // Convenience function implemented in base
  virtual void log_error(const std::string& message) const {
    log("ERROR: " + message);
  }
};

struct ConsoleLogger : Logger {
  void log(const std::string& message) const override {
    std::cout << "[Console] " << message << "\n";
  }
};

struct FileLogger : Logger {
  std::string filename;

  FileLogger(const std::string& file) : filename(file) {}

  void log(const std::string& message) const override {
    std::ofstream out(filename, std::ios::app);
    if (out) {
      out << "[File] " << message << "\n";
    }
  }
};

struct SilentLogger : Logger {
  void log(const std::string& message) const override {}
};

int main() {
  ConsoleLogger console;
  FileLogger file("logger.txt");
  SilentLogger silent;

  console.log("This should go to console.");
  console.log_error("Console Error Message.");

  file.log("This should go to file.");
  file.log_error("File error message.");

  silent.log("This shouldn't be seen.");
  silent.log_error("Silent Error Message, shouldn't be seen.");

  return 0;
}