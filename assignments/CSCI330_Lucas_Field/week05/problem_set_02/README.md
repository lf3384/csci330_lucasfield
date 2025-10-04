1. Problem Set 2-1:
STARTER CODE:
```cpp
#include <iostream>
#include <cmath>

struct Shape {
    virtual ~Shape() = default;
    // Add your pure virtual functions here

    // This can be implemented in base class
    virtual void display_info() const {
        std::cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};
```
Compiles with no errors.
FINAL CODE:
```cpp
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
```
2. Problem 2-2
STARTER CODE:
```cpp
struct Rectangle : Shape {
    double width, height;

    Rectangle(double w, double h) : width(w), height(h) {}

    // Implement area() and perimeter()
};
```
```cpp
struct Circle : Shape {
    double radius;

    Circle(double r) : radius(r) {}

    // Implement area() and perimeter()
    // Use M_PI for pi (or 3.14159)
};
```
Implemented area() and perimeter():
```cpp
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
  double area() const override {return M_PI * radius * radius;}
  double perimeter() const override {return 2 * M_PI * radius;}
  // Use M_PI for pi (or 3.14159)
};
int main() { return 0; }
```
Final Code:
```cpp
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

  rect.display_info();
  circ.display_info();
  return 0;
}
```
OUTPUT:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week05/probl
em_set_02$ ./problem2-2
Area: 8, Perimeter: 12
Area: 78.5398, Perimeter: 31.4159
```

3. Problem 2-3
Implement arrays, and iterate arrays to display info:
```cpp
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
```
New Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week05/probl
em_set_02$ ./problem2-3
Area: 30, Perimeter: 22
Area: 153.938, Perimeter: 43.9823
Area: 72, Perimeter: 34
```



