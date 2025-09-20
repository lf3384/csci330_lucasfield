#include <cstdio>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

void divide(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n");
    } else {
        printf("%d / %d = %d\n", a, b, a / b);
    }
}

int main() {
    // Test all operations
    int x = 15, y = 3;
    
    printf("Calculator Testing:\n");
    printf("%d + %d = %d\n", x, y, add(x, y));
    printf("%d - %d = %d\n", x, y, subtract(x, y));
    printf("%d * %d = %d\n", x, y, multiply(x, y));
    divide(x, y);
    
    // Test edge cases
    printf("\nEdge Case Testing:\n");
    divide(10, 0);  // Should show error
    printf("%d + %d = %d\n", -5, 8, add(-5, 8));
    
    return 0;
}
