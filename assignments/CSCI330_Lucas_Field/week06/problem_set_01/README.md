1. Problem 1-1:
Starter Code:
```cpp
#include <iostream>
using namespace std;

// Your template function here
template<typename T>
T absolute_value(T value) {
    // Implement this
}

int main() {
    cout << "absolute_value(-5) = " << absolute_value(-5) << endl;
    cout << "absolute_value(-3.14) = " << absolute_value(-3.14) << endl;
    cout << "absolute_value(42) = " << absolute_value(42) << endl;
    return 0;
}
```
Implemented:
```cpp
  if (value < 0) {
    return -value;
  }
  return value;
```
This makes any value below zero positive, and if the value is already positive, it just returns the value as is.

OUTPUT:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
6/problem_set_01$ ./problem1-1
absolute_value(-5) = 5
absolute_value(-3.14) = 3.14
absolute_value(42) = 42
```

2. Problem 1-2
Starter Code:
```cpp
#include <iostream>
using namespace std;

// Your template function here
template<typename T1, typename T2>
auto safe_divide(T1 numerator, T2 denominator) -> decltype(numerator/denominator) {
    // Implement this
}

int main() {
    cout << "10 / 2 = " << safe_divide(10, 2) << endl;
    cout << "10.5 / 2 = " << safe_divide(10.5, 2) << endl;
    cout << "10 / 0 = " << safe_divide(10, 0) << " (division by zero)" << endl;
    return 0;
}
```
Implemented:
```cpp
  if (denominator == 0) {
    return 0;
  }
  return numerator / denominator;
```
This if statement checks if denominator is 0, because you can't divide by zero, it just will return 0.
If not 0, normal division will happen.