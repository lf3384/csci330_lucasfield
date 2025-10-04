1. Problem Set 3-1
I used 'g++ -o problemx-x problemx-x.cpp' for a compilation command on all problem sets.
I didn't run into any problems using virtual interfaces with syntax or compilation errors, it was just sort of understanding them logically how they interact. Took a little bit but I understand it.

STARTER CODE
```cpp
#include <iostream>
#include <fstream>
#include <string>

struct Logger {
    virtual ~Logger() = default;
    virtual void log(const std::string& message) const = 0;

    // Convenience function implemented in base
    virtual void log_error(const std::string& message) const {
        log("ERROR: " + message);
    }
};
```
Compiler Error:
```output
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x1b): undefined reference to `main'
collect2: error: ld returned 1 exit status
```
Forgot 'int main()'

2. Problem 3-2
Implement Silent Error Message and call all 3 loggers.
```cpp
struct SilentLogger : Logger {
  void log(const std::string& message) const override {}
};
```


Calling Loggers:
```cpp
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
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week05/probl
em_set_03$ ./problem3-2
[Console] This should go to console.
[Console] ERROR: Console Error Message.
```
File Output:
```output
[File] This should go to file.
[File] ERROR: File error message.
```

3. Problem 3-3
Provided code:
```cpp
struct Application {
    Logger* logger;

    Application(Logger* log) : logger(log) {}

    void run() {
        logger->log("Application started");
        do_some_work();
        logger->log("Application finished");
    }

private:
    void do_some_work() {
        logger->log("Doing important work...");
        // Simulate potential error
        logger->log_error("Something went wrong!");
        logger->log("Recovered from error");
    }
};
```
Implementing to existing code:
```cpp
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

// Implemented starter code for 3-3
struct Application {
  Logger* logger;

  Application(Logger* log) : logger(log) {}

  void run() {
    logger->log("Application started");
    do_some_work();
    logger->log("Application finished");
  }

 private:
  void do_some_work() {
    logger->log("Doing important work...");
    // Simulate potential error
    logger->log_error("Something went wrong!");
    logger->log("Recovered from error");
  }
};
```

Calling Application with each logger in main:
```cpp
  Application logapp(&console);
  logapp.run();

  Application fileapp(&file);
  fileapp.run();

  Application silentapp(&silent);
  silentapp.run();
```
Omitting useless lines
```cpp
Full FINAL code and output:
```cpp
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

// Implemented starter code for 3-3
struct Application {
  Logger* logger;

  Application(Logger* log) : logger(log) {}

  void run() {
    logger->log("Application started");
    do_some_work();
    logger->log("Application finished");
  }

 private:
  void do_some_work() {
    logger->log("Doing important work...");
    // Simulate potential error
    logger->log_error("Something went wrong!");
    logger->log("Recovered from error");
  }
};

int main() {
  ConsoleLogger console;
  FileLogger file("applicaton-logger.txt");
  SilentLogger silent;

  Application logapp(&console);
  logapp.run();

  Application fileapp(&file);
  fileapp.run();

  Application silentapp(&silent);
  silentapp.run();

  return 0;
}
```
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week05/probl
em_set_03$ ./problem3-3
[Console] Application started
[Console] Doing important work...
[Console] ERROR: Something went wrong!
[Console] Recovered from error
[Console] Application finished
```
File Output
```output
[File] Application started
[File] Doing important work...
[File] ERROR: Something went wrong!
[File] Recovered from error
[File] Application finished
```
