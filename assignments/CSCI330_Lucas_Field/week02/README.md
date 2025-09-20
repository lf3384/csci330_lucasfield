1. First test, just making sure code works.
'''output
type_explorer.cpp:1:10: fatal error: ctsdio: No such file or directory
    1 | #include <ctsdio>
      |          ^~~~~~~~
compilation terminated.
```
2. Ran a second test after filling out rest of types, and testing first sizeof() call.
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ ./type_explorer
Fundamental types in C++:
Int: 5Size: 4 bytes
Double: 11.434
Char: L
Boolean: 1Long: 1234567890
Float: 22.4356
```
3. Ran another test.
```output
Fundamental types in C++:
Int: 5 (Size: 4 bytes. Range: -2147483648 to 2147483647)
Double: 11.434 (Size: 8 bytes. Precision: 15-17 digits.)
Char: L (Size: 1 bytes. ASCII: 76
)Boolean: true (Size: 1 bytes. Values: 0 or 1.)
```

4. Added Implicit vs Explicit
First run made a mistake with putting line breaks in wrong area.
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ g++ -o type_explorer type_explorer.cpp
type_explorer.cpp:23:8: error: stray '\' in program
   23 | printf(\n"Type Conversions in C++:\n");
      |        ^
type_explorer.cpp: In function 'int main()':
type_explorer.cpp:23:9: error: 'n' was not declared in this scope
   23 | printf(\n"Type Conversions in C++:\n");
      |
```

5. Fixed line break issue, cleaned up a little bit.
```output
Fundamental types in C++:
Int: 5 (Size: 4 bytes. Range: -2147483648 to 2147483647)
Double: 11.434 (Size: 8 bytes. Precision: 15-17 digits.)
Char: L (Size: 1 bytes. ASCII: 76)
Boolean: true (Size: 1 bytes. Values: 0 or 1.)

Type Conversions in C++:
Int = 11 --> Double = 11.00000000 (no loss)
Double = 11.45634 --> Int = 11 (loss in precision)
Char = 'Z' --> Int = 90

Explicit vs. Implicit Conversions
Implicit Results: 8 + 2.98 = 10.98 (int to double)
Explicit Results: 3.142 -> 3
```

Part 2: Unit Converter Examples
1. First test, several mistakes, declared variable meters twice, division wrong way,
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ g++ -o type_explorer type_explorer.cpp
type_explorer.cpp:52:34: error: stray '\' in program
   52 | double farenheit = celsius * 9.0 \ 5.0 + 32.0;
      |                                  ^
type_explorer.cpp: In function 'int main()':
type_explorer.cpp:52:36: error: expected ',' or ';' before numeric constant
   52 | double farenheit = celsius * 9.0 \ 5.0 + 32.0;
      |                                    ^~~
type_explorer.cpp:63:11: error: expected initializer before numeric constant
   63 | int miles 420;
      |           ^~~
type_explorer.cpp:64:21: error: 'miles' was not declared in this scope
   64 | double kilometers = miles * 1.60934;
      |                     ^~~~~
type_explorer.cpp:65:8: error: redeclaration of 'double meters'
   65 | double meters = kilometers * 1000;
      |        ^~~~~~
type_explorer.cpp:58:8: note: 'double meters' previously declared here
   58 | double meters = feet * 0.3048;
      |
```
Fixed those mistakes
New output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ ./type_explorer
Fundamental types in C++:
Int: 5 (Size: 4 bytes. Range: -2147483648 to 2147483647)
Double: 11.434 (Size: 8 bytes. Precision: 15-17 digits.)
Char: L (Size: 1 bytes. ASCII: 76)
Boolean: true (Size: 1 bytes. Values: 0 or 1.)

Type Conversions in C++:
Int = 11 --> Double = 11.00000000 (no loss)
Double = 11.45634 --> Int = 11 (loss in precision)
Char = 'Z' --> Int = 90

Explicit vs. Implicit Conversions
Implicit Results: 8 + 2.98 = 10.98 (int to double)
Explicit Results: 3.142 -> 3
```
This compiled and ran, but there was an issue. I put unit conversion after return 0; so unit conversion section was not executed. Fixed that
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ ./type_explorer
Fundamental types in C++:
Int: 5 (Size: 4 bytes. Range: -2147483648 to 2147483647)
Double: 11.434 (Size: 8 bytes. Precision: 15-17 digits.)
Char: L (Size: 1 bytes. ASCII: 76)
Boolean: true (Size: 1 bytes. Values: 0 or 1.)

Type Conversions in C++:
Int = 11 --> Double = 11.00000000 (no loss)
Double = 11.45634 --> Int = 11 (loss in precision)
Char = 'Z' --> Int = 90

Explicit vs. Implicit Conversions
Implicit Results: 8 + 2.98 = 10.98 (int to double)
Explicit Results: 3.142 -> 3
Celsius: 40 --> Farenheit: 104.0 --> Kelvin: 313.15
Feet:  6 --> Meters: 1.82880 -->  Inches: 72.000
Miles: 420 --> Kilometers: 675.922800 --> Meters: 675922.80
```
Everything worked, fixed some formatting, (too precise on some outputs.)
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field$ ./type_explorer
Fundamental types in C++:
Int: 5 (Size: 4 bytes. Range: -2147483648 to 2147483647)
Double: 11.434 (Size: 8 bytes. Precision: 15-17 digits.)
Char: L (Size: 1 bytes. ASCII: 76)
Boolean: true (Size: 1 bytes. Values: 0 or 1.)

Type Conversions in C++:
Int = 11 --> Double = 11.00000000 (no loss)
Double = 11.45634 --> Int = 11 (loss in precision)
Char = 'Z' --> Int = 90

Explicit vs. Implicit Conversions
Implicit Results: 8 + 2.98 = 10.98 (int to double)
Explicit Results: 3.142 -> 3

 Unit Conversions!
Celsius: 40 --> Farenheit: 104.0 --> Kelvin: 313.15
Feet:  6 --> Meters: 1.8288 -->  Inches: 72.0
Miles: 420 --> Kilometers: 675.9228 --> Meters: 675922.80
```
Part 2: Studnet Manager program
1. First test to see if students in array get displayed using for loop. Scope issues:
```output
student_manager.cpp: In function 'int main()':
student_manager.cpp:6:1: error: 'Student' was not declared in this scope
    6 | Student students[NUM_STUDENTS];
      | ^~~~~~~
student_manager.cpp:8:1: error: 'students' was not declared in this scope
    8 | students[0] = {"Lucas Field", 1010, {100, 90, 95, 87, 89}};
      | ^~~~~~~~
student_manager.cpp:15:9: error: 'display_student' was not declared in this scope
   15 |         display_student(students[i]);
      |         ^~~~~~~~~~~~~~~
```
2. Issues with scope again
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week02$ g++ -o student_manager student_manager.cpp
student_manager.cpp: In function 'int main()':
student_manager.cpp:14:9: error: expected initializer before 'students'
   14 | Student students[3];
      |         ^~~~~~~~
student_manager.cpp:15:8: error: 'students' was not declared in this scope; did you mean 'Student'?
   15 | strcpy(students[0].name, "Lucas Field");
      |        ^~~~~~~~
      |        Student
```
I can see names work:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week02$ ./student_manager
Lucas Field
John Day
Tyler Smith
```