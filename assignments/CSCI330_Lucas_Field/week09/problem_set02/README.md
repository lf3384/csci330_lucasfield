1. Problem 2-1:
Starter Code:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

struct Student {
    std::string name;
    int grade;

    Student(const std::string& n, int g) : name(n), grade(g) {}
};

int main() {
    std::vector<Student> students = {
        {"Alice", 92}, {"Bob", 87}, {"Charlie", 78},
        {"Diana", 95}, {"Eve", 82}, {"Frank", 69}
    };

    std::cout << "All students:\n";
    // TODO: Use std::for_each with lambda to print all students

    std::cout << "\nHonor roll students (grade >= 90):\n";
    // TODO: Use std::copy_if with lambda to find honor roll students

    // TODO: Count students passing (grade >= 70)
    int passing_count = 0; // Use std::count_if

    // TODO: Calculate average grade using std::accumulate and lambda
    double average = 0.0;

    // TODO: Apply curve (+5 points) using std::transform with capture
    int curve_points = 5;

    std::cout << "\nAfter applying " << curve_points << " point curve:\n";
    // TODO: Print curved grades

    std::cout << "\nStatistics:\n";
    std::cout << "Passing students: " << passing_count << "\n";
    std::cout << "Average grade: " << average << "\n";

    return 0;
}
```

Implemented:
```cpp
int main() {
  std::vector<Student> students = {{"Alice", 92}, {"Bob", 87}, {"Charlie", 78},
                                   {"Diana", 95}, {"Eve", 82}, {"Frank", 69}};

  std::cout << "All students:\n";
  // TODO: Use std::for_each with lambda to print all students
  std::for_each(students.begin(), students.end(), [](const Student& s) {
    std::cout << s.name << ": " << s.grade << "\n";
  });

  std::cout << "\nHonor roll students (grade >= 90):\n";
  // TODO: Use std::copy_if with lambda to find honor roll students
  std::vector<Student> honor_roll;
  std::copy_if(students.begin(), students.end(), std::back_inserter(honor_roll),
               [](const Student& s) { return s.grade >= 90; });
  std::for_each(honor_roll.begin(), honor_roll.end(), [](const Student& s) {
    std::cout << s.name << ": " << s.grade << "\n";
  });

  // TODO: Count students passing (grade >= 70)
  int passing_count =
      std::count_if(students.begin(), students.end(),
                    [](const Student& s) { return s.grade >= 70; });

  // TODO: Calculate average grade using std::accumulate and lambda
  int total =
      std::accumulate(students.begin(), students.end(), 0,
                      [](int sum, const Student& s) { return sum + s.grade; });
  double average = static_cast<double>(total) / students.size();

  // TODO: Apply curve (+5 points) using std::transform with capture
  int curve_points = 5;
  std::transform(students.begin(), students.end(), students.begin(),
                 [curve_points](Student s) {
                   s.grade += curve_points;
                   return s;
                 });

  std::cout << "\nAfter applying " << curve_points << " point curve:\n";
  // TODO: Print curved grades
  std::for_each(students.begin(), students.end(), [](const Student& s) {
    std::cout << s.name << ": " << s.grade << "\n";
  });

  std::cout << "\nStatistics:\n";
  std::cout << "Passing students: " << passing_count << "\n";
  std::cout << "Average grade: " << average << "\n";

  return 0;
}
```
Output:
```cpp
student@cpp-dev:~/workspace/assignments/CSCI330_Lu
cas_Field/week09/problem_set02$ ./problem2-1
All students:
Alice: 92
Bob: 87
Charlie: 78
Diana: 95
Eve: 82
Frank: 69

Honor roll students (grade >= 90):
Alice: 92
Diana: 95

After applying 5 point curve:
Alice: 97
Bob: 92
Charlie: 83
Diana: 100
Eve: 87
Frank: 74

Statistics:
Passing students: 5
Average grade: 83.8333
```

2. Problem 2-2:
Starter Code:
```cpp
#include <iostream>
#include <vector>
#include <functional>
#include <string>

class DataProcessor {
private:
    std::string processor_name;
    int processing_count;
    std::vector<int> results;

public:
    DataProcessor(const std::string& name)
        : processor_name(name), processing_count(0) {}

    // TODO: Create a lambda that captures member variables appropriately
    auto create_filter(int threshold) {
        // Return lambda that filters values above threshold
        // Should increment processing_count for each item processed
        // Should capture processor_name by value and processing_count by reference
    }

    // TODO: Create a lambda factory for transformations
    auto create_transformer(int multiplier, int offset) {
        // Return lambda that applies: value * multiplier + offset
        // Use init captures to store multiplier and offset
    }

    // TODO: Create a stateful lambda for accumulation
    auto create_accumulator() {
        // Return lambda that keeps running sum
        // Should store sum in capture and return current total each time
    }

    void process_data(const std::vector<int>& input_data) {
        std::cout << "Processing with " << processor_name << ":\n";

        // TODO: Use the lambdas created above to:
        // 1. Filter data (threshold = 10)
        // 2. Transform filtered data (multiply by 2, add 5)
        // 3. Accumulate results

        std::cout << "Items processed: " << processing_count << "\n";
    }

    // TODO: Create a lambda that demonstrates capture lifetime issues
    auto create_problematic_lambda() {
        int local_var = 42;
        // Return lambda that captures local_var by reference
        // This will demonstrate dangling reference problem
        return [&local_var]() { return local_var; };
    }

