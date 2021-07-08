#include <stdio.h>

#define MAXLINE 1000 // The maximum length of a string
#define OFFSET 32 // The offset between uppercase and lowercase letters

int getline(char s[]);
void lower(char s[]);

// main: Receives an input line from the user and prints it in lowercase, until line is EOF
int main(){
	char line[MAXLINE];

	while (getline(line) != 0){
		lower(line);
		printf("%s", line);
	}

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

// lower: Gets a char array and replaces all the uppercase letters with lowercase letters
void lower(char s[]){
	int i;

	for (i = 0;s[i] != '\0'; i++)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + OFFSET : s[i];
}