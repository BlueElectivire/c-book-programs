#include <stdio.h>

#define MAX 1000 // Max length for a string
#define OFFSET 48 // Digit offset in ASCII

void itoa(int, char[]);

int i = 0;

// main: Parses the input number as a string and prints it
int main(){
	int input = -81673;
	char output[MAX];

	itoa(input, output);
	output[i] = '\0';

	printf("%s\n", output);

	return 0;
}

void itoa(int input, char output[]){
	if (input < 0){
		output[i++] = '-';
		input *= -1;
	}
	if (input / 10)
		itoa(input / 10, output);
	output[i++] = input % 10 + OFFSET;
}