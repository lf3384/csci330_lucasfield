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