#include <functional>
#include <iostream>
#include <string>
#include <vector>

class DataProcessor {
 private:
  std::string processor_name;
  int processing_count;
  std::vector<int> results;

 public:
  DataProcessor(const std::string& name)
      : processor_name(name), processing_count(0) {}

  auto create_filter(int threshold) {
    return [this, threshold, name = processor_name](int value) {
      processing_count++;
      if (value > threshold) {
        std::cout << "  [" << name << "] Filtering: " << value << " > "
                  << threshold << " ✓\n";
        return true;
      }
      return false;
    };
  }

  auto create_transformer(int multiplier, int offset) {
    return [m = multiplier, o = offset](int value) { return value * m + o; };
  }

  auto create_accumulator() {
    return [sum = 0](int value) mutable {
      sum += value;
      return sum;
    };
  }

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

  auto create_problematic_lambda() {
    int local_var = 42;
    return [&local_var]() { return local_var; };
  }

  auto create_safe_lambda() {
    int local_var = 42;
    return [local_var]() { return local_var; };
  }
};

int main() {
  DataProcessor processor("NumberCruncher");
  std::vector<int> test_data = {5, 15, 8, 22, 3, 18, 12, 7};

  processor.process_data(test_data);

  std::cout << "\nTesting lambda lifetime:\n";

  auto problematic = processor.create_problematic_lambda();
  auto safe = processor.create_safe_lambda();

  std::cout << "Problematic lambda (dangling reference): " << problematic()
            << " (undefined behavior!)\n";
  std::cout << "Safe lambda (captured by value): " << safe() << "\n";

  return 0;
}