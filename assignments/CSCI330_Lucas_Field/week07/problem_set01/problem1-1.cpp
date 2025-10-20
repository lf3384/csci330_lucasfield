#include <iostream>
using namespace std;

int main() {
  int a = 10, b = 20, c = 5;

  // Question 1: What is the value of result1?
  int result1 = a + b * c;
  cout << "result1: " << result1 << endl;
  /// The value of result will be 110

  // Question 2: What is the value of result2?
  int result2 = (a + b) * c;
  cout << "result2: " << result2 << endl;
  // Result will be 150

  // Question 3: What is the value of result3?
  int result3 = a < b && b > c;
  cout << "result3: " << result3 << endl;
  // Result will be 1. (True)

  // Question 4: What is the value of result4?
  bool result4 = a < b || b < c && c > a;
  cout << "result4: " << result4 << endl;
  // Result will be 1. (True)

  // Question 5: What are the final values of x and y?
  int x = 5;
  int y = ++x + x++;
  cout << "x: " << x << ", y: " << y << endl;
  // x=7, y=13

  return 0;
}