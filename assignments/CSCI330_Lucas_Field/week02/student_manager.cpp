#include <cstdio>
#include <cstring>

struct Student {
    char name[30];           
    int student_id;          
    int grades[10];          
    int grade_count;         
};

double calculate_average(int* grades, int count) {
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += *(grades + i);
    }
    return (double) sum / count;
}

int main() {
    Student students[3];
   
    strcpy(students[0].name, "Lucas Field");
    students[0].grades[0] = 85; 
    students[0].grades[1] = 92; 
    students[0].grades[2] = 78;
    students[0].grades[3] = 96; 
    students[0].grades[4] = 88;
    students[0].grade_count = 5;
    
    strcpy(students[1].name, "John Day");
    students[1].grades[0] = 90; 
    students[1].grades[1] = 87; 
    students[1].grades[2] = 93;
    students[1].grade_count = 3;
    
    strcpy(students[2].name, "Tyler Smith");
    students[2].grades[0] = 75; 
    students[2].grades[1] = 85; 
    students[2].grades[2] = 80;
    students[2].grade_count = 3;
    
    double total_sum = 0.0;
    int total_grades = 0;
    
    for(int i = 0; i < 3; i++) {
        Student* s = students + i;
        double avg = calculate_average(s->grades, s->grade_count);
        printf("%s: %.1f\n", s->name, avg);
        
        for(int j = 0; j < s->grade_count; j++) {
            total_sum += *(s->grades + j);
            total_grades++;
        }
    }
    
    double class_avg = total_sum / total_grades;
    printf("Class Average: %.1f\n", class_avg);
    
    return 0;
}
