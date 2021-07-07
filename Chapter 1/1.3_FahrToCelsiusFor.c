#include <stdio.h>

// Print Fahrenheit-Celsius Conversion Table
// for Fahr = 0, 20, 40, ..., 300
// using a for loop
int main(){
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}