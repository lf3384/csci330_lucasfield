#include <iostream>
using namespace std;

template <typename T>
class Calculator {
 private:
  T value;

 public:
  Calculator(T initial) : value(initial) {}

  void add(T amount) { value += amount; }

  void print() { cout << "Result: " << value << endl; }

  // Bug 1: Missing template syntax in method definition outside class
  T getValue();
};
template <typename T>
T Calculator<T>::getValue() {  // This line has errors
  return value;
}

// Bug 2: Trying to use undefined operation
template <typename T>
void processValue(T value) {
  // value.doSomething();  // Not all types have this method
  cout << "Value: " << value << endl;
}

int main() {
  Calculator<int> calc(10);
  calc.add(5);
  calc.print();
  cout << "Final value: " << calc.getValue() << endl;

  // Bug 3: This will cause compilation error
  processValue(42);  // int doesn't have doSomething()
  processValue(2.41);
  processValue(string("Hello World"));

  return 0;
}