#include <stdio.h>

#define MAXLINE 1000 // Max length of a string

double atof(char s[]);
int getline(char line[]);
int isdigit();
int isspace();

int main(){
	char line[MAXLINE];

	while (getline(line))
		printf("%f\n", atof(line));

	return 0;
}

// getline: Gets an input line from the user and puts it in the array line.
// Returns its length
int getline(char line[]){
	int c; // Input character
	int i; // Length of the input string

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	if (i < MAXLINE)
		line[i] = '\0';

	return i;
}

// atof: Gets a string and converts it to a double
// Returns the double number.
double atof(char s[]){
	double val, power;
	int esign, exp, i, sign;

	for (i = 0;isspace(s[i]);i++); // Skip white spaces if there are any
	sign = (s[i] == '-') ? -1 : 1; // If there is a '-', it's negative
	if (s[i] == '-' || s[i] == '+') // Skip the sign if there is one
		i++;

	for (val = 0.0; isdigit(s[i]);i++) // Assigns numbers in front of the decimal point
		val = 10 * val + (s[i] - '0');
	
	if (s[i] == '.') // Skip the decimal point if there is one
		i++;
	for (power = 1.0; isdigit(s[i]);i++){ // Assigns numbers after the decimal point;
		val = 10 * val + (s[i] - '0');
		power *= 10;
	}

	val = sign * (val / power); // Calculate up to here and put it in val

	if (s[i] == 'E' || s[i] == 'e') // Skip over the scientific notation E if there is one
		i++;
	esign = (s[i] == '-') ? 0 : 1; // If there is a '-', it's negative
	if (s[i] == '-' || s[i] == '+') // Skip the sign if there is one
		i++;
	for (exp = 0; isdigit(s[i]);i++) // Assign the scientific notation power
		exp = 10 * exp + (s[i] - '0');

	
	if (esign) // If the scientific exponent is positive
		while (exp > 0){ // Multiply the number by 10^exp
			val *= 10;
			exp--;
		}
	else // If negative
		while (exp > 0){ // Divide by 10^exp
			val /= 10;
			exp--;
		}

	return val;
}