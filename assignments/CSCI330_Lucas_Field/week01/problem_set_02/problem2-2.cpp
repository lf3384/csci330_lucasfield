#include <cstdio>

// Use your functions from Problem 2.1 here
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { 
return a - b;
}
int multiply(int a, int b) { 
return a * b;
}
void divide(int a, int b) {
if (b == 0) {
	printf("Error! Divide by Zero is not possible!\n");
}
else {
	printf("%d / %d = %d\n", a, b, a / b);
}

}

int main() {
    int num1, num2;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\nCalculator Results for %d and %d:\n", num1, num2);
    
    // Perform all operations
    printf("Addition: %d + %d = %d\n", num1, num2, add(num1, num2));
    printf("Subtraction: %d - %d = %d\n", num1, num2, subtract(num1, num2));
    printf("Multiplication: %d * %d = %d\n", num1, num2, multiply(num1, num2));
    printf("Division: ");
    divide(num1, num2);
    
    return 0;
}

