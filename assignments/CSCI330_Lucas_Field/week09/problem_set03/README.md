1. Problem 3-1
Starter Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// TODO: Implement a statistics accumulator function object
class StatisticsAccumulator {
private:
    // TODO: Add member variables for count, sum, sum_squares, min, max

public:
    StatisticsAccumulator() {
        // TODO: Initialize state
    }

    // TODO: Implement function call operator
    void operator()(double value) {
        // TODO: Update statistics with new value
    }

    // TODO: Implement getter methods
    double get_mean() const {
        // TODO: Calculate and return mean
    }

    double get_variance() const {
        // TODO: Calculate and return variance
    }

    double get_std_dev() const {
        // TODO: Calculate and return standard deviation
    }

    double get_min() const { /* TODO */ }
    double get_max() const { /* TODO */ }
    int get_count() const { /* TODO */ }

    void reset() {
        // TODO: Reset all statistics
    }
};

// TODO: Implement a histogram function object
class HistogramBuilder {
private:
    // TODO: Add data structure to store bins and counts

public:
    HistogramBuilder(double min_val, double max_val, int num_bins) {
        // TODO: Initialize histogram bins
    }

    void operator()(double value) {
        // TODO: Add value to appropriate bin
    }

    void print_histogram() const {
        // TODO: Print histogram bars
    }
};

int main() {
    std::vector<double> data = {
        23.5, 45.2, 12.8, 67.1, 34.6, 89.3, 56.7, 78.9,
        43.2, 29.1, 65.4, 87.6, 54.3, 32.8, 76.5
    };

    std::cout << "Processing " << data.size() << " data points:\n";

    // TODO: Use StatisticsAccumulator with std::for_each
    StatisticsAccumulator stats;

    // TODO: Print statistics

    // TODO: Use HistogramBuilder
    HistogramBuilder histogram(0, 100, 10);

    std::cout << "\nHistogram:\n";
    // TODO: Print histogram

    return 0;
}
```
Implemented:
Member Variables
```cpp
private:
    int count;
    double sum;
    double sum_squares;
    double min_val;
    double max_val;
```
Constructor
```cpp
StatisticsAccumulator() {
    count = 0;
    sum = 0.0;
    sum_squares = 0.0;
    min_val = std::numeric_limits<double>::max();
    max_val = std::numeric_limits<double>::lowest();
}
```
Operator
```cpp
void operator()(double value) {
    count++;
    sum += value;
    sum_squares += value * value;
    if (value < min_val) min_val = value;
    if (value > max_val) max_val = value;
}
```
Get Methods
```cpp
double get_mean() const {
    return count > 0 ? sum / count : 0.0;
}

double get_variance() const {
    if (count == 0) return 0.0;
    double mean = get_mean();
    return (sum_squares / count) - (mean * mean);
}

double get_std_dev() const {
    return std::sqrt(get_variance());
}

double get_min() const { return min_val; }
double get_max() const { return max_val; }
int get_count() const { return count; }
```
Reset Methods
```cpp
void reset() {
    count = 0;
    sum = 0.0;
    sum_squares = 0.0;
    min_val = std::numeric_limits<double>::max();
    max_val = std::numeric_limits<double>::lowest();
}
```
Builder Member Variables
```cpp
private:
    double min_val;
    double max_val;
    int num_bins;
    std::vector<int> bins;
    double bin_width;
```
Constructor
```cpp
HistogramBuilder(double min_v, double max_v, int num_b)
    : min_val(min_v), max_val(max_v), num_bins(num_b) {
    bins.resize(num_bins, 0);
    bin_width = (max_val - min_val) / num_bins;
}
```
Operator
```cpp
void operator()(double value) {
    if (value < min_val || value >= max_val) return;

    int bin_index = static_cast<int>((value - min_val) / bin_width);
    if (bin_index >= 0 && bin_index < num_bins) {
        bins[bin_index]++;
    }
}
```
Print
```cpp
void print_histogram() const {
    int max_count = *std::max_element(bins.begin(), bins.end());

    for (int i = 0; i < num_bins; i++) {
        double range_start = min_val + i * bin_width;
        double range_end = range_start + bin_width;

        std::cout << "[" << range_start << "-" << range_end << "): ";

        int bar_length = max_count > 0 ? (bins[i] * 50) / max_count : 0;
        for (int j = 0; j < bar_length; j++) {
            std::cout << "█";
        }
        std::cout << " (" << bins[i] << ")\n";
    }
}
```
Using objects in main
```cpp
StatisticsAccumulator stats;
stats = std::for_each(data.begin(), data.end(), stats);

