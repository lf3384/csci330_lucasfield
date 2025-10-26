1. Problem Set 1-1
Starter Code:
```cpp
#include <iostream>

int main() {
    std::cout << "Enter numeric grade (0-100): ";
    int grade;
    std::cin >> grade;

    // TODO: Validate input
    // TODO: Convert to letter grade using switch
    // TODO: Print result

    return 0;
}
```
Implemented Code:
```cpp
#include <iostream>
// TODO: Convert to letter grade using switch
char convertLetterGrade(int grade) {
  switch (grade / 10) {
    case 10:
    case 9:
      return 'A';
    case 8:
      return 'B';
    case 7:
      return 'C';
    case 6:
      return 'D';
    default:
      return 'F';
  }
}
int main() {
  std::cout << "Enter numeric grade (0-100): ";
  int grade;
  std::cin >> grade;

  // TODO: Validate input
  if (grade < 0 || grade > 100) {
    std::cout << "Error! Grade must be between 0-100." << std::endl;
  }
  // TODO: Print result
  std::cout << convertLetterGrade(grade) << std::endl;

  return 0;
}
```
```output
Output:
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
8/problem_set01$ ./problem1-1
Enter numeric grade (0-100): 98
A
```
2. Problem 1-2
Starter Code
```cpp
#include <iostream>

int main() {
    int size;
    char mode;

    std::cout << "Enter pattern size (1-10): ";
    std::cin >> size;

    std::cout << "Show all rows (a) or odd rows only (o)? ";
    std::cin >> mode;

    // TODO: Validate inputs
    // TODO: Generate pattern with nested loops
    // TODO: Use continue for odd-only mode

    return 0;
}
```
Implemented:
```cpp
  if (size < 1 || size > 10) {
    std::cout << "Invalid size. Must be 1-10." << std::endl;
    return 1;
  }

  if (mode != 'a' && mode != 'o') {
    std::cout << "Invalid mode. Use 'a' or 'o'." << std::endl;
    return 1;
  }

  return 0;

    for (int i = 1; i <= size; ++i) {
    if (mode == 'o' && i % 2 == 0) {
      continue;
    }
    for (int j = 1; j <= i; ++j) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  ```
  Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
8/problem_set01$ ./problem1-2
Enter pattern size (1-10): 4
Show all rows (a) or odd rows only (o)? o
*
***
```
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
8/problem_set01$ ./problem1-2
Enter pattern size (1-10): 3
Show all rows (a) or odd rows only (o)? a
*
**
***
```
3. Problem 1-3
Starter Code:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<double> temperatures = {68.5, 72.1, 69.8, 74.2, 71.5, 73.0, 70.2};

    // TODO: Display all temperatures
    // TODO: Calculate average
    // TODO: Count above average
    // TODO: Add 2.0 to all temperatures
    // TODO: Display modified temperatures

    return 0;
}
```
Implemented:
```cpp

  // TODO: Display all temperatures
  for (int i; i < temperatures.size(); ++i) {
    std::cout << temperatures[i] << " ";
  }
  // TODO: Calculate average
  double sum = 0.0;
  for (double temp : temperatures) {
    sum += temp;
  }
  double average = sum / temperatures.size();
  std::cout << std::endl << "Average Temps: " << average << std::endl;

  // TODO: Count above average
  int above_count = 0;
  for (double temp : temperatures) {
    if (temp > average) {
      above_count++;
    }
  }
  std::cout << "Temps above the average: " << above_count << std::endl;

  // TODO: Add 2.0 to all temperatures
  std::cout << "Adding 2 to every temperature: " << std::endl;
  for (double& temp : temperatures) {
    temp += 2.0;
  }
  // TODO: Display modified temperatures
  for (double temp : temperatures) {
    std::cout << temp << " ";
  }
  ```
