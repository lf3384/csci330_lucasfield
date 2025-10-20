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