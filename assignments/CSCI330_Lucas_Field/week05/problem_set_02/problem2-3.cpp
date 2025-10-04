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
struct Rectangle : Shape {
  double width, height;

  Rectangle(double w, double h) : width(w), height(h) {}

  // Implement area() and perimeter()
  double area() const override { return width * height; }
  double perimeter() const override { return 2 * (width + height); }
};
struct Circle : Shape {
  double radius;

  Circle(double r) : radius(r) {}

  // Implement area() and perimeter()
  double area() const override { return M_PI * radius * radius; }
  double perimeter() const override { return 2 * M_PI * radius; }
  // Use M_PI for pi (or 3.14159)
};
int main() {
  Rectangle rect(2, 4);
  Circle circ(5);

  Shape* shapes[3] = {new Rectangle(5, 6), new Circle(7), new Rectangle(8, 9)};
  for (int i; i < 3; i++) {
    shapes[i]->display_info();
  }
  for (int i; i < 3; i++) {
    delete shapes[i];
  }

  return 0;
}