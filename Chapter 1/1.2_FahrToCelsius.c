#include <stdio.h>

// Print Fahrenheit-Celsius Conversion Table
// for Fahr = 0, 20, 40, ..., 300
int main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; // Lower limit of temperature table
	upper = 300; // Upper limit
	step = 20; // Step size

	printf("Fahrenheit to Celsius Conversion:\n");

	fahr = lower;
	while (fahr <= upper){
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}