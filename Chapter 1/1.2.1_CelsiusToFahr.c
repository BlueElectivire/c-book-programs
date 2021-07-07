#include <stdio.h>

// Print Celsius to Fahrenheit conversion table
// For Celsius = 0, 20, 40, ..., 300
int main(){
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius to Fahrenheit Conversion:\n");

	celsius = lower;
	while (celsius <= upper){
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}