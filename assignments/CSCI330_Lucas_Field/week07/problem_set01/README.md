1. Problem Set 1-1.
Starter Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 5;

    // Question 1: What is the value of result1?
    int result1 = a + b * c;
    cout << "result1: " << result1 << endl;

    // Question 2: What is the value of result2?
    int result2 = (a + b) * c;
    cout << "result2: " << result2 << endl;

    // Question 3: What is the value of result3?
    int result3 = a < b && b > c;
    cout << "result3: " << result3 << endl;

    // Question 4: What is the value of result4?
    bool result4 = a < b || b < c && c > a;
    cout << "result4: " << result4 << endl;

    // Question 5: What are the final values of x and y?
    int x = 5;
    int y = ++x + x++;
    cout << "x: " << x << ", y: " << y << endl;

    return 0;
}
```
My answers:
Result1 = 110
Result2 = 150
Result3 = 1 (True)
Result4 = 1 (True)
x = 7, y = 13
Output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
7$ ./problem1-1
result1: 110
result2: 150
result3: 1
result4: 1
x: 7, y: 13
```
2. Problem 1-2
Starter Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    // Bug 1: Integer division problem
    int total_items = 17;
    int groups = 5;
    double average = total_items / groups;  // Should be 3.4, but gives 3.0
    cout << "Average: " << average << endl;

    // Bug 2: Signed/unsigned comparison
    int signed_value = -1;
    unsigned int unsigned_value = 1;
    if (signed_value < unsigned_value) {
        cout << "This might not print when you expect!" << endl;
    }

    // Bug 3: Loss of precision
    double precise_value = 3.99999;
    int truncated = precise_value;  // We want to round, not truncate
    cout << "Rounded value should be 4, got: " << truncated << endl;

    return 0;
}
Updated code:
```cpp
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  // Bug 1: Integer division problem
  // SOLUTION: Cast one of the ints, so that way the value is not converted to
  // double after the division. Still does int division (17/5=3), then converts,
  // which is why we get 3.0.
  int total_items = 17;
  int groups = 5;
  double average = static_cast<double>(total_items) /
                   groups;  // Should be 3.4, but gives 3.0
  cout << "Average: " << average << endl;

  // Bug 2: Signed/unsigned comparison
  // SOLUTION: Also cast, the unsigned value to an int. When comparing a
  // ngeative signed int to an unsigned int, the value is represented as a large
  // unsigned value, so the if condition won't be true.
  int signed_value = -1;
  unsigned int unsigned_value = 1;
  if (signed_value < static_cast<int>(unsigned_value)) {
    cout << "This might not print when you expect!" << endl;
  }

  // Bug 3: Loss of precision
  // SOLUTION: Use the round() function, in the <cmath> library.
  double precise_value = 3.99999;
  int truncated = round(precise_value);  // We want to round, not truncate
  cout << "Rounded value should be 4, got: " << truncated << endl;

  return 0;
}
```
Output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
7$ ./problem1-2
Average: 3.4
This might not print when you expect!
Rounded value should be 4, got: 4
```
3. Problem 1-3
Starter Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Rewrite these using compound assignment operators
    int score = 100;
    score = score + 50;
    score = score * 2;
    score = score - 25;
    score = score / 3;
    score = score % 10;

    string message = "Hello";
    message = message + " ";
    message = message + "World";
    message = message + "!";

    bool flags = true;
    flags = flags && false;
    flags = flags || true;

    cout << "Final score: " << score << endl;
    cout << "Final message: " << message << endl;
    cout << "Final flags: " << flags << endl;

    return 0;
}
```
Updated Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  // Rewrite these using compound assignment operators
  int score = 100;
  score += 50;
  score *= 2;
  score -= 25;
  score /= 3;
  score %= 10;

  string message = "Hello";
  message += " ";
  message += "World";
  message += "!";

  bool flags = true;
  flags &= false;
  flags |= true;

  cout << "Final score: " << score << endl;
  cout << "Final message: " << message << endl;
  cout << "Final flags: " << flags << endl;

  return 0;
}

```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week0
7$ ./problem1-3
Final score: 1
Final message: Hello World!
Final flags: 1
```