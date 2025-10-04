#include <cmath>
#include <iostream>

struct Shape {
  virtual ~Shape() = default;
  // Add your pure virtual functions here
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  // This can be implemented in base class
  virtual void display_info() const {
    std::cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n";
  }
};
int main() { return 0; }