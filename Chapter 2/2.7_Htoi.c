#include <stdio.h>
#include <math.h>

#define HEXPOW pow(16, length - 1 - i) // Value of current power of 16.
#define ISHEXCHAR ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) // Checks if c is in the hex character range.
#define MAX 100 // Max length for a hex string.

enum boolean { FALSE, TRUE}; // Boolean values

int getline(char line[]);
int htoi(char hex[], int length);

// Receive a hex number string and print its decimal form
int main(){
	int length; // Length of line
	char line[MAX]; // The input line

	while ((length = getline(line)) != 0){
		if (length > 0) { // If line is infact hex
			printf("%d\n", htoi(line, length)); // Passing in length - 2 to accomodate for the \n character
		}
		else
			printf("Input is not a hex number.\n");	
	}

	return 0;
}

// getline: Inserts the input into 'line' and returns its length.
// If input is not a hex string returns -1.
int getline(char line[]){
	int c; // Input character
	int i; // Iteration variable, length of line
	int hasPrefix = FALSE; // Boolean - checks if line has the optional 0x prefix
	int isHex = TRUE; // Boolean - checks if the input string is a hex number

	for (i = 0;i < MAX && (c = getchar()) != '\n' && c != EOF; ++i){
		if (i == 0 && c == '0') // First character of optinal prefix
			hasPrefix = TRUE;
		else if (hasPrefix && i == 1) { // Second character of optional prefix
			if (c != 'x' && c != 'X') // If not a prefix after all
				if (!ISHEXCHAR) // Check for illegal characters
					isHex = FALSE;
		}
		else if (!ISHEXCHAR) // Check for illegal characters
			isHex = FALSE;
		
		line[i] = c;
	}
	
	if (isHex)
		return i;
	return -1;
}

// htoi: Gets a hex string and its length and returns it as a decimal number
int htoi(char hex[], int length){
	int dec = 0; // The result of the conversion
	int i; // Iteration variable
	int hasPrefix = FALSE; // Boolean - checks if line has the optional 0x prefix

	// Check for prefix
	if (hex[0] == '0')
		hasPrefix = TRUE;
	if (hasPrefix && hex[1] != 'x' && hex[1] != 'X')
		hasPrefix = FALSE;

	// Convert the number
	for (i = 0;i < length; ++i) {
		if (!(hasPrefix && i <= 1)){ // If current place is not a part of the prefix
			if (hex[i] >= '0' && hex[i] <= '9') // If its a digit
				dec += HEXPOW * (hex[i] - '0');
			else if (hex[i] >= 'A' && hex[i] <= 'F') // If its an uppercase a to f
				dec += HEXPOW * (hex[i] - 'A' + 10);
			else // Only other option is lowercase a to f
				dec += HEXPOW * (hex[i] - 'a' + 10);
		}
	}

	return dec;
}