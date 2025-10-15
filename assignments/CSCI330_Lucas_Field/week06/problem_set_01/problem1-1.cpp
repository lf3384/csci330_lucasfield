#include <iostream>
using namespace std;

// Your template function here
template <typename T>
T absolute_value(T value) {
  if (value < 0) {
    return -value;
  }
  return value;
}

int main() {
  cout << "absolute_value(-5) = " << absolute_value(-5) << endl;
  cout << "absolute_value(-3.14) = " << absolute_value(-3.14) << endl;
  cout << "absolute_value(42) = " << absolute_value(42) << endl;
  return 0;
}