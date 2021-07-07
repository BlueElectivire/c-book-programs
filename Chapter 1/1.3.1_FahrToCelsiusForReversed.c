#include <stdio.h>

// Print Fahrenheit-Celsius Conversion Table
// for Fahr = 300, 280, 260, ..., 0
// using a for loop
int main(){
	int fahr;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}