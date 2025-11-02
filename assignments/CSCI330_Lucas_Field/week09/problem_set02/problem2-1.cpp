#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Student {
  std::string name;
  int grade;

  Student(const std::string& n, int g) : name(n), grade(g) {}
};

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