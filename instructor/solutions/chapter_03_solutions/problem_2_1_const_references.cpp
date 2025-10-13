// Problem 2.1: Const Reference Parameters
// Demonstrates using const references for read-only function parameters

#include <cstdio>

struct Student {
    char name[50];
    int age;
    double gpa;
};

// Function that takes a const Student reference and prints student information
void display_student(const Student& student) {
    printf("Student: %s, Age: %d, GPA: %.2f\n", 
           student.name, student.age, student.gpa);
}

// Function that takes a const Student reference and returns true if GPA >= 3.5
bool is_honor_student(const Student& student) {
    return student.gpa >= 3.5;
}

int main() {
    Student alice = {"Alice Johnson", 20, 3.8};
    
    // Call both functions with alice
    display_student(alice);
    
    if (is_honor_student(alice)) {
        printf("Alice is an honor student: Yes\n");
    } else {
        printf("Alice is an honor student: No\n");
    }
    
    // Test with another student
    Student charlie = {"Charlie Brown", 19, 3.2};
    display_student(charlie);
    
    if (is_honor_student(charlie)) {
        printf("Charlie is an honor student: Yes\n");
    } else {
        printf("Charlie is an honor student: No\n");
    }
    
    return 0;
}