std::cout << "Statistics:\n";
std::cout << "  Count: " << stats.get_count() << "\n";
std::cout << "  Mean: " << stats.get_mean() << "\n";
std::cout << "  Std Dev: " << stats.get_std_dev() << "\n";
std::cout << "  Variance: " << stats.get_variance() << "\n";
std::cout << "  Min: " << stats.get_min() << "\n";
std::cout << "  Max: " << stats.get_max() << "\n";

HistogramBuilder histogram(0, 100, 10);
std::for_each(data.begin(), data.end(), std::ref(histogram));

std::cout << "\nHistogram:\n";
histogram.print_histogram();
```

Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lu
cas_Field/week09/problem_set03$ ./problem3-1
Processing 15 data points:

Statistics:
  Count: 15
  Mean: 53.1333
  Std Dev: 23.1899
  Variance: 537.772
  Min: 12.8
  Max: 89.3

Histogram:
[0-10):  (0)
[10-20): █████████████████████████ (1)
[20-30): ██████████████████████████████████████████████████ (2)
[30-40): ██████████████████████████████████████████████████ (2)
[40-50): ██████████████████████████████████████████████████ (2)
[50-60): ██████████████████████████████████████████████████ (2)
[60-70): ██████████████████████████████████████████████████ (2)
[70-80): ██████████████████████████████████████████████████ (2)
[80-90): ██████████████████████████████████████████████████ (2)
[90-100):  (0)
```

2. Problem 3-2
Starter Code:
```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <map>

// Function pointer type for simple transformations
typedef double (*SimpleTransform)(double);

// TODO: Implement some simple transform functions
double square(double x) { /* TODO */ }
double cube(double x) { /* TODO */ }
double negate(double x) { /* TODO */ }

// TODO: Implement a pipeline stage function object
class ScaleAndOffset {
private:
    double scale, offset;

public:
    ScaleAndOffset(double s, double o) : scale(s), offset(o) {}
    double operator()(double x) const { /* TODO */ }
};

class DataPipeline {
private:
    std::vector<std::function<double(double)>> stages;
    std::string pipeline_name;

public:
    DataPipeline(const std::string& name) : pipeline_name(name) {}

    // TODO: Add method to register processing stages
    void add_stage(std::function<double(double)> stage) {
        // TODO: Add stage to pipeline
    }

    // TODO: Process a single value through all stages
    double process(double input) {
        // TODO: Apply all stages in sequence
    }

    // TODO: Process a vector of values
    std::vector<double> process_batch(const std::vector<double>& inputs) {
        // TODO: Process all inputs and return results
    }

    void print_info() const {
        std::cout << "Pipeline '" << pipeline_name
                  << "' has " << stages.size() << " stages\n";
    }
};

int main() {
    std::vector<double> test_data = {1.0, 2.0, 3.0, 4.0, 5.0};

    // TODO: Create pipeline and add different types of stages
    DataPipeline pipeline("MathProcessor");

    // Add function pointer stage
    pipeline.add_stage(square);

    // Add lambda stage
    double multiplier = 0.5;
    pipeline.add_stage([multiplier](double x) { return x * multiplier; });

    // Add function object stage
    pipeline.add_stage(ScaleAndOffset(2.0, 10.0));

    // Add generic lambda stage
    pipeline.add_stage([](auto x) { return x < 0 ? 0 : x; }); // ReLU-like

    pipeline.print_info();

    std::cout << "\nProcessing data through pipeline:\n";
    // TODO: Process test data and show results

    std::cout << "\nOriginal -> Processed:\n";
    for(double value : test_data) {
        double result = pipeline.process(value);
        std::cout << value << " -> " << result << "\n";
    }

    return 0;
}
```
Implemented:
Transform Functions
```cpp
double square(double x) {
    return x * x;
}

double cube(double x) {
    return x * x * x;
}

double negate(double x) {
    return -x;
}
```
Scale operator
```cpp
double operator()(double x) const {
    return x * scale + offset;
}
```
add_stage()
```cpp
void add_stage(std::function<double(double)> stage) {
    stages.push_back(stage);
}
```
process method
```cpp
double process(double input) {
    double result = input;
    for (const auto& stage : stages) {
        result = stage(result);
    }
    return result;
}
```
process_batch()
```cpp
std::vector<double> process_batch(const std::vector<double>& inputs) {
    std::vector<double> results;
    for (double input : inputs) {
        results.push_back(process(input));
    }
    return results;
}
```
Test data
```cpp
std::cout << "\nProcessing data through pipeline:\n";
std::vector<double> results = pipeline.process_batch(test_data);

std::cout << "\nOriginal -> Processed:\n";
for(double value : test_data) {
    double result = pipeline.process(value);
    std::cout << value << " -> " << result << "\n";
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lu
cas_Field/week09/problem_set03$ ./problem3-2
Pipeline 'MathProcessor' has 4 stages

Processing data through pipeline:

Original -> Processed:
1 -> 11
2 -> 14
3 -> 19
4 -> 26
5 -> 35
```