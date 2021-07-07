#include <stdio.h>

#define MAXLINE 1000 // The maximum length of a string

int getline(char line[]);
void squeeze(char s1[], char s2[]);

// main: Gets two input strings, removes any instance of any character in the second string from the first and prints the first.
int main(){
	char s1[MAXLINE]; // The first string
	char s2[MAXLINE]; // The second string

	while (getline(s1) != 0 && getline(s2) != 0) { // Inputs two strings. If both arent EOF:
		squeeze(s1, s2);
		printf("%s\n", s1);
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

// squeeze: Receives two character arrays, removes any instance of any of the values in s2 (except '\0') from s1
void squeeze(char s1[], char s2[]){
	int i, j; // Iteration variables
	int count; // Counts the amount of good chars

	for (i = 0;i < MAXLINE && s2[i] != '\0'; i++){ // For each character in s2 before '\0'
		count = 0;

		for (j = 0;j < MAXLINE && s1[j] != '\0'; j++) // For each character in s1 before '\0'
			if (s1[j] != s2[i]) // If s1[j] is not the checked character
				s1[count++] = s1[j]; // Put it in the first available spot

		s1[count] = '\0'; // Terminate the string
	}
}