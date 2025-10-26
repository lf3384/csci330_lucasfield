#include <iostream>
#include <vector>

int main() {
  std::vector<double> temperatures = {68.5, 72.1, 69.8, 74.2, 71.5, 73.0, 70.2};

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

  return 0;
}