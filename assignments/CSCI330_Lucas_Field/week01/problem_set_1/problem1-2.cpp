#include <cstdio>

// Function to convert Celsius to Fahrenheit
int celsius_to_fahrenheit(int celsius) {
   	return (celsius * 9 / 5) + 32;
}

int main() {
    int temp_celsius = 25;
    int temp_fahrenheit = celsius_to_fahrenheit(temp_celsius);
    
    printf("%d°C = %d°F\n", temp_celsius, temp_fahrenheit);
    
    // Test with multiple values
    printf("%d°C = %d°F\n", 0, celsius_to_fahrenheit(0));
    printf("%d°C = %d°F\n", 100, celsius_to_fahrenheit(100));
    
    return 0;
}
