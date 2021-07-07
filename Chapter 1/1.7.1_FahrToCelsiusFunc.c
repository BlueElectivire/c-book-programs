#include <stdio.h>

#define UPPER 300 // Upper limit of table
#define LOWER 0 // Lower limit of table
#define STEP 20 // Table step

float fahrToCelsius(int fahr);

// Print Fahrenheit-Celsius Conversion Table
// for Fahr = 0, 20, 40, ..., 300
// using functions
int main(){
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahrToCelsius(fahr));
	
	return 0;
}

// Convert from Fahrenheit to Celsius
float fahrToCelsius(int fahr){
	return (5.0 / 9.0) * (fahr -32);
}