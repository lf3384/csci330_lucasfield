1. Problem Set 2-1
Starter Code:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    int cents;  // Store as cents to avoid floating-point issues

public:
    // Constructor: Money(dollars, cents) or Money(total_cents)
    Money(int dollars = 0, int cents = 0) : cents(dollars * 100 + cents) {}
    explicit Money(int total_cents) : cents(total_cents) {}

    // TODO: Implement these operators
    // Addition
    Money operator+(const Money& other) const {
        // Your implementation here
    }

    // Subtraction
    Money operator-(const Money& other) const {
        // Your implementation here
    }

    // Compound addition
    Money& operator+=(const Money& other) {
        // Your implementation here
    }

    // Compound subtraction
    Money& operator-=(const Money& other) {
        // Your implementation here
    }

    // Equality comparison
    bool operator==(const Money& other) const {
        // Your implementation here
    }

    // Less than comparison
    bool operator<(const Money& other) const {
        // Your implementation here
    }

    // Display function (we'll make this an operator later)
    void print() const {
        cout << "$" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100;
    }

    // Getter for testing
    int get_cents() const { return cents; }
};

int main() {
    Money wallet(25, 50);  // $25.50
    Money coffee(4, 75);   // $4.75
    Money lunch(12, 30);   // $12.30

    cout << "Starting amount: ";
    wallet.print();
    cout << endl;

    // Test your operators
    Money after_coffee = wallet - coffee;
    cout << "After buying coffee: ";
    after_coffee.print();
    cout << endl;

    after_coffee -= lunch;
    cout << "After buying lunch: ";
    after_coffee.print();
    cout << endl;

    Money total_spent = coffee + lunch;
    cout << "Total spent: ";
    total_spent.print();
    cout << endl;

    // Test comparisons
    if (after_coffee < Money(10, 0)) {
        cout << "Running low on money!" << endl;
    }

    return 0;
}
```
Updated Code:
```cpp
#include <iomanip>
#include <iostream>
using namespace std;

class Money {
 private:
  int cents;  // Store as cents to avoid floating-point issues

 public:
  // Constructor: Money(dollars, cents)
  Money(int dollars = 0, int cents_part = 0) : cents(dollars * 100 + cents_part) {}

  // Addition
  Money operator+(const Money& other) const {
    Money result;
    result.cents = this->cents + other.cents;
    return result;
  }

  // Subtraction
  Money operator-(const Money& other) const {
    Money result;
    result.cents = this->cents - other.cents;
    return result;
  }

  // Compound addition
  Money& operator+=(const Money& other) {
    cents += other.cents;
    return *this;
  }

  // Compound subtraction
  Money& operator-=(const Money& other) {
    cents -= other.cents;
    return *this;
  }

  // Equality comparison
  bool operator==(const Money& other) const {
    return cents == other.cents;
  }

  // Less than comparison
  bool operator<(const Money& other) const {
    return cents < other.cents;
  }

  // Display function (we'll make this an operator later)
  void print() const {
    cout << "$" << cents / 100 << "." << setfill('0') << setw(2) << cents % 100;
  }

  // Getter for testing
  int get_cents() const { return cents; }
};

int main() {
  Money wallet(25, 50);  // $25.50
  Money coffee(4, 75);   // $4.75
  Money lunch(12, 30);   // $12.30

  cout << "Starting amount: ";
  wallet.print();
  cout << endl;

  // Test your operators
  Money after_coffee = wallet - coffee;
  cout << "After buying coffee: ";
  after_coffee.print();
  cout << endl;

  after_coffee -= lunch;
  cout << "After buying lunch: ";
  after_coffee.print();
  cout << endl;

  Money total_spent = coffee + lunch;
  cout << "Total spent: ";
  total_spent.print();
  cout << endl;

  // Test comparisons
  if (after_coffee < Money(10, 0)) {
    cout << "Running low on money!" << endl;
  }

  return 0;
}
```
Implemented different operators.
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
7/problem_set02$ ./problem2-1
Starting amount: $25.50
After buying coffee: $20.75
After buying lunch: $8.45
Total spent: $17.05
Running low on money!
```
2. Problem 2-2:
Starter Code:
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    // TODO: Implement these operators

    // Vector addition
    Vector2D operator+(const Vector2D& other) const {
        // Your implementation here
    }

    // Vector subtraction
    Vector2D operator-(const Vector2D& other) const {
        // Your implementation here
    }

    // Scalar multiplication (vector * scalar)
    Vector2D operator*(double scalar) const {
        // Your implementation here
    }

    // Dot product (return scalar)
    double operator*(const Vector2D& other) const {
        // Your implementation here
    }

    // Compound addition
    Vector2D& operator+=(const Vector2D& other) {
        // Your implementation here
    }

    // Equality (be careful with floating-point comparison!)
    bool operator==(const Vector2D& other) const {
        const double EPSILON = 1e-9;
        // Your implementation here
    }

    // Calculate magnitude
    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    // Normalize vector (make it unit length)
    Vector2D normalize() const {
        double mag = magnitude();
        if (mag == 0.0) return Vector2D(0, 0);
        return Vector2D(x / mag, y / mag);
    }
};

// TODO: Implement this non-member function
// Scalar multiplication (scalar * vector)
Vector2D operator*(double scalar, const Vector2D& vec) {
    // Your implementation here
}

// TODO: Implement stream output operator
ostream& operator<<(ostream& os, const Vector2D& vec) {
    // Format: (x, y)
    // Your implementation here
}

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "v1 + v2: " << sum << endl;

    Vector2D scaled = v1 * 2.0;
    cout << "v1 * 2: " << scaled << endl;

    Vector2D scaled2 = 3.0 * v2;
    cout << "3 * v2: " << scaled2 << endl;

    double dot = v1 * v2;  // dot product
    cout << "v1 · v2: " << dot << endl;

    cout << "Magnitude of v1: " << v1.magnitude() << endl;
    cout << "v1 normalized: " << v1.normalize() << endl;

    return 0;
}
```
Implemented Code:
```cpp
// Vector addition
Vector2D operator+(const Vector2D& other) const {
  return Vector2D(x + other.x, y + other.y);
}

// Vector subtraction
Vector2D operator-(const Vector2D& other) const {
  return Vector2D(x - other.x, y - other.y);
}

// Scalar multiplication (vector * scalar)
Vector2D operator*(double scalar) const {
  return Vector2D(x * scalar, y * scalar);
}

// Dot product (return scalar)
double operator*(const Vector2D& other) const {
  return x * other.x + y * other.y;
}

// Compound addition
Vector2D& operator+=(const Vector2D& other) {
  x += other.x;
  y += other.y;
  return *this;
}

// Equality (be careful with floating-point comparison!)
bool operator==(const Vector2D& other) const {
  const double EPSILON = 1e-9;
  return abs(x - other.x) < EPSILON && abs(y - other.y) < EPSILON;
}

// Scalar multiplication (scalar * vector)
Vector2D operator*(double scalar, const Vector2D& vec) {
  return vec * scalar;
}

ostream& operator<<(ostream& os, const Vector2D& vec) {
  os << "(" << vec.get_x() << ", " << vec.get_y() << ")";
  return os;
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
7/problem_set02$ ./problem2-2
v1: (3, 4)
v2: (1, 2)
v1 + v2: (4, 6)
v1 * 2: (6, 8)
3 * v2: (3, 6)
v1 · v2: 11
Magnitude of v1: 5
v1 normalized: (0.6, 0.8)
```
