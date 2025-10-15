1. Problem 2-1
Starter Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Pair {
private:
    T first_value;
    T second_value;
public:
    // Implement constructor and methods here
};

int main() {
    Pair<int> numbers(10, 20);
    cout << "First: " << numbers.first() << ", Second: " << numbers.second() << endl;

    numbers.swap();
    cout << "After swap - First: " << numbers.first() << ", Second: " << numbers.second() << endl;

    Pair<string> words("hello", "world");
    cout << words.first() << " " << words.second() << endl;

    return 0;
}
```
Implemented:
```cpp
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
```
Called word swap:
```cpp
words.swap();
  cout << "After Swap: " << words.first() << " " << words.second() << endl;
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
6/problem_set_02$ ./problem2-1
First: 10, Second: 20
After swap - First: 20, Second: 10
hello world
After Swap: world hello
```
2. Problem 2-2
Starter Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class SimpleArray {
private:
    T* data;
    size_t array_size;
public:
    SimpleArray(size_t size) : array_size(size) {
        data = new T[size];
    }

    ~SimpleArray() {
        delete[] data;
    }

    // Implement the rest of the methods
};

int main() {
    SimpleArray<int> numbers(5);
    numbers.set(0, 100);
    numbers.set(1, 200);
    cout << "numbers[0] = " << numbers.get(0) << endl;
    cout << "Size: " << numbers.size() << endl;

    SimpleArray<string> words(3);
    words.set(0, "apple");
    words.set(1, "banana");
    cout << "words[0] = " << words.get(0) << endl;

    return 0;
}
```
Implemented:
```cpp
  T get(size_t index) const {
    if (index >= array_size) {
      cout << "Error: Index" << index << " out of bounds." << endl;
      return T{};
    }
    return data[index];
  }

  void set(size_t index, const T& value) {
    if (index >= array_size) {
      cout << "Error: Index" << index << " out of bounds" << endl;
      return;
    }
    data[index] = value;
  }

  size_t size() const { return array_size; }
```
Similar methods, but as you can see, set method assigns data[index] to value, rather than just returning data[index].

Output:
```output
./problem2-2
numbers[0] = 100
Size: 5
Error: Index10 out of bounds.
words[0] = apple
```
