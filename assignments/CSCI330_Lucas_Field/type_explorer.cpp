#include <cstdio>
#include <climits>

int main () {
	int varInt = 5;
	double varDouble = 11.434;
	char varChar = 'L';
	bool varBool = true;

//Part A: Type Discovery and Analysis
printf("Fundamental types in C++: \n");
printf("Int: %d ", varInt);
printf("(Size: %zu bytes. Range: %d to %d)\n", sizeof(int), INT_MIN, INT_MAX); 

printf("Double: %.3f ", varDouble);
printf("(Size: %zu bytes. Precision: 15-17 digits.)\n", sizeof(double));

printf("Char: %c ", varChar);
printf("(Size: %zu bytes. ASCII: %d)\n", sizeof(varChar), (int)varChar);

printf("Boolean: %s ", varBool ? "true" : "false");
printf("(Size: %zu bytes. Values: 0 or 1.)\n", sizeof(bool));

printf("\nType Conversions in C++:\n");

int intConversion = 11;
double intToDouble = intConversion;
printf("Int = %d --> Double = %.8f (no loss)\n", intConversion, intToDouble);

double doubleConversion = 11.45634;
int doubleToInt = doubleConversion;
printf("Double = %.5f --> Int = %d (loss in precision)\n", doubleConversion, doubleToInt); 

char charConversion = 'Z';
int charToInt = (int)charConversion;
printf("Char = '%c' --> Int = %d\n", charConversion, charToInt);

printf("\nExplicit vs. Implicit Conversions\n");

int implicitInt = 8;
double implicitDouble = 2.978;
double implicitConvert = implicitInt + implicitDouble;
printf("Implicit Results: %d + %.2f = %.2f (int to double)\n", implicitInt, implicitDouble, implicitConvert);

double explicitDouble = 3.142;
int explicitInt = (int)explicitDouble;
printf("Explicit Results: %.3f -> %d\n", explicitDouble, explicitInt);


//Part B: Mulit-Unit Converter
printf("\nUnit Conversions!\n");
int celsius = 40;
double farenheit = celsius * 9.0 / 5.0 + 32.0;
double kelvin = celsius + 273.15;

printf("Celsius: %d --> Farenheit: %.1f --> Kelvin: %.2f\n", celsius, farenheit, kelvin);

int feet = 6;
double meters = feet * 0.3048;
double inches = feet * 12.0;

printf("Feet:  %d --> Meters: %.4f -->  Inches: %.1f\n", feet, meters, inches);

int miles = 420;
double kilometers = miles * 1.60934;
meters = kilometers * 1000;

printf("Miles: %d --> Kilometers: %.4f --> Meters: %.2f\n", miles, kilometers, meters);

return 0;
}
