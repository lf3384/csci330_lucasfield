1. Problem 3-1
Starter Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

// General template
template<typename T>
class Printer {
public:
    static void print(const T& value) {
        cout << "Value: " << value << endl;
    }
};

// TODO: Add specializations for bool and string
// Hint: template<> class Printer<bool> { ... };

int main() {
    Printer<int>::print(42);
    Printer<bool>::print(true);
    Printer<string>::print("hello world");
    Printer<double>::print(3.14);
    return 0;
}
```
Implemented:
```cpp
template <>
class Printer<bool> {
 public:
  static void print(const bool& value) {
    cout << "Boolean: " << (value ? "true" : "false") << endl;
  }
};

template <>
class Printer<string> {
 public:
  static void print(const string& value) {
    cout << "String: " << value << endl;
  }
};
```
Specialization to print Boolean and String, still works with int and double.
Output:
```output
 ./problem3-1
Value: 42
Boolean: true
String: hello world
Value: 3.14
```

2. Problem 3-2
Starter Code:
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Calculator {
private:
    T value;
public:
    Calculator(T initial) : value(initial) {}

    void add(T amount) {
        value += amount;
    }

    void print() {
        cout << "Result: " << value << endl;
    }

    // Bug 1: Missing template syntax in method definition outside class
    T getValue();
};

T Calculator::getValue() {  // This line has errors
    return value;
}

// Bug 2: Trying to use undefined operation
template<typename T>
void processValue(T val) {
    val.doSomething();  // Not all types have this method
}

int main() {
    Calculator<int> calc(10);
    calc.add(5);
    calc.print();
    cout << "Final value: " << calc.getValue() << endl;

    // Bug 3: This will cause compilation error
    processValue(42);  // int doesn't have doSomething()

    return 0;
}
```
Changes Made:
--Template syntax is wrong
```cpp
T Calculator::getValue() {  // This line has errors
    return value;
}
```
--Fixed Template syntax
```cpp
template <typename T>
T Calculator<T>::getValue() {  // This line has errors
  return value;
}
```
---Got rid of of doSomething(), just printed values instead.
```cpp
// Bug 2: Trying to use undefined operation
template<typename T>
void processValue(T val) {
    val.doSomething();  // Not all types have this method
}
```
---Fixed Version
```cpp
// Bug 2: Trying to use undefined operation
template <typename T>
void processValue(T value) {
  // value.doSomething();  // Not all types have this method
  cout << "Value: " << value << endl;
}
```
Implemented processValue() tests
```cpp
  // Bug 3: This will cause compilation error
  processValue(42);  // int doesn't have doSomething()
  processValue(2.41);
  processValue(string("Hello World"));
```
New Output:
```output
./problem3-2
Result: 15
Final value: 15
Value: 42
Value: 2.41
Value: Hello World
```