    // TODO: Fixed version of the above
    auto create_safe_lambda() {
        int local_var = 42;
        // Return lambda that captures local_var safely
    }
};

int main() {
    DataProcessor processor("NumberCruncher");
    std::vector<int> test_data = {5, 15, 8, 22, 3, 18, 12, 7};

    processor.process_data(test_data);

    // TODO: Demonstrate the problematic vs safe lambda
    std::cout << "\nTesting lambda lifetime:\n";

    return 0;
}
```

Implemented:
create_filter()
```cpp
auto create_filter(int threshold) {
    return [this, threshold, name = processor_name](int value) {
        processing_count++;  // Increment via 'this' (by reference)
        if (value > threshold) {
            std::cout << "  [" << name << "] Filtering: " << value << " > " << threshold << " ✓\n";
            return true;
        }
        return false;
    };
}
```
create_transformer()
```cpp
auto create_transformer(int multiplier, int offset) {
    return [m = multiplier, o = offset](int value) {
        return value * m + o;
    };
}
```
create_acccumulator()
```cpp
auto create_accumulator() {
    return [sum = 0](int value) mutable {
        sum += value;
        return sum;
    };
}
```

process_data()
```cpp
void process_data(const std::vector<int>& input_data) {
    std::cout << "Processing with " << processor_name << ":\n";

    auto filter = create_filter(10);
    auto transformer = create_transformer(2, 5);
    auto accumulator = create_accumulator();

    std::cout << "\nFiltering phase:\n";
    for (int value : input_data) {
        if (filter(value)) {
            int transformed = transformer(value);
            std::cout << "  Transformed " << value << " -> " << transformed << "\n";
            int total = accumulator(transformed);
            std::cout << "  Running total: " << total << "\n";
        }
    }

    std::cout << "\nItems processed: " << processing_count << "\n";
}
```

Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lu
cas_Field/week09/problem_set02$ ./problem2-2
Processing with NumberCruncher:

Filtering phase:
  [NumberCruncher] Filtering: 15 > 10 ✓
  Transformed 15 -> 35
  Running total: 35
  [NumberCruncher] Filtering: 22 > 10 ✓
  Transformed 22 -> 49
  Running total: 84
  [NumberCruncher] Filtering: 18 > 10 ✓
  Transformed 18 -> 41
  Running total: 125
  [NumberCruncher] Filtering: 12 > 10 ✓
  Transformed 12 -> 29
  Running total: 154

Items processed: 8

Testing lambda lifetime:
Problematic lambda (dangling reference): 42 (undefined behavior!)
Safe lambda (captured by value): 42
```
3. Problem 2-3:
Starter Code:
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // TODO: Create a generic lambda for printing with custom format
    auto printer = [](const auto& item, const std::string& prefix = "") {
        // Your implementation here
    };

    // TODO: Create a generic lambda for comparison
    auto less_than = [](const auto& a, const auto& b) {
        // Your implementation here
    };

    // TODO: Create a generic lambda for transformation
    auto doubler = [](auto item) {
        // Your implementation here - should work for numbers and strings
    };

    // Test with integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Original numbers: ";
    std::for_each(numbers.begin(), numbers.end(),
                  [&printer](const auto& n) { printer(n, ""); });
    std::cout << "\n";

    // TODO: Use doubler with transform on numbers

    // Test with strings
    std::vector<std::string> words = {"hello", "world", "cpp", "lambda"};
    std::cout << "Original words: ";
    // TODO: Print words using generic printer

    // TODO: Use doubler with transform on strings (should concatenate with itself)

    // Test comparison with different types
    std::cout << "5 < 10: " << less_than(5, 10) << "\n";
    std::cout << "hello < world: " << less_than(std::string("hello"), std::string("world")) << "\n";

    // TODO: Use generic comparison with std::sort

    return 0;
}
```

Implemented:
Printer
```cpp
auto printer = [](const auto& item, const std::string& prefix = "") {
    std::cout << prefix << item << " ";
};
```
less_than lambda
```cpp
auto less_than = [](const auto& a, const auto& b) {
    return a < b;
};
```
doubler lambda
```cpp
auto doubler = [](auto item) {
    return item + item;
};
```
Transform doubler
```cpp
std::vector<int> doubled_numbers;
std::transform(numbers.begin(), numbers.end(), std::back_inserter(doubled_numbers), doubler);
std::cout << "Doubled numbers: ";
std::for_each(doubled_numbers.begin(), doubled_numbers.end(),
              [&printer](const auto& n) { printer(n, ""); });
std::cout << "\n";
```
Sort
```cpp
std::sort(numbers.begin(), numbers.end(), less_than);
std::cout << "Sorted numbers: ";
std::for_each(numbers.begin(), numbers.end(),
              [&printer](const auto& n) { printer(n, ""); });
std::cout << "\n";

std::sort(words.begin(), words.end(), less_than);
std::cout << "Sorted words: ";
std::for_each(words.begin(), words.end(),
              [&printer](const auto& w) { printer(w, ""); });
std::cout << "\n";
```

Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lu
cas_Field/week09/problem_set02$ ./problem2-3
Original numbers: 1 2 3 4 5
Doubled numbers: 2 4 6 8 10
Original words: hello world cpp lambda
Doubled words: hellohello worldworld cppcpp lambdalambda
5 < 10: 1
hello < world: 1
Sorted numbers: 1 2 3 4 5
Sorted words: cpp hello lambda world
```