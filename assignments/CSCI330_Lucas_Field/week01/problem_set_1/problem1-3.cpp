#include <cstdio>

void analyze_number(int num) {
    printf("Analyzing %d: ", num);
    
    // Your if-else logic here
    if (num > 0) {
	    printf("%d is positive.\n", num);
    }
    else if (num < 0) {
	    printf("%d is negative.\n", num);
    }
    else {
	    printf("%d is zero.\n", num);
    }


    // Determine if positive, negative, or zero
    // Also determine if even or odd (for non-zero numbers)
}

int main() {
    // Test with various numbers
    analyze_number(10);
    analyze_number(-5);
    analyze_number(0);
    analyze_number(7);
    
    return 0;
}
