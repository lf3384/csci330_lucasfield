1.  Problem 1-1:
Starter Code:
```cpp
#include <iostream>
#include <string>

class DataProcessor {
private:
    int* data;
    size_t size;

public:
    DataProcessor(size_t n) : size(n) {
        data = new int[n];
        for (size_t i = 0; i < n; ++i) {
            data[i] = static_cast<int>(i * i);
        }
    }

    ~DataProcessor() {
        delete[] data;
    }

    // Copy constructor and assignment operator needed but missing!

    void print_data() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int get_value(size_t index) const {
        if (index < size) return data[index];
        return -1;
    }
};
```
Implemented:
'std::unique_ptr'
```cpp
class DataProcessor {
 private:
  std::unique_ptr<int[]> data;
  size_t size;

 public:
  DataProcessor(size_t n) : data(std::make_unique<int[]>(n)), size(n) {
    for (size_t i = 0; i < n; ++i) {
      data[i] = static_cast<int>(i * i);
    }
  }

  void print_data() const {
    for (size_t i = 0; i < size; ++i) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }

  int get_value(size_t index) const {
    if (index < size) return data[index];
    return -1;
  }
};
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set01$ ./problem1-1
0 1 4 9 16
0 1 4 9 16
Value at index 3: 9
```
2. Problem 1-2
Starter Code:
```cpp
#include <memory>
#include <iostream>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override {
        std::cout << "Drawing circle with radius " << radius << std::endl;
    }
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override {
        std::cout << "Drawing rectangle " << width << "x" << height << std::endl;
    }
    double area() const override {
        return width * height;
    }
};

class ShapeFactory {
public:
    // TODO: Implement this method
    static std::unique_ptr<Shape> create_shape(const std::string& type, double param1, double param2 = 0);
};
```
Implemented:
ShapeFactory class
```cpp
class ShapeFactory {
public:
    static std::unique_ptr<Shape> create_shape(
        const std::string& type,
        double param1,
        double param2 = 0.0
    ) {
        if (type == "circle") {
            return std::make_unique<Circle>(param1);
        }
        else if (type == "rectangle") {
            return std::make_unique<Rectangle>(param1, param2);
        }
        else {
            return nullptr;
        }
    }
};
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set01$ ./problem1-2
Drawing a Circle with radius 5
Area: 78.5397
Drawing a Rectangle with width 3 and height 4
Area: 12
Unknown shape type
```
3. Problem 1-3
Starter Code:
```cpp
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

class FileManager {
private:
    // TODO: Use unique_ptr with custom deleter for FILE*
    std::unique_ptr<FILE, decltype(&std::fclose)> file;

public:
    // TODO: Implement constructor that opens file
    FileManager(const std::string& filename, const std::string& mode);

    // TODO: Implement write method
    bool write(const std::string& data);

    // TODO: Implement read method
    std::string read_line();

    // TODO: Implement method to check if file is open
    bool is_open() const;
};
```
Implemented:
Custom Deleter for FILE*
```cpp
FileManager(const std::string& filename, const std::string& mode)
    : file(std::fopen(filename.c_str(), mode.c_str()), &std::fclose)
```
Write Method
```cpp
bool write(const std::string& data) {
    if (!is_open()) {
        return false;
    }

    size_t written = std::fwrite(data.c_str(), sizeof(char), data.size(), file.get());
    return written == data.size();
```
Line Read Method:
```cpp
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

    return "";  /
}
```
IsOpen check
```cpp
bool is_open() const {
    return file != nullptr;
}
```
Output (in test.txt)
```output
Hello, Smart Pointers!
RAII is awesome!
```