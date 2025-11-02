#include <iostream>
#include <vector>

// Comparison function type - returns true if first should come before second
typedef bool (*Comparator)(int a, int b);

// TODO: Implement comparison functions
bool ascending(int a, int b) { return a < b; }

bool descending(int a, int b) { return a > b; }

// TODO: Implement simple bubble sort with custom comparator
void sort_with_comparator(std::vector<int>& data, Comparator comp) {
  int n = data.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (comp(data[j + 1], data[j])) {
        // Swap
        int temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

void print_vector(const std::vector<int>& data) {
  for (int n : data) {
    std::cout << n << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

  std::cout << "Original: ";
  print_vector(numbers);

  // TODO: Sort ascending
  sort_with_comparator(numbers, ascending);
  std::cout << "Ascending: ";
  print_vector(numbers);

  // TODO: Sort descending
  sort_with_comparator(numbers, descending);
  std::cout << "Descending: ";
  print_vector(numbers);

  // TODO: Show results

  return 0;
}