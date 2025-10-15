#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pair {
 private:
  T first_value;
  T second_value;

 public:
  // Implement constructor and methods here
  Pair(T first, T second) : first_value(first), second_value(second) {}

  T first() const { return first_value; }

  T second() const { return second_value; }

  void set_first(T value) { first_value = value; }

  void set_second(T value) { second_value = value; }

  void swap() {
    T temp_value = first_value;
    first_value = second_value;
    second_value = temp_value;
  }
};

int main() {
  Pair<int> numbers(10, 20);
  cout << "First: " << numbers.first() << ", Second: " << numbers.second()
       << endl;

  numbers.swap();
  cout << "After swap - First: " << numbers.first()
       << ", Second: " << numbers.second() << endl;

  Pair<string> words("hello", "world");
  cout << words.first() << " " << words.second() << endl;

  words.swap();
  cout << "After Swap: " << words.first() << " " << words.second() << endl;

  return 0;
}