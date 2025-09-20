Problem 1-1:
1. Sample Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01/problem_
set_1$ ./problem1-1
Name: Lucas Field
Favorite Language: Java
Learning C++ because: I have taken a C++ class before, but I want to strengthen my understanding, it seems like a good baseline to help me understand other languages.
```

Problem 1-2:
1. Sample Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01/problem_
set_1$ ./problem1-2
25°C = 77°F
0°C = 32°F
100°C = 212°F
```
Problem 1-3:
Compilation Errors:
1. For this, i changed analyzed_number, to int
```
problem1-3.cpp: In function 'void analyze_number(int)':
problem1-3.cpp:7:24: error: ordered comparison of pointer with integer zero ('void (*)(int)' and 'int')
    7 |     if (analyze_number > 0) {
      |         ~~~~~~~~~~~~~~~^~~
problem1-3.cpp:8:20: error: invalid conversion from 'int' to 'const char*' [-fpermissive]
    8 |             printf(num, "is positive.");
      |                    ^~~
      |                    |
      |                    int
In file included from /usr/include/c++/11/cstdio:42,
                 from problem1-3.cpp:1:
/usr/include/stdio.h:356:43: note:   initializing argument 1 of 'int printf(const char*, ...)'
  356 | extern int printf (const char *__restrict __format, ...);
      |                    ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
problem1-3.cpp:10:10: error: expected primary-expression before 'if'
   10 |     else-if (analyze_number < 0) {
      |          ^~
problem1-3.cpp:13:5: error: 'else' without a previous 'if'
   13 |     else {
      |     ^~~~
problem1-3.cpp:14:20: error: invalid conversion from 'int' to 'const char*' [-fpermissive]
   14 |             printf(num, "is zero.");
      |                    ^~~
      |                    |
      |                    int
In file included from /usr/include/c++/11/cstdio:42,
                 from problem1-3.cpp:1:
/usr/include/stdio.h:356:43: note:   initializing argument 1 of 'int printf(const char*, ...)'
  356 | extern int printf (const char *__restrict __format, ...);
```
2. For this error, I removed the hyphenated else-if
```
problem1-3.cpp: In function 'void analyze_number(int)':
problem1-3.cpp:8:20: error: invalid conversion from 'int' to 'const char*' [-fpermissive]
    8 |             printf(num, "is positive.");
      |                    ^~~
      |                    |
      |                    int
In file included from /usr/include/c++/11/cstdio:42,
                 from problem1-3.cpp:1:
/usr/include/stdio.h:356:43: note:   initializing argument 1 of 'int printf(const char*, ...)'
  356 | extern int printf (const char *__restrict __format, ...);
      |                    ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
problem1-3.cpp:10:10: error: expected primary-expression before 'if'
   10 |     else-if (num < 0) {
      |          ^~
problem1-3.cpp:13:5: error: 'else' without a previous 'if'
   13 |     else {
      |     ^~~~
problem1-3.cpp:14:20: error: invalid conversion from 'int' to 'const char*' [-fpermissive]
   14 |             printf(num, "is zero.");
      |                    ^~~
      |                    |
      |                    int
In file included from /usr/include/c++/11/cstdio:42,
                 from problem1-3.cpp:1:
/usr/include/stdio.h:356:43: note:   initializing argument 1 of 'int printf(const char*, ...)'
  356 | extern int printf (const char *__restrict __format, ...);
      |                    ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
```
2. Sample Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01/problem_set_1$ ./problem1-3
Analyzing 10: 10 is positive.Analyzing -5: -5 is negative.Analyzing 0: 0 is zero.Analyzing 7: 7 is positive.student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01/problem_set_1$ vim problem1-3.cpp
```

I didn't like the formatting, so I added a "\n" to the printf statements:

NEW Sample Output:
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01/problem_set_1$ ./problem1-3
```output
Analyzing 10: 10 is positive.
Analyzing -5: -5 is negative.
Analyzing 0: 0 is zero.
Analyzing 7: 7 is positive.
```

Problem 2-1:
1. Sample Output:
```output
Calculator Testing:
15 + 3 = 18
15 - 3 = 12
15 * 3 = 45
15 / 3 = 5

Edge Case Testing:
Error: Cannot divide by zero!
-5 + 8 = 3
```
Problem2-2:
1. Sample Output:
```output

Calculator Results for 15 and 3:
Addition: 15 + 3 = 18
Subtraction: 15 - 3 = 12
Multiplication: 15 * 3 = 45
Division: 15 / 3 = 5
```
```output
Enter two integers: 10 0

Calculator Results for 10 and 0:
Addition: 10 + 0 = 10
Subtraction: 10 - 0 = 10
Multiplication: 10 * 0 = 0
Division: Error! Divide by Zero is not possible!
```
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week01$ ./problem2-2
Enter two integers: -5 2

Calculator Results for -5 and 2:
Addition: -5 + 2 = -3
Subtraction: -5 - 2 = -7
Multiplication: -5 * 2 = -10
Division: -5 / 2 = -2
```